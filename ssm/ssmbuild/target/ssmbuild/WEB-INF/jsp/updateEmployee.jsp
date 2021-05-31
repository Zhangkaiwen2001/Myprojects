<%--
  Created by IntelliJ IDEA.
  User: HP
  Date: 2021/5/22
  Time: 14:34
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

  <form action="${pageContext.request.contextPath}/employee/updateEmployee" method="post">
    <input type="hidden" name="Eno" value="${employee.getEno()}"/>
    员工姓名：<input type="text" name="Ename" value="${employee.getEname()}"/><br><br><br>
    员工年龄：<input type="text" name="Eage" value="${employee.getEage()}"/><br><br><br>
    员工薪资：<input type="text" name="Esalary" value="${employee.getEsalary()}"/><br><br><br>
    员工居住地：<input type="text" name="Eaddress" value="${employee.getEaddress()}"/><br><br><br>
    员工所在部门：<input type="text" name="Dno" value="${employee.getDno()}"/><br><br><br>
    <input type="submit" value="提交"/>
  </form>

</div>
</body>
</html>

