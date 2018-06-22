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
-- Temporary table structure for view `all_show_info`
--

DROP TABLE IF EXISTS `all_show_info`;
/*!50001 DROP VIEW IF EXISTS `all_show_info`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE VIEW `all_show_info` AS SELECT 
 1 AS `goodsname`,
 1 AS `ei`,
 1 AS `contact`,
 1 AS `source`,
 1 AS `place`,
 1 AS `number`,
 1 AS `price`,
 1 AS `catogory`,
 1 AS `tel`,
 1 AS `apartment`*/;
SET character_set_client = @saved_cs_client;

--
-- Table structure for table `contact`
--

DROP TABLE IF EXISTS `contact`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `contact` (
  `contact` varchar(11) NOT NULL,
  `tel` varchar(11) NOT NULL,
  `apartment` varchar(20) NOT NULL,
  PRIMARY KEY (`contact`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `contact`
--

LOCK TABLES `contact` WRITE;
/*!40000 ALTER TABLE `contact` DISABLE KEYS */;
INSERT INTO `contact` VALUES ('Antonio','12414','宝马汽车公司'),('yamy','1234','鲨鱼厂'),('刘旭','1234','铝合金厂'),('刘老头','1234','大米厂'),('刘能','1234','螺丝刀厂'),('孟美岐','1234','宝马厂'),('张大川','141241','云南毛巾厂'),('杨旭','1234','石灰厂'),('肖晓','1412421324','威海'),('陈大元','1234','棉花厂'),('马东','1234','轮胎厂'),('马薇薇','1234','轮胎厂'),('鲍思佳','1234','砖头厂');
/*!40000 ALTER TABLE `contact` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `contact_all`
--

DROP TABLE IF EXISTS `contact_all`;
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
-- Dumping data for table `contact_all`
--

LOCK TABLES `contact_all` WRITE;
/*!40000 ALTER TABLE `contact_all` DISABLE KEYS */;
INSERT INTO `contact_all` VALUES ('yamy','1234','鲨鱼厂'),('刘旭','1234','铝合金厂'),('刘老头','1234','大米厂'),('刘能','1234','螺丝刀厂'),('孟美岐','1234','宝马厂'),('杨旭','1234','石灰厂'),('陈大元','1234','棉花厂'),('马东','1234','轮胎厂'),('马薇薇','1234','轮胎厂'),('鲍思佳','1234','砖头厂');
/*!40000 ALTER TABLE `contact_all` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `eiinfo`
--

DROP TABLE IF EXISTS `eiinfo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `eiinfo` (
  `goodsname` varchar(10) NOT NULL,
  `ei` varchar(5) NOT NULL,
  `contact` varchar(20) NOT NULL,
  PRIMARY KEY (`goodsname`,`ei`,`contact`),
  KEY `fk_contact` (`contact`),
  KEY `fk_1` (`goodsname`,`contact`),
  CONSTRAINT `fk_1` FOREIGN KEY (`goodsname`, `contact`) REFERENCES `goodsinfo` (`goodsname`, `contact`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_contact` FOREIGN KEY (`contact`) REFERENCES `contact` (`contact`) ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `eiinfo`
--

LOCK TABLES `eiinfo` WRITE;
/*!40000 ALTER TABLE `eiinfo` DISABLE KEYS */;
INSERT INTO `eiinfo` VALUES ('方向盘','出货','Antonio'),('鲨鱼','进货','yamy'),('铝合金','进货','刘旭'),('大米','进货','刘老头'),('毛巾','进货','张大川'),('生石灰','出货','杨旭'),('钉子','出货','肖晓'),('棉花','进货','陈大元'),('轮胎','进货','马东'),('轮胎','进货','马薇薇'),('砖头','进货','鲍思佳');
/*!40000 ALTER TABLE `eiinfo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `eiinfo_all`
--

DROP TABLE IF EXISTS `eiinfo_all`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `eiinfo_all` (
  `goodsname` varchar(10) NOT NULL,
  `ei` varchar(5) NOT NULL,
  `contact` varchar(20) NOT NULL,
  PRIMARY KEY (`goodsname`,`ei`,`contact`),
  KEY `fk_contact` (`contact`),
  KEY `fk_1` (`goodsname`,`contact`),
  CONSTRAINT `ei_all_c` FOREIGN KEY (`contact`) REFERENCES `contact` (`contact`) ON UPDATE CASCADE,
  CONSTRAINT `ei_all_gc` FOREIGN KEY (`goodsname`, `contact`) REFERENCES `goodsinfo` (`goodsname`, `contact`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `eiinfo_all`
--

LOCK TABLES `eiinfo_all` WRITE;
/*!40000 ALTER TABLE `eiinfo_all` DISABLE KEYS */;
/*!40000 ALTER TABLE `eiinfo_all` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `goodsinfo`
--

DROP TABLE IF EXISTS `goodsinfo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `goodsinfo` (
  `goodsname` varchar(10) NOT NULL,
  `source` varchar(20) DEFAULT NULL,
  `place` varchar(20) DEFAULT NULL,
  `number` int(5) DEFAULT NULL,
  `price` float DEFAULT NULL,
  `catogory` varchar(10) DEFAULT NULL,
  `contact` varchar(20) NOT NULL,
  PRIMARY KEY (`goodsname`,`contact`),
  KEY `contact` (`contact`),
  CONSTRAINT `goodsinfo_ibfk_1` FOREIGN KEY (`contact`) REFERENCES `contact` (`contact`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `goodsinfo`
--

LOCK TABLES `goodsinfo` WRITE;
/*!40000 ALTER TABLE `goodsinfo` DISABLE KEYS */;
INSERT INTO `goodsinfo` VALUES ('大米','大连','威海',79,79.33,'农业产品','刘老头'),('方向盘','Los Angeles','LA',500,800000,'其他','Antonio'),('棉花','大连','威海',79,79.33,'农业产品','陈大元'),('毛巾','云南','大连',40,50.8,'其他','张大川'),('生石灰','大连','威海',79,79.33,'化工材料','杨旭'),('砖头','大连','威海',79,79.33,'建筑材料','鲍思佳'),('轮胎','大连','威海',79,79.33,'车辆配件','马东'),('轮胎','大连','威海',79,79.33,'车辆配件','马薇薇'),('钉子','深圳','山东',50,60.3,'机电五金','肖晓'),('铝合金','大连','威海',79,79.33,'金属材料','刘旭'),('鲨鱼','太原','威海',79,79.33,'金属材料','yamy');
/*!40000 ALTER TABLE `goodsinfo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `goodsinfo_all`
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
  CONSTRAINT `goodsinfo_all_ibfk_1` FOREIGN KEY (`contact`) REFERENCES `contact_all` (`contact`) ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `goodsinfo_all`
--

LOCK TABLES `goodsinfo_all` WRITE;
/*!40000 ALTER TABLE `goodsinfo_all` DISABLE KEYS */;
INSERT INTO `goodsinfo_all` VALUES ('大米','大连','威海',79,79.33,'农业产品','刘老头'),('宝马','大连','威海',79,79.33,'车辆配件','孟美岐'),('棉花','大连','威海',79,79.33,'农业产品','陈大元'),('生石灰','大连','威海',79,79.33,'化工材料','杨旭'),('砖头','大连','威海',79,79.33,'建筑材料','鲍思佳'),('螺丝刀','大连','威海',79,79.33,'机电五金','刘能'),('轮胎','大连','威海',79,79.33,'车辆配件','马东'),('轮胎','大连','威海',79,79.33,'车辆配件','马薇薇'),('铝合金','大连','威海',79,79.33,'金属材料','刘旭'),('鲨鱼','大连','威海',79,79.33,'金属材料','yamy');
/*!40000 ALTER TABLE `goodsinfo_all` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `userinfo`
--

DROP TABLE IF EXISTS `userinfo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `userinfo` (
  `username` varchar(10) NOT NULL,
  `password` varchar(20) NOT NULL,
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `userinfo`
--

LOCK TABLES `userinfo` WRITE;
/*!40000 ALTER TABLE `userinfo` DISABLE KEYS */;
INSERT INTO `userinfo` VALUES ('123','123');
/*!40000 ALTER TABLE `userinfo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Final view structure for view `all_show_info`
--

/*!50001 DROP VIEW IF EXISTS `all_show_info`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `all_show_info` AS select `eiinfo`.`goodsname` AS `goodsname`,`eiinfo`.`ei` AS `ei`,`eiinfo`.`contact` AS `contact`,`goodsinfo`.`source` AS `source`,`goodsinfo`.`place` AS `place`,`goodsinfo`.`number` AS `number`,`goodsinfo`.`price` AS `price`,`goodsinfo`.`catogory` AS `catogory`,`contact`.`tel` AS `tel`,`contact`.`apartment` AS `apartment` from ((`eiinfo` join `goodsinfo`) join `contact`) where ((`eiinfo`.`contact` = `goodsinfo`.`contact`) and (`goodsinfo`.`contact` = `contact`.`contact`)) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-06-08  8:49:46
