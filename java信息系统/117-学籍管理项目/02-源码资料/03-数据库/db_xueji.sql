/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 50735
Source Host           : localhost:3306
Source Database       : db_xueji

Target Server Type    : MYSQL
Target Server Version : 50735
File Encoding         : 65001

Date: 2022-02-07 10:31:52
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for t_admin
-- ----------------------------
DROP TABLE IF EXISTS `t_admin`;
CREATE TABLE `t_admin` (
  `userId` int(10) NOT NULL AUTO_INCREMENT,
  `userName` varchar(55) DEFAULT NULL,
  `userPw` varchar(66) DEFAULT NULL,
  PRIMARY KEY (`userId`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_admin
-- ----------------------------
INSERT INTO `t_admin` VALUES ('1', 'admin', '123456');

-- ----------------------------
-- Table structure for t_banji
-- ----------------------------
DROP TABLE IF EXISTS `t_banji`;
CREATE TABLE `t_banji` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(66) DEFAULT NULL,
  `zhuanye_id` int(10) DEFAULT NULL,
  `del` varchar(55) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_banji
-- ----------------------------
INSERT INTO `t_banji` VALUES ('1', '通信工程专业1班 ', '1', 'no');
INSERT INTO `t_banji` VALUES ('2', '信息工程专业1班 ', '2', 'no');

-- ----------------------------
-- Table structure for t_chengji
-- ----------------------------
DROP TABLE IF EXISTS `t_chengji`;
CREATE TABLE `t_chengji` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `stu_id` int(10) DEFAULT NULL,
  `kecheng_id` int(10) DEFAULT NULL,
  `chengji` int(10) DEFAULT NULL,
  `xuenian` varchar(255) DEFAULT NULL,
  `del` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_chengji
-- ----------------------------
INSERT INTO `t_chengji` VALUES ('1', '1', '1', '100', '大一上', 'no');
INSERT INTO `t_chengji` VALUES ('2', '2', '2', '98', '大二上', 'no');

-- ----------------------------
-- Table structure for t_jiangcheng
-- ----------------------------
DROP TABLE IF EXISTS `t_jiangcheng`;
CREATE TABLE `t_jiangcheng` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `stu_id` int(10) DEFAULT NULL,
  `shijian` varchar(255) DEFAULT NULL,
  `shuxing` varchar(255) DEFAULT NULL,
  `beizhu` varchar(500) DEFAULT NULL,
  `del` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_jiangcheng
-- ----------------------------
INSERT INTO `t_jiangcheng` VALUES ('1', '1', '大一上', '三好学生', '成绩优良', 'no');
INSERT INTO `t_jiangcheng` VALUES ('2', '2', '大二下', '优秀奖金', '成绩前十', 'no');

-- ----------------------------
-- Table structure for t_kecheng
-- ----------------------------
DROP TABLE IF EXISTS `t_kecheng`;
CREATE TABLE `t_kecheng` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  `jieshao` varchar(555) DEFAULT NULL,
  `del` varchar(55) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_kecheng
-- ----------------------------
INSERT INTO `t_kecheng` VALUES ('1', '高等数学', '高等数学', 'no');
INSERT INTO `t_kecheng` VALUES ('2', '通信原理', '通信原理', 'no');

-- ----------------------------
-- Table structure for t_stu
-- ----------------------------
DROP TABLE IF EXISTS `t_stu`;
CREATE TABLE `t_stu` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `xuehao` varchar(55) DEFAULT NULL,
  `name1` varchar(55) DEFAULT NULL,
  `sex` varchar(55) DEFAULT NULL,
  `age` varchar(55) DEFAULT NULL,
  `banji_id` varchar(66) DEFAULT NULL,
  `ruxueshijian` varchar(55) DEFAULT NULL,
  `biyeshijian` varchar(55) DEFAULT NULL,
  `xuezhi` varchar(55) DEFAULT NULL,
  `xuexiao` varchar(55) DEFAULT NULL,
  `del` varchar(55) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_stu
-- ----------------------------
INSERT INTO `t_stu` VALUES ('1', '122682016001', '张三', '男', '23', '1', '2016-09-10', '2020-06-15', '四年', '光电信息学院', 'no');
INSERT INTO `t_stu` VALUES ('2', '122682016002', '李四', '女', '23', '2', '2016-09-10', '2020-06-15', '四年', '光电信息学院', 'no');

-- ----------------------------
-- Table structure for t_zhuanye
-- ----------------------------
DROP TABLE IF EXISTS `t_zhuanye`;
CREATE TABLE `t_zhuanye` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  `jieshao` varchar(555) DEFAULT NULL,
  `del` varchar(66) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_zhuanye
-- ----------------------------
INSERT INTO `t_zhuanye` VALUES ('1', '通信工程专业', '通信工程专业', 'no');
INSERT INTO `t_zhuanye` VALUES ('2', '信息工程专业', '信息工程专业', 'no');
INSERT INTO `t_zhuanye` VALUES ('3', '计算机专业', '计算机专业', 'yes');
