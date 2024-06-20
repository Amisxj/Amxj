package com.mingrisoft.utils;

import java.sql.ResultSet;
import com.mingrisoft.db.DBConnection;

public class Utils {
	DBConnection Conn = new DBConnection();

	public String CheckReplace(String s) {
		try {
			if ((s == null) || (s.equals("")))
				return "";

			StringBuffer stringbuffer = new StringBuffer();
			for (int i = 0; i < s.length(); i++) {
				char c = s.charAt(i);
				switch (c) {
				case '"':
					stringbuffer.append("&quot;");
					break;
				case '\'':
					stringbuffer.append("&#039;");
					break;
				case '|':
					stringbuffer.append("");
					break;
				case '&':
					stringbuffer.append("&amp;");
					break;
				case '<':
					stringbuffer.append("&lt;");
					break;
				case '>':
					stringbuffer.append("&gt;");
					break;
				default:
					stringbuffer.append(c);
				}
			}

			return stringbuffer.toString().trim();
		} catch (Exception e) {
		}
		return "";
	}

	public String CheckDate(String[] s1, String[] s2) {
		boolean OK = true;
		StringBuffer sb = new StringBuffer();
		try {
			for (int i = 0; i < s1.length; i++) {
				if ((s1[i] == null) || (s1[i].equals("")) || (s1[i].equals(" "))) {
					sb.append("<li> [ " + s2[i] + " ] 不能为空!");
					OK = false;
				}
			}
			if (OK)
				return "Yes";
			return sb.toString().trim();
		} catch (Exception e) {
		}
		return "操作失败！";
	}

	public String getStrCN(String s) {

		return s;
	}

	public int StrToInt(String s) {
		try {
			return Integer.parseInt(CheckReplace(s));
		} catch (Exception e) {
		}
		return 0;
	}

	public boolean StringToBoolean(String s) {
		if ((s != null) && (s.equals("Yes")))
			return true;
		return false;
	}

	public String Page(String sPage, ResultSet rs, int intPage, int intPageSize) {
		String s = null;
		int i = 0;
		try {
			rs.last();

			int intRowCount = rs.getRow();
			int intPageCount;
			if (intRowCount % intPageSize == 0)
				intPageCount = intRowCount / intPageSize;
			else
				intPageCount = (int) Math.floor(intRowCount / intPageSize) + 1;
			if (intPageCount == 0)
				intPageCount = 1;

			if (intPage < 1)
				intPage = 1;
			if (intPage > intPageCount)
				intPage = intPageCount;

			if (intRowCount > intPageSize) {
				s = "<table class=\"am-table am-table-striped\" width=\"90%\"  border=\"0\" align=\"center\" cellpadding=\"2\" cellspacing=\"0\"><tr>";
				s = s + "<td width=\"80%\" height=\"30\" class=\"chinese\"><span class=\"chinese\">";
				s = s + "当前第" + intPage + "页/共" + intPageCount + "页,&nbsp;&nbsp;&nbsp;&nbsp;共" + intRowCount
						+ "条记录,&nbsp;&nbsp;&nbsp;&nbsp;" + intPageSize + "条/页";

				int showye = intPageCount;
				if (showye > 10)
					showye = 10;
				for (i = 1; i <= showye; i++)
					;
				s = s + "</span></td>";
				s = s + "<td width=\"20%\">";
				s = s + "<table width=\"100%\" border=\"0\">";
				s = s + "<tr><td><div align=\"right\"><span class=\"chinese\">";
				s = s + "<select id=\"ipage\" name=\"ipage\" class=\"chinese\" onChange=\"jumpMenu('self',this,0)\">";
				s = s + "<option value=\"\" selected>请选择</option>";

				for (i = 1; i <= intPageCount; i++) {
					String sSelect = i == intPage ? "SELECTED" : "";
					s = s + "<option value=\"" + sPage + "intPage=" + i + "\"" + sSelect + ">第" + i + "页</option>";
				}

				s = s + "</select></span></div>";
				s = s + "</td></tr></table>";
				return s + "</td></tr></table>";
			}

			return "";
		} catch (Exception e) {
		}
		return "分页出错!";
	}

	public String PageFront(String sPage, ResultSet rs, int intPage, int intPageSize) {
		String s = null;

		int i = 0;
		try {
			rs.last();

			int intRowCount = rs.getRow();
			int intPageCount;
			if (intRowCount % intPageSize == 0)
				intPageCount = intRowCount / intPageSize;
			else
				intPageCount = (int) Math.floor(intRowCount / intPageSize) + 1;
			if (intPageCount == 0)
				intPageCount = 1;

			if (intPage < 1)
				intPage = 1;
			if (intPage > intPageCount)
				intPage = intPageCount;

			if (intRowCount > intPageSize) {
				s = "<table  width=\"90%\"  border=\"0\" align=\"left\" cellpadding=\"2\" cellspacing=\"0\"><tr>";
				s = s + "<td style=\"text-align:left\" width=\"80%\" height=\"30\" class=\"chinese\"><span class=\"chinese\">";
				s = s + "当前第" + intPage + "页/共" + intPageCount + "页,&nbsp;&nbsp;&nbsp;&nbsp;共" + intRowCount
						+ "条记录,&nbsp;&nbsp;&nbsp;&nbsp;" + intPageSize
						+ "条/页&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";

				int showye = intPageCount;
				if (showye > 10)
					showye = 10;
				for (i = 1; i <= showye; i++) {
					if (i == intPage)
						s = s + " " + i + " ";
					else {
						s = s + "&nbsp; <a style=\"color:#3F862E\" href=\"" + sPage + "intPage=" + i + "\">" + i
								+ "</a> ";
					}
				}
				s = s + "</span></td>";

				return s + "</tr></table>";
			}

			return "";
		} catch (Exception e) {
		}
		return "分页出错!";
	}
}