CREATE TABLE [dbo].[TrafficData]
(
    id INT IDENTITY PRIMARY KEY,
    engineNumber NVARCHAR(50) NOT NULL,
    plateNumber NVARCHAR(50) NOT NULL,
    transmitterId INT REFERENCES [dbo].[Towers] (transmitterId) ,
    receiverId NVARCHAR(128) NOT NULL,
    status_v INT DEFAULT(1),
    incoming DATETIME DEFAULT(CURRENT_TIMESTAMP),
    outgoing DATETIME NULL
)


CREATE TABLE [dbo].[Towers]
(
    transmitterId INT IDENTITY PRIMARY KEY,
    transmitterAddr NVARCHAR(100) NOT NULL,
    vehicleCount INT DEFAULT(0),
)