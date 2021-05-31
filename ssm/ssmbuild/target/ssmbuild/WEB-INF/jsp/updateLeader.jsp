<%--
  Created by IntelliJ IDEA.
  User: HP
  Date: 2021/5/22
  Time: 10:57
  To change this template use File | Settings | File Templates.
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>修改信息</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <!-- 引入 Bootstrap -->
    <link href="https://cdn.bootcss.com/bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
<div class="container">

    <div class="row clearfix">
        <div class="col-md-12 column">
            <div class="page-header">
                <h1>
                    <small>修改信息</small>
                </h1>
            </div>
        </div>
    </div>

    <form action="${pageContext.request.contextPath}/leader/updateLeader" method="post">
        <input type="hidden" name="Lno" value="${leader.getLno()}"/>
        部门主管年龄：<input type="text" name="Lage" value="${leader.getLage()}"/>
        部门主管姓名：<input type="text" name="Lname" value="${leader.getLname()}"/>
        <input type="submit" value="提交"/>
    </form>

</div>
</body>
</html>
