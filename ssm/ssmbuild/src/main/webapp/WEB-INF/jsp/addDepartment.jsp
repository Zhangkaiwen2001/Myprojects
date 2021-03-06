<%--
  Created by IntelliJ IDEA.
  User: HP
  Date: 2021/5/19
  Time: 19:24
  To change this template use File | Settings | File Templates.
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<html>
<head>
    <title>新增部门</title>
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
                    <small>新增部门</small>
                </h1>
            </div>
        </div>
    </div>
    <form action="${pageContext.request.contextPath}/department/addDepartment" method="post">
        部门编号：<input type="text" name="departmentNo" required><br><br><br>
        部门名称：<input type="text" name="departmentName" required><br><br><br>
        部门主管号：<input type="text" name="leaderNo" required><br><br><br>
        部门所在工厂：<input type="text" name="factoryName" required><br><br><br>
        <input type="submit" value="添加">
    </form>

</div>

</body>
</html>
