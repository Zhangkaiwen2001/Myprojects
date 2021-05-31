<%--
  Created by IntelliJ IDEA.
  User: HP
  Date: 2021/5/22
  Time: 11:49
  To change this template use File | Settings | File Templates.
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<html>
<head>
    <title>新增员工</title>
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
                    <small>新增员工</small>
                </h1>
            </div>
        </div>
    </div>
    <form action="${pageContext.request.contextPath}/employee/addEmployee" method="post">
        员工编号：<input type="text" name="Eno" required><br><br><br>
        员工姓名：<input type="text" name="Ename" required><br><br><br>
        员工年龄：<input type="text" name="Eage" required><br><br><br>
        员工薪资：<input type="text" name="Esalary" required><br><br><br>
        员工居住地：<input type="text" name="Eaddress" required><br><br><br>
        员工所在部门：<input type="text" name="Dno" required><br><br><br>
        <input type="submit" value="添加">
    </form>

</div>

</body>
</html>
