# Smart Traffic and Advanced Sytems
 This is Github Submission Repo for Microsoft Open Source Hackathon 2020, Team : Comma
 
Submission Time : 3/23/2020 10:17 PM
Demo Video : https://youtu.be/zZdG1mFc-Fo

We have build a IOT based Traffic notification system using Azure SQL Database. 

## How it works?
- We have used RF Transmitter which will stick in the Car and a RF receiver which will stick to the Street Light Pole with 100 meter distance between each.
- RF Transmitter and Receiver Code can be found in Arduino
- The Receiver sends the Information to the Tower whose in its range and the Python Program (TrafficManager.py) of the Tower done certain calculations and operations such as Insert or Update Database based on condition. 

###### When there is >= 300 vehicles in range of same tower then our python program send the message to the Officer to tell him to clear the traffic. 
###### We have also develop a C++ CLI/CLR Project to display the Tower Info such as Vehicles in its Range, Tower ID & Tower Address.
