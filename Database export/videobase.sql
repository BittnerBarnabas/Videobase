-- MySQL dump 10.13  Distrib 5.7.12, for Win32 (AMD64)
--
-- Host: localhost    Database: videobase
-- ------------------------------------------------------
-- Server version	5.7.12-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `members`
--

DROP TABLE IF EXISTS `members`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `members` (
  `MEM_ID` int(4) NOT NULL AUTO_INCREMENT,
  `NAME` varchar(120) NOT NULL,
  `ADDRESS` varchar(120) NOT NULL,
  `PHONE` varchar(20) NOT NULL,
  PRIMARY KEY (`MEM_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `members`
--

LOCK TABLES `members` WRITE;
/*!40000 ALTER TABLE `members` DISABLE KEYS */;
INSERT INTO `members` VALUES (1,'Bittner Barnab├ís','1133. Budapest K├írp├ít utca 24.','06702191657'),(2,'Horv├íth Csaba','1053. Budapest Rozgonyi utca 2.','06705462313'),(3,'Cillei Ulrik','2120. Dunakeszi Vir├íg utca 24.','06708423645'),(4,'Bagam├⌐ri Fanni','2151. F├│t Kund P├íl utca 42.','06703541265');
/*!40000 ALTER TABLE `members` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `movies`
--

DROP TABLE IF EXISTS `movies`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `movies` (
  `MOV_ID` int(4) NOT NULL AUTO_INCREMENT,
  `title` varchar(40) NOT NULL,
  `MAIN_CHAR` text NOT NULL,
  `DIRECTOR` varchar(50) NOT NULL,
  `PUBLISHER` varchar(50) NOT NULL,
  `YEAR` year(4) NOT NULL,
  `LOCKED` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`MOV_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `movies`
--

LOCK TABLES `movies` WRITE;
/*!40000 ALTER TABLE `movies` DISABLE KEYS */;
INSERT INTO `movies` VALUES (1,'Inglourious Basterds','Brad Pitt, Diane Kruger, Eli Roth, M├⌐lanie Laurent','Quentin Tarantino','Universal Pictures',2009,0),(2,'Guardians of the Galaxy','Chris Pratt, Vin Diesel, Bradley Cooper','James Gunn','Marvel Studios',2014,0),(3,'Interstellar','Matthew McConaughey, Anne Hathaway, Jessica Chastain','Christopher Nolan','Paramount Pictures',2014,0),(4,'Good Will Hunting','Robin Williams, Matt Damon, Ben Affleck ','Gus Van Sant','Be Gentlemen Limited Partnership',1997,0),(5,'The Shawshank Redemption','Tim Robbins, Morgan Freeman, Bob Gunton','Frank Darabont','Castle Rock Entertainment',1994,0);
/*!40000 ALTER TABLE `movies` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rentals`
--

DROP TABLE IF EXISTS `rentals`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rentals` (
  `RENT_ID` int(4) NOT NULL AUTO_INCREMENT,
  `MEM_ID` int(11) NOT NULL,
  `MOV_ID` int(11) NOT NULL,
  `RENT_DATE` date NOT NULL,
  `RET_DATE` date NOT NULL DEFAULT '2001-01-01',
  PRIMARY KEY (`RENT_ID`),
  KEY `MEM_ID` (`MEM_ID`),
  KEY `MOV_ID` (`MOV_ID`),
  CONSTRAINT `rentals_ibfk_1` FOREIGN KEY (`MEM_ID`) REFERENCES `members` (`MEM_ID`),
  CONSTRAINT `rentals_ibfk_2` FOREIGN KEY (`MOV_ID`) REFERENCES `movies` (`MOV_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rentals`
--

LOCK TABLES `rentals` WRITE;
/*!40000 ALTER TABLE `rentals` DISABLE KEYS */;
INSERT INTO `rentals` VALUES (1,1,2,'2016-04-22','2001-01-01'),(2,2,1,'2016-04-22','2001-01-01'),(9,4,5,'2016-05-01','2001-01-01');
/*!40000 ALTER TABLE `rentals` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-05-03  7:53:35
