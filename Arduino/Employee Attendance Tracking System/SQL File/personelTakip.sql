CREATE TABLE [dbo].[Table]
(
	[Id] INT NOT NULL PRIMARY KEY, 
    [personelId] INT NOT NULL, 
    [personelAd] NVARCHAR(50) NOT NULL, 
    [personelSoyad] NVARCHAR(50) NOT NULL, 
    [tcKimlik] NVARCHAR(11) NOT NULL, 
    [meslek] NVARCHAR(50) NOT NULL, 
    [adres] NVARCHAR(250) NOT NULL, 
    [telefon] NVARCHAR(11) NOT NULL, 
    [rfId] NVARCHAR(50) NOT NULL
)
