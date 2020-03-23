import serial, http
import time
import json
import pyodbc



def sendMessage(msg, number):

    conn = http.client.HTTPSConnection("api.msg91.com")
    headers = {

            'authkey': "101279AndtYYhy56a3c00a",
            'content-type': "application/json"
        }

    array = {
        "sender": "SOCKET",
        "route": "4",
        "country": "91",
        "sender":"TRFMNG",
        "sms": [
            {
                "message": msg,
                "to": [number]
            }
                ]
            }
    enc_json = json.dumps(array)
    
    conn.request("POST", "/api/v2/sendsms?country=91", enc_json, headers)
    res = conn.getresponse()
    data = res.read()
    
    return True




server = 'tonz.database.windows.net'
database = 'traffic'
username = 'tonz'
password = '****'
driver= '{SQL Server}'

cnxn = pyodbc.connect('DRIVER='+driver+';PORT=1433;SERVER='+server+';PORT=1443;DATABASE='+database+';UID='+username+';PWD='+ password)
cursor = cnxn.cursor()


TOWER_ID = 1
v_count = 0

vehicles_list = []
incoming_time = []


ser = serial.Serial('COM3', 9600)

while True:
    b = ser.readline().decode('utf-8')
    b = b.replace("#", '')
    b = b.replace('\r\n', '')
    b = b.split('-')

    engineNumber = b[0]
    plateNumber = b[1]
    receiverId = engineNumber + plateNumber

    print("\n\nData Received")
    print("Receiver ID : ", receiverId)

    if receiverId not in vehicles_list:

        print("New Vehicle")
        vehicles_list.append(receiverId)
        incoming_time.append(time.time())

        insertSql = "INSERT INTO [dbo].[TrafficData]([engineNumber], [plateNumber], [transmitterId], [receiverId], [status_v], [incoming], [outgoing]) VALUES ('{}', '{}', {} , '{}' , 1, CURRENT_TIMESTAMP,NULL);".format(engineNumber, plateNumber, TOWER_ID, receiverId)
        cursor.execute(insertSql)
        cnxn.commit()
        print("Inserted to Azure")
        v_count +=1
    
    else:
        getindex = vehicles_list.index(receiverId)
        incoming_time[getindex] = time.time()
        print("Old Vehicle, Update Time")

        
    ind = 0


    for vehicle in vehicles_list:

        getincomingtime = incoming_time[ind]
        diff = time.time() - getincomingtime

        if(diff >= 300):
            UpdateSQL = "UPDATE dbo.TrafficData SET dbo.TrafficData.status_v=0, dbo.TrafficData.outgoing=CURRENT_TIMESTAMP  WHERE dbo.TrafficData.receiverId='{}';".format(receiverId)
            cursor.execute(UpdateSQL)
            cnxn.commit()

            incoming_time.pop(ind)
            vehicles_list.pop(ind)

            print("Vehicle : " + vehicle + " Out of Range updating Database")

            v_count -=1
            
        ind +=1

    if v_count >= 300:
        getTowerAuthoritySQL = "SELECT phone_no FROM [dbo].[TrafficAuthority] WHERE [dbo].[TrafficAuthority].[transmitterId] = {}".format(TOWER_ID)
        cursor.execute(getTowerAuthoritySQL)
        getTowerAuthority = cursor.fetchall()

        for number in getTowerAuthority:
            print("Sending message to Traffic Officer")
            sendMessage("Need Road " + receiverId + " to be cleared", number[0])
    
    UpdateVehicleSQL = "UPDATE dbo.Towers SET dbo.Towers.vehicleCount={}  WHERE dbo.Towers.transmitterId='{}';".format(v_count, TOWER_ID)
    cursor.execute(UpdateVehicleSQL)
    cnxn.commit()




        
    


