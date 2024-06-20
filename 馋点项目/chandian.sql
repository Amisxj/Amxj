/*
 Navicat Premium Data Transfer

 Source Server         : xiaojie
 Source Server Type    : MySQL
 Source Server Version : 50739
 Source Host           : localhost:3305
 Source Schema         : chandian

 Target Server Type    : MySQL
 Target Server Version : 50739
 File Encoding         : 65001

 Date: 15/12/2023 17:06:07
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for address
-- ----------------------------
DROP TABLE IF EXISTS `address`;
CREATE TABLE `address`  (
  `inschool` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `outschol` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `wanda` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `market` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `laojie` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of address
-- ----------------------------

-- ----------------------------
-- Table structure for admin
-- ----------------------------
DROP TABLE IF EXISTS `admin`;
CREATE TABLE `admin`  (
  `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `account` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `password` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 2 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of admin
-- ----------------------------
INSERT INTO `admin` VALUES (1, 'xj', '123');

-- ----------------------------
-- Table structure for messageboard
-- ----------------------------
DROP TABLE IF EXISTS `messageboard`;
CREATE TABLE `messageboard`  (
  `mid` int(11) NOT NULL AUTO_INCREMENT,
  `restaurant` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `datetime` datetime NOT NULL,
  `message` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `evaluate` float(255, 1) NULL DEFAULT NULL,
  PRIMARY KEY (`mid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 39 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of messageboard
-- ----------------------------
INSERT INTO `messageboard` VALUES (1, '美食汇', '小杰', '2023-12-03 23:23:50', '正在工作', 1.0);
INSERT INTO `messageboard` VALUES (2, '美食汇', '小廖', '2023-12-08 14:17:29', '睡觉', 5.0);
INSERT INTO `messageboard` VALUES (3, '美食汇', '小无', '2023-12-27 14:18:12', '看电视', 5.0);
INSERT INTO `messageboard` VALUES (4, '336饭馆', '小杰', '2023-12-18 14:20:28', '正在测试', NULL);
INSERT INTO `messageboard` VALUES (5, 'TACO KING 美式墨西哥餐厅', '123', '2023-12-14 23:20:15', '好吃', NULL);
INSERT INTO `messageboard` VALUES (6, 'TACO KING 美式墨西哥餐厅', '123', '2023-12-14 23:21:36', '还不错', NULL);
INSERT INTO `messageboard` VALUES (7, 'TACO KING 美式墨西哥餐厅', '123', '2023-12-14 23:24:30', '可以', NULL);
INSERT INTO `messageboard` VALUES (8, 'TACO KING 美式墨西哥餐厅', '123', '2023-12-14 23:26:10', '行把', NULL);
INSERT INTO `messageboard` VALUES (9, '重庆小面', '123', '2023-12-14 23:26:59', '我觉得不错', NULL);
INSERT INTO `messageboard` VALUES (10, '书亦烧仙草', '123', '2023-12-14 23:27:27', '口味很可以', NULL);
INSERT INTO `messageboard` VALUES (11, 'TACO KING 美式墨西哥餐厅', 'wmj', '2023-12-14 15:36:13', '这个味道不错', NULL);
INSERT INTO `messageboard` VALUES (12, '瑞幸咖啡', 'ls', '2023-12-14 15:53:05', '这家店非常好吃', NULL);
INSERT INTO `messageboard` VALUES (13, '匠心卤', '123', '2023-12-15 15:42:17', '12345', NULL);
INSERT INTO `messageboard` VALUES (14, '711便利店', 'wmjxy', '2023-12-15 07:52:15', '还不错', NULL);
INSERT INTO `messageboard` VALUES (15, 'TACO KING 美式墨西哥餐厅', 'wmj', '2023-12-15 08:07:33', '感觉还可以', NULL);

-- ----------------------------
-- Table structure for restaurant
-- ----------------------------
DROP TABLE IF EXISTS `restaurant`;
CREATE TABLE `restaurant`  (
  `id` int(255) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `range` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `address` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `type` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `price` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `image` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `evaluate` float(10, 1) NULL DEFAULT NULL,
  `telephone` varchar(11) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 80 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of restaurant
-- ----------------------------
INSERT INTO `restaurant` VALUES (1, 'Hi锅鸭爪爪', '万达区', '綦江区万达广场3F', '面食、粉食系列', '69.9', 'Higuo (1).jpg', 5.0, '112');
INSERT INTO `restaurant` VALUES (2, '霸王茶姬', '万达区', '綦江区万达广场3F', '休闲甜点', '18.8', 'bawangchaji (1).jpg', 3.5, '153');
INSERT INTO `restaurant` VALUES (3, '德香宛脆皮烤鸭', '万达区', '綦江区万达广场3F', '夜市系列', '89.9', 'dexiangwan (1).jpg', 4.0, '15432074');
INSERT INTO `restaurant` VALUES (4, '汉堡王', '万达区', '綦江区万达广场3F', '休闲甜点', '26.9', 'hanbaowang (1).jpg', 3.2, '34');
INSERT INTO `restaurant` VALUES (5, '吉布鲁牛排烤肉自助', '万达区', '綦江区万达广场3F', '自助餐', '79.9', 'jibulu (1).jpg', 4.3, NULL);
INSERT INTO `restaurant` VALUES (6, '贾如集市串串', '万达区', '綦江区万达广场3F', '火锅', '66.9', 'jiaru (1).jpg', 4.3, NULL);
INSERT INTO `restaurant` VALUES (7, '皮皮岛·泰式大排档', '万达区', '綦江区万达广场3F', '美食', '69.9', 'pipidao (1).jpg', 2.3, NULL);
INSERT INTO `restaurant` VALUES (8, '日之屋·炭火烤肉·寿司料理', '万达区', '綦江区万达广场3F', '美食', '88.8', 'rizhiwu (1).jpg', 3.2, NULL);
INSERT INTO `restaurant` VALUES (9, '蓉李记成都名小吃', '万达区', '綦江区万达广场3F', '快餐小吃', '19.9', 'rongji (1).jpg', 5.0, '');
INSERT INTO `restaurant` VALUES (10, '瑞幸咖啡', '万达区', '綦江区万达广场3F', '茶饮', '16.6', 'ruixing (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (11, '外婆傢', '万达区', '綦江区万达广场3F', '美食', '68.9', 'waipojia (1).jpg', 4.3, NULL);
INSERT INTO `restaurant` VALUES (12, '我们麦火锅', '万达区', '綦江区万达广场3F', '火锅', '56.9', 'womenmai (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (13, '喜茶', '万达区', '綦江区万达广场3F', '奶茶', '12.8', 'xicha (1).jpg', 3.5, NULL);
INSERT INTO `restaurant` VALUES (14, '小南姜酸汤一人锅', '万达区', '綦江区万达广场3F', '汤锅', '48.8', 'xiaonan (1).jpg', 2.3, NULL);
INSERT INTO `restaurant` VALUES (15, '小猪查理', '万达区', '綦江区万达广场3F', '自助餐', '68.9', 'xiaozhu (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (16, '蟹恋锅虾蟹煲', '万达区', '綦江区万达广场3F', '汤锅', '88.9', 'xielianguo (1).jpg', 4.9, NULL);
INSERT INTO `restaurant` VALUES (17, '艾小九', '校门区', '綦江区移通学院3号门', '干锅', '12.8', 'aixiaojiu (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (18, '霸道小面', '校门区', '綦江区移通学院3号门', '面食', '8.8', 'badaoxiaomian (1).jpg', 4.6, NULL);
INSERT INTO `restaurant` VALUES (19, '初茶花月', '校门区', '綦江区移通学院3号门', '奶茶', '12.9', 'chuchahuayue (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (20, '大犇火锅串串香', '校门区', '綦江区移通学院3号门', '火锅', '59.9', 'daniuhuoguo (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (21, '福禄哆自选火锅', '校门区', '綦江区移通学院B3—08', '火锅', '69.9', 'fuluduo (1).jpg', 4.7, NULL);
INSERT INTO `restaurant` VALUES (22, '港式烧腊', '校门区', '綦江区移通学院美食汇', '快餐', '12.5', 'gangshishaola (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (23, '花雕醉鸡', '校门区', '綦江区移通学院B3—08', '美食', '79.9', 'huadiaozuiji (1).jpg', 4.3, NULL);
INSERT INTO `restaurant` VALUES (24, '疆粉儿·新疆炒米粉', '校门区', '綦江区移通学院3号门', '美食', '13.9', 'jiangfener (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (25, '蜜雪冰城', '校门区', '綦江区移通学院3号门', '奶茶', '5.5', 'mixuebingcheng (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (26, '书亦烧仙草', '校门区', '綦江区移通学院3号门', '奶茶', '12.5', 'shuyi (1).jpg', 4.5, NULL);
INSERT INTO `restaurant` VALUES (27, '唐记', '校门区', '綦江区移通学院3号门', '焖锅', '36.9', 'tangji (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (28, '围醉', '校门区', '綦江区移通学院B3—08', '烧烤', '59.9', 'weizui (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (29, '羊阳洋', '校门区', '綦江区移通学院3号门', '火锅', '19', 'yangyangyang (1).jpg', 4.3, NULL);
INSERT INTO `restaurant` VALUES (30, '张亮麻辣烫', '校门区', '綦江区移通学院3号门', '美食', '15.9', 'zhangliang (1).jpg', 4.3, NULL);
INSERT INTO `restaurant` VALUES (31, '重庆鸡公煲', '校门区', '綦江区移通学院3号门', '干锅', '56.9', 'jigongbao (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (32, 'F+牛肉饭', '校门区', '綦江区移通学院美食汇', '快餐', '12.5', 'niuroufan (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (33, 'TACO KING 美式墨西哥餐厅', '校内区', '綦江区移通学院B3—05', '美食', '19.9', 'tacoking (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (34, '五谷杂粮鱼粉', '校内区', '綦江区移通学院北渡食堂', '面食', '13.9', 'wuguyufen (1).png', 3.6, NULL);
INSERT INTO `restaurant` VALUES (35, '兰州拉面', '校内区', '綦江区移通学院北渡食堂', '面食', '14.5', 'lanzhou (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (36, '冒椒火辣', '校内区', '綦江区移通学院北渡食堂', '美食', '16.9', 'maojiao (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (37, '北村韩屋·韩式炸鸡', '校内区', '綦江区移通学院B3—06', '快餐', '26.9', 'beicun (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (38, '匠心卤', '校内区', '綦江区移通学院北渡食堂', '快餐', '12.6', 'jiangxinlu (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (39, '周记烤鸭', '校内区', '綦江区移通学院北渡食堂', '套饭', '13.9', 'zhoujikaoya (1).jpg', 4.8, NULL);
INSERT INTO `restaurant` VALUES (40, '外婆卤肉饭', '校内区', '綦江区移通学院北渡食堂', '套饭', '11.9', 'waipo (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (41, '宜佳鲜牛牛肉粉', '校内区', '綦江区移通学院北渡食堂', '面食', '15.9', 'yijiaxianniu (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (42, '小薇薇', '校内区', '綦江区移通学院B3—07', '烤肉', '56.9', 'xiaoweiwei (1).png', NULL, NULL);
INSERT INTO `restaurant` VALUES (43, '库迪咖啡', '校内区', '綦江区移通学院B3—11', '咖啡', '18.8', 'kudi (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (44, '悟香浓水饺', '校内区', '綦江区移通学院北渡食堂', '美食', '16.9', 'wuxiangnong (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (45, '时光石锅拌饭', '校内区', '綦江区移通学院北渡食堂', '美食', '15.5', 'shiguo (1).png', 4.3, NULL);
INSERT INTO `restaurant` VALUES (46, '模饭少年', '校内区', '綦江区移通学院北渡食堂', '炒饭', '13.5', 'mofan (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (47, '水煮江湖', '校内区', '綦江区移通学院北渡食堂', '美食', '16.9', 'shuizhu (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (48, '米洛西娅', '校内区', '綦江区移通学院B3—09', '面包', '18.8', 'miluoxiya  (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (49, '精品套餐', '校内区', '綦江区移通学院北渡食堂', '套饭', '12', 'taofan (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (50, '茶百道', '校内区', '綦江区移通学院B3—10', '奶茶', '16.9', 'chabaidao (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (51, '酱香饼', '校内区', '綦江区移通学院北渡食堂', '饼类', '4.5', 'jiangxiangbing (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (52, '重庆小面', '校内区', '綦江区移通学院北渡食堂', '面食', '6.9', 'chongqingxiaomian (1).png', 4.9, NULL);
INSERT INTO `restaurant` VALUES (53, '麦速堡', '校内区', '綦江区移通学院北渡食堂', '快餐', '12.8', 'maisubao (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (54, '麻哥抄手', '校内区', '綦江区移通学院北渡食堂', '面食', '13.9', 'mage (1).jpg', NULL, NULL);
INSERT INTO `restaurant` VALUES (55, '711便利店', '校园小卖部区', '綦江区移通学院綦河书院3号楼', '百货', '6.9', 'qiyiyi (1).png', NULL, NULL);
INSERT INTO `restaurant` VALUES (56, '天猫超市', '校园小卖部区', '綦江区移通学院3号门', '百货', '3.9', 'tianmao (1).png', NULL, NULL);
INSERT INTO `restaurant` VALUES (57, '校园超市', '校园小卖部区', '綦江区移通学院B3—04', '百货', '7.9', 'xiaoyuanchaoshi (1).png', NULL, NULL);
INSERT INTO `restaurant` VALUES (58, '兄弟烧烤', '校园周边区', '綦江区移通学院美食街', '烧烤', '12.9', 'xiongdishaokao (1).jpg', 4.6, NULL);
INSERT INTO `restaurant` VALUES (59, '卷饭天卤肉饼', '校园周边区', '綦江区移通学院美食街', '饼类', '13.8', 'juanfantian (1).png', NULL, NULL);
INSERT INTO `restaurant` VALUES (60, '大叔臭豆腐', '校园周边区', '綦江区移通学院美食街', '美食', '9.9', 'dashu (1).png', NULL, NULL);
INSERT INTO `restaurant` VALUES (61, '小钻风儿烤冷面', '校园周边区', '綦江区移通学院美食街', '美食', '12.8', 'kaolengmian (1).png', NULL, NULL);
INSERT INTO `restaurant` VALUES (62, '广东肠粉', '校园周边区', '綦江区移通学院美食街', '美食', '11.8', 'changfen (1).png', 1.7, NULL);
INSERT INTO `restaurant` VALUES (63, '杜家砂锅米线', '校园周边区', '綦江区移通学院美食街', '美食', '12.5', 'dujia (1).png', NULL, NULL);
INSERT INTO `restaurant` VALUES (64, '梅菜扣肉', '校园周边区', '綦江区移通学院美食街', '美食', '7.8', 'meicaikourou (1).png', 5.4, NULL);
INSERT INTO `restaurant` VALUES (65, '火锅冒菜', '校园周边区', '綦江区移通学院美食街', '美食', '16.6', 'huoguomaocai (1).png', NULL, NULL);
INSERT INTO `restaurant` VALUES (66, '爱情麻辣烫', '校园周边区', '綦江区移通学院美食街', '美食', '15.9', 'aiqingmalatang (1).png', NULL, NULL);
INSERT INTO `restaurant` VALUES (67, '牟记小厨', '校园周边区', '綦江区移通学院美食街', '炒饭', '14.5', 'mouji (1).png', NULL, NULL);
INSERT INTO `restaurant` VALUES (68, '特色酸辣粉', '校园周边区', '綦江区移通学院美食街', '美食', '8.8', 'suanlafen (1).png', NULL, NULL);
INSERT INTO `restaurant` VALUES (69, '生煎包', '校园周边区', '綦江区移通学院美食街', '美食', '6.6', 'shengjianbao (1).png', NULL, NULL);
INSERT INTO `restaurant` VALUES (70, '福鼎肉片', '校园周边区', '綦江区移通学院美食街', '美食', '16.8', 'fuding (1).png', 3.8, NULL);
INSERT INTO `restaurant` VALUES (71, '老潼关肉夹馍', '校园周边区', '綦江区移通学院美食街', '美食', '12.5', 'roujiamo (1).png', NULL, NULL);
INSERT INTO `restaurant` VALUES (72, '胖妈炒饭', '校园周边区', '綦江区移通学院美食街', '炒饭', '13.9', 'pangma (1).png', NULL, NULL);
INSERT INTO `restaurant` VALUES (73, '蛋烘糕', '校园周边区', '綦江区移通学院美食街', '蛋糕', '6.6', 'danhonggao (1).png', NULL, NULL);
INSERT INTO `restaurant` VALUES (74, '贵阳糯米饭', '校园周边区', '綦江区移通学院美食街', '', '8.9', 'guiyang (1).jpg', 2.4, '');
INSERT INTO `restaurant` VALUES (75, '鱿鱼记', '校园周边区', '綦江区移通学院美食街', '烧烤', '7.8', 'youyuji (1).png', NULL, NULL);

-- ----------------------------
-- Table structure for score
-- ----------------------------
DROP TABLE IF EXISTS `score`;
CREATE TABLE `score`  (
  `score` float NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of score
-- ----------------------------
INSERT INTO `score` VALUES (1);

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user`  (
  `userid` int(11) NOT NULL AUTO_INCREMENT,
  `account` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `password` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`userid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 8 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES (1, '123', '123');
INSERT INTO `user` VALUES (2, 'wmj', '12345');

-- ----------------------------
-- Table structure for wanda
-- ----------------------------
DROP TABLE IF EXISTS `wanda`;
CREATE TABLE `wanda`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `restaurant` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of wanda
-- ----------------------------

-- ----------------------------
-- Table structure for xiaomen
-- ----------------------------
DROP TABLE IF EXISTS `xiaomen`;
CREATE TABLE `xiaomen`  (
  `序号` int(255) NOT NULL,
  `店名` varchar(15) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL DEFAULT '',
  `地址` varchar(40) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`店名`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of xiaomen
-- ----------------------------
INSERT INTO `xiaomen` VALUES (7, '原食家牛肉饭', '校门');
INSERT INTO `xiaomen` VALUES (4, '唐记特色焖锅', '校门');
INSERT INTO `xiaomen` VALUES (12, '好食光炸鸡', '校门');
INSERT INTO `xiaomen` VALUES (6, '张亮麻辣烫', '校门');
INSERT INTO `xiaomen` VALUES (14, '杨记黄焖鸡', '校门');
INSERT INTO `xiaomen` VALUES (8, '校园小炒', '校门');
INSERT INTO `xiaomen` VALUES (2, '爱尚鸡排', '校门');
INSERT INTO `xiaomen` VALUES (15, '盐度干锅', '校门');
INSERT INTO `xiaomen` VALUES (17, '茶嘟嘟', '校门');
INSERT INTO `xiaomen` VALUES (11, '菜得快', '校门');
INSERT INTO `xiaomen` VALUES (9, '赵酸酸四鲜米线', '校门');
INSERT INTO `xiaomen` VALUES (5, '重庆火锅冒菜', '校门');
INSERT INTO `xiaomen` VALUES (3, '重庆鸡公煲', '校门');
INSERT INTO `xiaomen` VALUES (13, '铁板厨房', '校门');
INSERT INTO `xiaomen` VALUES (10, '隆江猪脚饭', '校门');
INSERT INTO `xiaomen` VALUES (1, '霸道小面', '校门');
INSERT INTO `xiaomen` VALUES (16, '鸭老板', '校门');

-- ----------------------------
-- Table structure for xiaonei
-- ----------------------------
DROP TABLE IF EXISTS `xiaonei`;
CREATE TABLE `xiaonei`  (
  `序号` int(255) NOT NULL,
  `店名` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  PRIMARY KEY (`店名`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of xiaonei
-- ----------------------------
INSERT INTO `xiaonei` VALUES (7, '原食家牛肉饭');
INSERT INTO `xiaonei` VALUES (4, '唐记特色焖锅');
INSERT INTO `xiaonei` VALUES (12, '好食光炸鸡');
INSERT INTO `xiaonei` VALUES (6, '张亮麻辣烫');
INSERT INTO `xiaonei` VALUES (14, '杨记黄焖鸡');
INSERT INTO `xiaonei` VALUES (8, '校园小炒');
INSERT INTO `xiaonei` VALUES (2, '爱尚鸡排');
INSERT INTO `xiaonei` VALUES (15, '盐度干锅');
INSERT INTO `xiaonei` VALUES (17, '茶嘟嘟');
INSERT INTO `xiaonei` VALUES (11, '菜得快');
INSERT INTO `xiaonei` VALUES (9, '赵酸酸四鲜米线');
INSERT INTO `xiaonei` VALUES (5, '重庆火锅冒菜');
INSERT INTO `xiaonei` VALUES (3, '重庆鸡公煲');
INSERT INTO `xiaonei` VALUES (13, '铁板厨房');
INSERT INTO `xiaonei` VALUES (10, '隆江猪脚饭');
INSERT INTO `xiaonei` VALUES (1, '霸道小面');
INSERT INTO `xiaonei` VALUES (16, '鸭老板');

SET FOREIGN_KEY_CHECKS = 1;
