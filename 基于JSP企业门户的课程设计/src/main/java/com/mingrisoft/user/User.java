package com.mingrisoft.user;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;

import com.mingrisoft.db.DBConnection;
import com.mingrisoft.utils.Utils;

public class User {
	DBConnection DBConn = new DBConnection();
	Utils utils = new Utils();

	public String AdminName, AdminPwd, LastLoginTime;
	public int AdminID, AdminType;
	public String[] sType = new String[4];

	public User() {
		sType[1] = "";
		sType[2] = "";
		sType[3] = "";
	}

	public String ListUser(String sPage, String strPage) {
		try {
			Connection Conn = DBConn.getConnToMySql();
			// ResultSet.TYPE_SCROLL_INSENSITIVE结果集可以前后移动
			// ResultSet.CONCUR_UPDATABLE可以更新数据
			Statement stmt = Conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);	
			ResultSet rs = null;
			StringBuffer sb = new StringBuffer();

			int i;
			int intPage = 1;
			int intPageSize = 5;

			String sSql = "select * from Admin order by AdminID desc";
			rs = stmt.executeQuery(sSql);
			if (!rs.next()) {
				sb.append("<tr height=\"25\" bgcolor=\"#d6dff7\"  class=\"info1\"><td colspan=\"4\">\r\n");
				sb.append("<div align=\"center\"><b>无用户</b></div></td></tr>\r\n");
			} else {
				intPage = utils.StrToInt(strPage);
				sPage = utils.CheckReplace(sPage);
				if (intPage == 0)
					intPage = 1;

				rs.absolute((intPage - 1) * intPageSize + 1);
				i = 0;
				while (i < intPageSize && !rs.isAfterLast()) {
					int AdminID = rs.getInt("AdminID");
					String AdminName = rs.getString("AdminName");
					String AdminPwd = rs.getString("AdminPwd");
					String LastLoginTime = rs.getString("LastLoginTime");

					sb.append("<tr>");
					sb.append("<td class=\"table-id\">" + AdminID + "</td>");

					sb.append("<td>" + AdminName + "</td>");
					sb.append("<td class=\"table-title\">" + AdminPwd + "</td>");
					sb.append("<td class=\"table-title\">" + LastLoginTime + "</td>");
					sb.append("</tr>");

					rs.next();
					i++;
				}
				sb.append(utils.Page(sPage, rs, intPage, intPageSize));
			}
			rs.close();
			stmt.close();
			Conn.close();
			return sb.toString();
		} catch (Exception e) {
			return "No";
		}
	}
}