USE [master]
GO
/****** Object:  Database [AirPort]    Script Date: 7/14/2021 1:29:52 PM ******/
CREATE DATABASE [AirPort]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'AirPort', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.SQLEXPRESS\MSSQL\DATA\AirPort.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'AirPort_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.SQLEXPRESS\MSSQL\DATA\AirPort_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [AirPort].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [AirPort] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [AirPort] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [AirPort] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [AirPort] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [AirPort] SET ARITHABORT OFF 
GO
ALTER DATABASE [AirPort] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [AirPort] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [AirPort] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [AirPort] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [AirPort] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [AirPort] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [AirPort] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [AirPort] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [AirPort] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [AirPort] SET  DISABLE_BROKER 
GO
ALTER DATABASE [AirPort] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [AirPort] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [AirPort] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [AirPort] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [AirPort] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [AirPort] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [AirPort] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [AirPort] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [AirPort] SET  MULTI_USER 
GO
ALTER DATABASE [AirPort] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [AirPort] SET DB_CHAINING OFF 
GO
ALTER DATABASE [AirPort] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [AirPort] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [AirPort] SET DELAYED_DURABILITY = DISABLED 
GO
USE [AirPort]
GO
/****** Object:  Table [dbo].[Country]    Script Date: 7/14/2021 1:29:52 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Country](
	[CountryId] [int] NOT NULL,
	[Name] [varchar](50) NOT NULL,
	[Time] [varchar](50) NOT NULL,
	[ArrivalDestination] [varchar](50) NOT NULL,
	[Price] [float] NOT NULL,
 CONSTRAINT [PK_Country] PRIMARY KEY CLUSTERED 
(
	[CountryId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Tickets]    Script Date: 7/14/2021 1:29:52 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tickets](
	[Id] [int] NOT NULL,
	[CountryId] [int] NOT NULL,
 CONSTRAINT [PK_Tickets] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (1, N'Italy,Venice', N'19:00', N'Germany,Berlin', 167.8)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (2, N'Italy,Venice', N'10:00', N'Germany,Berlin', 236.94)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (3, N'Italy,Venice', N'09:00', N'Germany,Berlin', 247.08)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (4, N'Italy,Venice', N'07:00', N'Germany,Berlin', 251.69)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (5, N'Italy,Venice', N'10:30', N'France,Paris', 219.43)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (6, N'Italy,Venice', N'07:00', N'France,Paris', 221.27)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (7, N'Italy,Venice', N'06:00', N'France,Paris', 310.7)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (8, N'Italy,Venice', N'12:30', N'France,Paris', 329.14)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (9, N'Italy,Venice', N'09:00', N'England,London', 267.37)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (10, N'Italy,Venice', N'11:00', N'England,London', 271.06)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (11, N'Italy,Venice', N'06:00', N'England,London', 314.39)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (12, N'Italy,Venice', N'07:00', N'England,London', 307.01)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (13, N'Italy,Venice', N'09:00', N'Spain,Barcelona', 293.18)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (14, N'Italy,Venice', N'07:00', N'Spain,Barcelona', 328.22)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (15, N'Italy,Venice', N'06:00', N'Spain,Barcelona', 342.05)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (16, N'Italy,Venice', N'11:00', N'Spain,Barcelona', 342.97)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (17, N'Italy,Venice', N'11:00', N'Turkey,Istanbul', 324.53)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (18, N'Italy,Venice', N'07:00', N'Turkey,Istanbul', 717.28)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (19, N'Italy,Venice', N'06:00', N'Turkey,Istanbul', 638.92)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (20, N'Italy,Venice', N'18:10', N'Turkey,Istanbul', 527.36)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (21, N'Germany,Berlin', N'07:00', N'France,Paris', 166.87)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (22, N'Germany,Berlin', N'18:00', N'France,Paris', 184.39)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (23, N'Germany,Berlin', N'11:30', N'France,Paris', 224.96)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (24, N'Germany,Berlin', N'12:30', N'France,Paris', 236.94)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (25, N'Germany,Berlin', N'17:00', N'Brazil,Rio de Janeiro', 1193.01)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (26, N'Germany,Berlin', N'06:00', N'Brazil,Rio de Janeiro', 1193.01)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (27, N'Germany,Berlin', N'12:00', N'Brazil,Rio de Janeiro', 1470.52)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (28, N'Germany,Berlin', N'20:00', N'Brazil,Rio de Janeiro', 1553.5)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (29, N'Germany,Berlin', N'06:00', N'USA,New York', 481.26)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (30, N'Germany,Berlin', N'09:00', N'USA,New York', 494.17)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (31, N'Germany,Berlin', N'12:30', N'USA,New York', 554.1)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (32, N'Germany,Berlin', N'9:30', N'USA,New York', 691.47)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (33, N'Germany,Berlin', N'21:30', N'Egypt,Cairo', 426)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (34, N'Germany,Berlin', N'20:30', N'Egypt,Cairo', 440)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (35, N'Germany,Berlin', N'6:30', N'Egypt,Cairo', 462)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (36, N'Germany,Berlin', N'15:00', N'Egypt,Cairo', 533)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (37, N'Germany,Berlin', N'12:00', N'Georgia,Atlanta', 846)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (38, N'Germany,Berlin', N'06:00', N'Georgia,Atlanta', 846)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (39, N'Germany,Berlin', N'09:00', N'Georgia,Atlanta', 846)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (40, N'Germany,Berlin', N'07:00', N'Georgia,Atlanta', 853)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (41, N'France,Paris', N'09:30', N'Romania,Bucharest', 329)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (42, N'France,Paris', N'02:30', N'Romania,Bucharest', 274)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (43, N'France,Paris', N'10:00', N'Romania,Bucharest', 284)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (44, N'France,Paris', N'12:00', N'Romania,Bucharest', 365)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (45, N'France,Paris', N'07:00', N'South Korea, Seoul', 1083)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (46, N'France,Paris', N'02:00', N'South Korea, Seoul', 937)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (47, N'France,Paris', N'04:00', N'South Korea, Seoul', 4923)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (48, N'France,Paris', N'07:30', N'South Korea, Seoul', 879)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (49, N'France,Paris', N'11:00', N'Ukraine,Kyiv', 321)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (50, N'France,Paris', N'07:00', N'Ukraine,Kyiv', 335)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (51, N'France,Paris', N'09:30', N'Ukraine,Kyiv', 502)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (52, N'France,Paris', N'01:30', N'Ukraine,Kyiv', 607)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (53, N'France,Paris', N'08:30', N'Germany.Hamburt', 216)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (54, N'France,Paris', N'07:00', N'Germany.Hamburt', 227)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (55, N'France,Paris', N'02:30', N'Germany.Hamburt', 293)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (56, N'France,Paris', N'10:00', N'Germany.Hamburt', 304)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (57, N'France,Paris', N'10:00', N'Bulgaria,Sofia', 310)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (58, N'France,Paris', N'12:00', N'Bulgaria,Sofia', 341)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (59, N'France,Paris', N'07:00', N'Bulgaria,Sofia', 362)
GO
INSERT [dbo].[Country] ([CountryId], [Name], [Time], [ArrivalDestination], [Price]) VALUES (60, N'France,Paris', N'11:00', N'Bulgaria,Sofia', 420)
GO
INSERT [dbo].[Tickets] ([Id], [CountryId]) VALUES (1, 1)
GO
INSERT [dbo].[Tickets] ([Id], [CountryId]) VALUES (2, 2)
GO
INSERT [dbo].[Tickets] ([Id], [CountryId]) VALUES (3, 3)
GO
INSERT [dbo].[Tickets] ([Id], [CountryId]) VALUES (4, 4)
GO
INSERT [dbo].[Tickets] ([Id], [CountryId]) VALUES (5, 5)
GO
INSERT [dbo].[Tickets] ([Id], [CountryId]) VALUES (6, 6)
GO
INSERT [dbo].[Tickets] ([Id], [CountryId]) VALUES (7, 7)
GO
INSERT [dbo].[Tickets] ([Id], [CountryId]) VALUES (8, 8)
GO
INSERT [dbo].[Tickets] ([Id], [CountryId]) VALUES (9, 9)
GO
INSERT [dbo].[Tickets] ([Id], [CountryId]) VALUES (10, 10)
GO
INSERT [dbo].[Tickets] ([Id], [CountryId]) VALUES (11, 11)
GO
INSERT [dbo].[Tickets] ([Id], [CountryId]) VALUES (12, 12)
GO
INSERT [dbo].[Tickets] ([Id], [CountryId]) VALUES (13, 2)
GO
ALTER TABLE [dbo].[Tickets]  WITH CHECK ADD  CONSTRAINT [FK_Tickets_CountryId] FOREIGN KEY([CountryId])
REFERENCES [dbo].[Country] ([CountryId])
GO
ALTER TABLE [dbo].[Tickets] CHECK CONSTRAINT [FK_Tickets_CountryId]
GO
USE [master]
GO
ALTER DATABASE [AirPort] SET  READ_WRITE 
GO
