-- MySQL dump 10.13  Distrib 5.7.21, for Win64 (x86_64)
--
-- Host: localhost    Database: a2
-- ------------------------------------------------------
-- Server version	5.7.21

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
-- Table structure for table `goodsinfo`
--

DROP TABLE IF EXISTS `goodsinfo_all`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `goodsinfo_all` (
  `goodsname` varchar(10) NOT NULL,
  `source` varchar(20) DEFAULT NULL,
  `place` varchar(20) DEFAULT NULL,
  `number` int(5) DEFAULT NULL,
  `price` float DEFAULT NULL,
  `catogory` varchar(10) DEFAULT NULL,
  `contact` varchar(20) NOT NULL,
  PRIMARY KEY (`goodsname`,`contact`),
  KEY `contact` (`contact`),
  CONSTRAINT `gi_all_fk` FOREIGN KEY (`contact`) REFERENCES `contact` (`contact`) ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `goodsinfo`
--



--
-- Table structure for table `eiinfo`
--

/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `eiinfo_all` (
  `goodsname` varchar(10) NOT NULL,
  `ei` varchar(5) NOT NULL,
  `contact` varchar(20) NOT NULL,
  PRIMARY KEY (`goodsname`,`ei`,`contact`),
  KEY `fk_contact` (`contact`),
  KEY `fk_1` (`goodsname`,`contact`),
  CONSTRAINT `ei_all_gc` FOREIGN KEY (`goodsname`, `contact`) REFERENCES `goodsinfo` (`goodsname`, `contact`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `ei_all_c` FOREIGN KEY (`contact`) REFERENCES `contact` (`contact`) ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `eiinfo`
--

--
-- Table structure for table `contact`
--

/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `contact_all` (
  `contact` varchar(11) NOT NULL,
  `tel` varchar(11) NOT NULL,
  `apartment` varchar(20) NOT NULL,
  PRIMARY KEY (`contact`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `contact`
--

/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-06-07 10:19:37
