package com.mingrisoft.db; //指定类所在的包

import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.util.Properties;

public class DBConnection {
	// 连接对象
	private Connection conn;
	// MYSQL Server驱动程序
	private String MySqlDriver;
	// MYSQL Server连接字符串
	private String MySqlURL;

	@SuppressWarnings("deprecation")
	public Connection getConnToMySql() {
		conn = null;
		Properties prop = new Properties();
		try {
			// 利用类加载器获取配置文件输入流
			InputStream in = getClass().getResourceAsStream("DBConfig.property");
			// 加载配置文件
			prop.load(in);
			// 获取数据库参数
			MySqlDriver = prop.getProperty("MySQLDriver");
			MySqlURL = prop.getProperty("MySQLURL");
			// 加载数据库驱动
			Class.forName(MySqlDriver).newInstance();
			// 获取数据库连接
			conn = (Connection) DriverManager.getConnection(MySqlURL);
			if (in != null)
				in.close();
		} catch (Exception e) {
			System.err.println(e.getMessage());
		}
		return conn;
	}
}
