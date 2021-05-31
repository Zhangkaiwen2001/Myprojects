<%--
  Created by IntelliJ IDEA.
  User: HP
  Date: 2021/5/22
  Time: 15:47
  To change this template use File | Settings | File Templates.
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<html>
<head>
    <title>新增项目</title>
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
                    <small>新增项目</small>
                </h1>
            </div>
        </div>
    </div>
    <form action="${pageContext.request.contextPath}/project/addProject" method="post">
        项目号：<input type="text" name="Pno" required><br><br><br>
        项目名称：<input type="text" name="Pname" required><br><br><br>
        项目预算：<input type="text" name="budget" required><br><br><br>
        项目开工时间：<input type="text" name="work_time" required><br><br><br>
        部门号：<input type="text" name="Dno" required><br><br><br>
        <input type="submit" value="添加">
    </form>

</div>

</body>
</html>
