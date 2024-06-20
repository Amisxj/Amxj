<%@ page contentType="text/html; charset=utf-8" language="java"%>
<%@ page import="com.mingrisoft.news.News"%>
<%@ include file="Session.jsp"%>
<%
    request.setCharacterEncoding("utf-8");//设置编码方式为utf-8
	News News = new News();//引入新闻方法类
	String NewsID = request.getParameter("newsId");//从页面请求中获取编号
	String Action = request.getParameter("Action");//从页面请求中获取命令
	if (Action!=null && Action.equals("Edit"))//判断是否存在
	{
		String AdminName = (String)session.getAttribute("AdminName"); //从页面缓存中提取当前用户
		String [] news = new String[2];//定义数组
		news[0] = request.getParameter("upd_NewsTitle");//填写数组第一位
		news[1] = request.getParameter("upd_NewsContent");//填写数组二位	
		String sOK = News.EditNews(news,NewsID,AdminName);//获取方法返回值
		if (sOK.equals("Yes"))//判断返回值
		{
			out.println("<script>alert('修改新闻成功!');location.href='news.jsp';</script>");//页面输出
			return;//结束
		}
		else //否则
		{
			out.println("<script>alert('修改新闻失败!');location.href='news.jsp';</script>");//页面输出
			return;//结束
		}
	}
%>
