/*
 Navicat MySQL Data Transfer

 Source Server         : mysqlConnection
 Source Server Type    : MySQL
 Source Server Version : 80034 (8.0.34)
 Source Host           : 127.0.0.1:3306
 Source Schema         : hdats

 Target Server Type    : MySQL
 Target Server Version : 80034 (8.0.34)
 File Encoding         : 65001

 Date: 10/01/2024 20:28:29
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for diagnostic_records
-- ----------------------------
DROP TABLE IF EXISTS `diagnostic_records`;
CREATE TABLE `diagnostic_records` (
  `DR_ID` int NOT NULL AUTO_INCREMENT,
  `D_NAME` varchar(32) NOT NULL COMMENT '医生姓名',
  `P_NAME` varchar(32) NOT NULL COMMENT '患者姓名',
  `DATEOFVISIT` date NOT NULL COMMENT '就诊日期',
  `CONTEXT` text COMMENT '诊断结果',
  PRIMARY KEY (`DR_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=32 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='诊断记录';

-- ----------------------------
-- Table structure for doctor
-- ----------------------------
DROP TABLE IF EXISTS `doctor`;
CREATE TABLE `doctor` (
  `D_ID` int NOT NULL AUTO_INCREMENT,
  `D_NAME` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `D_MOBILEPHOME` varchar(32) COLLATE utf8mb4_general_ci NOT NULL COMMENT '电话号码',
  `D_SEX` varchar(10) COLLATE utf8mb4_general_ci NOT NULL,
  `PASSWORD` varchar(50) COLLATE utf8mb4_general_ci NOT NULL,
  `PLevel` int NOT NULL COMMENT '权限等级',
  `PCNO` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL COMMENT '执业证书号',
  `D_BIRTHDATE` date NOT NULL,
  PRIMARY KEY (`D_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- ----------------------------
-- Table structure for drug
-- ----------------------------
DROP TABLE IF EXISTS `drug`;
CREATE TABLE `drug` (
  `DRUG_ID` int NOT NULL AUTO_INCREMENT,
  `DRUG_NAME` varchar(32) NOT NULL,
  `DOSE` varchar(32) NOT NULL COMMENT '剂量',
  `INVENTORY` int NOT NULL COMMENT '库存',
  `DRUG_INTRODUCTION_TIME` date NOT NULL COMMENT '药品引入时间',
  PRIMARY KEY (`DRUG_ID`) USING BTREE,
  UNIQUE KEY `DRUG_NAME` (`DRUG_NAME`) COMMENT '药品名字唯一'
) ENGINE=InnoDB AUTO_INCREMENT=25 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='药品';

-- ----------------------------
-- Table structure for medication_record
-- ----------------------------
DROP TABLE IF EXISTS `medication_record`;
CREATE TABLE `medication_record` (
  `MRDR_ID` int NOT NULL COMMENT '诊断记录ID',
  `DrugName` varchar(32) NOT NULL,
  PRIMARY KEY (`MRDR_ID`,`DrugName`) USING BTREE,
  KEY `MRDR_ID` (`MRDR_ID`) USING BTREE,
  KEY `MRDRUG_ID` (`DrugName`),
  CONSTRAINT `medication_record_ibfk_1` FOREIGN KEY (`MRDR_ID`) REFERENCES `diagnostic_records` (`DR_ID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='药品开具记录';

-- ----------------------------
-- Table structure for patient
-- ----------------------------
DROP TABLE IF EXISTS `patient`;
CREATE TABLE `patient` (
  `P_ID` int NOT NULL AUTO_INCREMENT,
  `P_NAME` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `P_MOBILEPHOME` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `P_SEX` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `HEIGHT` double(5,2) NOT NULL,
  `WEIGHT` double(5,2) NOT NULL,
  `P_BIRTHDATE` date NOT NULL,
  PRIMARY KEY (`P_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=65 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- ----------------------------
-- Table structure for work_report
-- ----------------------------
DROP TABLE IF EXISTS `work_report`;
CREATE TABLE `work_report` (
  `WRID` int NOT NULL AUTO_INCREMENT,
  `WRD_ID` int NOT NULL,
  `D_NAME` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `CREATETIMESTAMP` date NOT NULL,
  `DiagnosisSituation` text COMMENT '诊疗情况',
  `TreatmentEffect` text COMMENT '治疗效果评估',
  PRIMARY KEY (`WRID`),
  KEY `WRD_ID` (`WRD_ID`),
  CONSTRAINT `work_report_ibfk_1` FOREIGN KEY (`WRD_ID`) REFERENCES `doctor` (`D_ID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Function structure for addDiagnosticRecord
-- ----------------------------
DROP FUNCTION IF EXISTS `addDiagnosticRecord`;
delimiter ;;
CREATE FUNCTION `addDiagnosticRecord`(dname VARCHAR(32), pname VARCHAR(32), dataOfVisit DATE, context TEXT)
 RETURNS int
  DETERMINISTIC
  SQL SECURITY INVOKER
BEGIN
	DECLARE id INT;
  INSERT INTO diagnostic_records (D_NAME, P_NAME, DATEOFVISIT, CONTEXT) VALUES (dname, pname, dataOfVisit, context);
	SELECT LAST_INSERT_ID() INTO id;
	RETURN id;
END
;;
delimiter ;

SET FOREIGN_KEY_CHECKS = 1;
