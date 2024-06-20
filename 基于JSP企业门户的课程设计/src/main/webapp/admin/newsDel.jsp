<%@ page contentType="text/html; charset=UTF-8" language="java"
	buffer="32kb"%>
<%@ page import="com.mingrisoft.news.News"%>
<meta http-equiv="Content-Language" content="zh-cn">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<%
	News News = new News();//引入新闻方法类
	//从页面请求中获取新闻ID
	String newsID = request.getParameter("NewsID");
	if (News.DelNews(newsID))//判断返回值
		out.print("<script>alert('删除新闻成功!');location.href='news.jsp';</script>");//页面输出
	else //否则
		out.print("<script>alert('删除新闻失败!');location.href='news.jsp';</script>");//页面输出
%>
