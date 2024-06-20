<%@ page language="java" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt"%>
<%@ page isELIgnored="false" %> 
<%
String path = request.getContextPath();
%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<meta http-equiv="pragma" content="no-cache" />
		<meta http-equiv="cache-control" content="no-cache" />
		<meta http-equiv="expires" content="0" />
		<meta http-equiv="keywords" content="keyword1,keyword2,keyword3" />
		<meta http-equiv="description" content="This is my page" />

		<link rel="stylesheet" type="text/css" href="<%=path %>/css/base.css" />
		<script type='text/javascript' src='<%=path %>/dwr/interface/loginService.js'></script>
		<script type='text/javascript' src='<%=path %>/dwr/engine.js'></script>
		<script type='text/javascript' src='<%=path %>/dwr/util.js'></script>
        <script language="javascript">
           function jiangchengDel(id)
           {
               if(confirm('您确定删除吗？'))
               {
                   window.location.href="<%=path %>/jiangcheng?type=jiangchengDel&id="+id;
               }
           }
           function p()
           {
              window.print();
           }
           function jiangchengAdd()
           {
                 var url="<%=path %>/admin/jiangcheng/jiangchengAdd.jsp";
				 window.location.href=url;
           }
           
           
           
           var i=0;
           function stuAll()
           {
               if(i==0)
               {
                   document.getElementById("indicator").style.display="block";
                   loginService.stuAll(callback);
                   i=1;
               }
               
           }
           function callback(data)
           {
               document.getElementById("indicator").style.display="none";
               DWRUtil.addOptions("stu_id",data,"id","xuehao");
           }
       </script>
	</head>

	<body leftmargin="2" topmargin="2" background='<%=path %>/img/allbg.gif'>
			<table width="98%" border="0" cellpadding="2" cellspacing="1" bgcolor="#D1DDAA" align="center" style="margin-top:8px">
				<tr bgcolor="#E7E7E7">
				     <td height="14" colspan="100" background="<%=path %>/img/tbg.gif">&nbsp;&nbsp;</td>
				</tr>
				<tr align="center" bgcolor="#FAFAF1" height="22">
				    <td width="20%">学生学号</td>
					<td width="20%">时间</td>
					<td width="20%">奖惩属性</td>
					<td width="20%">备注</td>
					<td width="20%">操作</td>
		        </tr>	
				<c:forEach items="${requestScope.jiangchengList}" var="jiangcheng">
				<tr align='center' bgcolor="#FFFFFF" onMouseMove="javascript:this.bgColor='red';" onMouseOut="javascript:this.bgColor='#FFFFFF';" height="22">
					<td bgcolor="#FFFFFF" align="center">
						${jiangcheng.stu_xuehao}
					</td>
					<td bgcolor="#FFFFFF" align="center">
						${jiangcheng.shijian}
					</td>
					<td bgcolor="#FFFFFF" align="center">
						${jiangcheng.shuxing}
					</td>
					<td bgcolor="#FFFFFF" align="center">
						${jiangcheng.beizhu}
					</td>
					<td bgcolor="#FFFFFF" align="center">
						   <input type="button" value="删除" onclick="jiangchengDel(${jiangcheng.id})"/>
					</td>
				</tr>
				</c:forEach>
			</table>
			
			<table width='98%'  border='0'style="margin-top:8px;margin-left: 5px;">
			  <tr>
			    <td>
			      <input type="button" value="添加" style="width: 80px;" onclick="jiangchengAdd()" />
			      <input type="button" value="打印" style="width: 80px;" onclick="p()" />
			    </td>
			  </tr>
		    </table>
		    
		    <form action="<%=path %>/jiangcheng?type=jiangchengSearch" method="post">
		    <table width='98%'  border='0'style="margin-top:8px;margin-left: 5px;">
			  <tr>
			       <td>  
	                  <select name="stu_id" id="stu_id" onclick="stuAll()">
			              <option value="0">请选择学生</option>
			          </select>
			          <select name="shuxing">
			               <option value="奖励">奖励</option>
			               <option value="惩罚">惩罚</option>
			          </select>
			          <input type="submit" value="查询"/>
			          <img id="indicator" src="<%=path %>/img/loading.gif" style="display:none"/>
	               </td>
			  </tr>
		    </table>
		    </form>
	</body>
</html>
