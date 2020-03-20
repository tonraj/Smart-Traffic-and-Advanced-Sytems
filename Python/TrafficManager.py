import serial
import time
import json
import pyodbc


server = 'tonz.database.windows.net'
database = 'traffic'
username = 'tonz'
password = '9893753436Raj'
driver= '{SQL Server}'

cnxn = pyodbc.connect('DRIVER='+driver+';PORT=1433;SERVER='+server+';PORT=1443;DATABASE='+database+';UID='+username+';PWD='+ password)
cursor = cnxn.cursor()

#cursor.execute("INSERT INTO [dbo].[TrafficData]([engineNumber], [plateNumber], [transmitterId], [receiverId], [status_v], [incoming], [outgoing]) VALUES ('daad','NdsasdewColor',1,'dadasdasdsad',0, CURRENT_TIMESTAMP,CURRENT_TIMESTAMP);")
#cnxn.commit()



TOWER_ID = 1


ser = serial.Serial('COM3', 9600)
while True:
    b = ser.readline().decode('utf-8')
    b = b.replace("#", '')
    b = b.replace('\r\n', '')
    b = b.split('-')

    engineNumber = b[0]
    plateNumber = b[1]
    receiverId = engineNumber + plateNumber