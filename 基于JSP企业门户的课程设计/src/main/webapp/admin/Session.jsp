<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ page import="com.mingrisoft.utils.Utils"%>
<%
	Utils utils = new Utils();
	boolean isLogin = utils.StringToBoolean((String) session.getAttribute("Login"));
	if (!isLogin) {
		out.print("<script>alert('请重新登录!');location.href='login.jsp';</script>");
	}
%>