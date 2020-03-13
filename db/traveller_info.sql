CREATE TABLE [dbo].[traveller]
(
	[Id] INT NOT NULL PRIMARY KEY, 
    [engine_id] NCHAR(75) NOT NULL, 
    [receiver_id] NCHAR(75) NULL, 
    [sensor_id] NCHAR(75) NULL, 
    [time] TIMESTAMP NULL
)
