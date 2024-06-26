<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ page import="com.mingrisoft.news.News"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + path;
%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<meta name="viewport"
	content="width=device-width, initial-scale=1, maximum-scale=1">
<title>明日科技有限公司</title>
<link href="css/main.css" rel="stylesheet" type="text/css">
<link href="css/container.css" rel="stylesheet" type="text/css">
<link href="css/reset.css" rel="stylesheet" type="text/css">
<link href="css/screen.css" rel="stylesheet" type="text/css">
<script src="js/jquery.min.js">
	
</script>
<script src="js/tab.js">
	
</script>
</head>
<body>
	<%@ include file="common_header.jsp"%>

	<!--banner-->
	<div class="second_banner">
		<img src="img/4.gif" alt="">
	</div>
	<!--//banner-->
	<!--新闻-->
	<div class="container">
		<div class="left">
			<div class="menu_plan">
				<div class="menu_title">
					公司动态<br> <span>news of company</span>
				</div>
				<ul id="tab">
					<li><a href="#">公司新闻</a></li>
				</ul>
			</div>
		</div>
		<div class="right">
			<div class="location">
				<span>当前位置：<a href="#">公司新闻</a></span>
				<div class="brief" id="b">
					<a href="#">公司新闻</a>
				</div>
			</div>
			<div style="font-size: 14px; margin-top: 53px; line-height: 36px;">
				<div id="tab_con">
					<div id="tab_con_2" class="dis-n" style="display: none;">
						<div class="content_main">
							<%
							request.setCharacterEncoding("UTF-8");
							News news = new News();
							String newsId = request.getParameter("newsId");
							String sPage = request.getContextPath() + request.getServletPath() + "?";
							String sOK = news.FrontNewsDetail(newsId);
							if (sOK.equals("No")) {
								out.println("数据服务器出现错误！");
							} else {
								out.println(sOK);
							}
							%>
						</div>
					</div>
				</div>
			</div>
		</div>
	</div>
	<!--//新闻-->
	<!--底部-->
	<%@ include file="common_footer.jsp"%>
</body>
<!--//底部-->
<script>
	tabs("#tab", "active", "#tab_con");
</script>
</html>
