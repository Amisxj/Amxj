package com.mingrisoft.user;

import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import com.mingrisoft.db.DBConnection;
import com.mingrisoft.utils.Utils;


public class Login {

	DBConnection DBConn = new DBConnection();
	Utils utils = new Utils();

	public boolean LoginCheck(String username, String password) {
		try {
			Connection Conn = DBConn.getConnToMySql();
			boolean OK = true;
			OK = CheckLogin(Conn, username, password);
			return OK;

		} catch (SQLException e) {
			return false;
		}
	}

	public boolean CheckLogin(Connection conn, String username, String password) throws SQLException {
		
		// ResultSet.TYPE_SCROLL_INSENSITIVE结果集可以前后移动
		// ResultSet.CONCUR_UPDATABLE可以更新数据
		Statement stmt = conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
		// 创建数据查询
		ResultSet rs = null;
		boolean OK = true;
		String AdminPwd = "";
		String User = utils.CheckReplace(username);
		String Pwd = utils.CheckReplace(password);
		//密码加上MD5
		String NewPwd =getMD5(Pwd);
		System.out.print(NewPwd);
		// 业务逻辑处理
		String Sql = "select * from Admin where AdminName='" + User + "'";
		rs = stmt.executeQuery(Sql);
		if (!rs.next()) {
			OK = false;
		} else {
			AdminPwd = rs.getString("AdminPwd");
			if (NewPwd.equals(AdminPwd)) {
				OK = true;
			} else {
				OK = false;
			}
		}
		return OK;
	}
	public static String getMD5(String input) {
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] messageDigest = md.digest(input.getBytes());
            BigInteger no = new BigInteger(1, messageDigest);
            String hashtext = no.toString(16);
            hashtext ="123"+ hashtext;
            return hashtext;
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }
}