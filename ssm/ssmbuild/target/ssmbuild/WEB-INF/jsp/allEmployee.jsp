<%--
  Created by IntelliJ IDEA.
  User: HP
  Date: 2021/5/22
  Time: 11:41
  To change this template use File | Settings | File Templates.
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>员工列表</title>
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
                    <small>员工列表 —— 显示所有员工</small>
                </h1>
            </div>
        </div>
    </div>

    <div class="row">
        <div class="col-md-4 column">
            <a class="btn btn-primary" href="${pageContext.request.contextPath}">返回主界面</a><br><br><br>
            <a class="btn btn-primary" href="${pageContext.request.contextPath}/employee/toAddEmployee">新增</a><br><br><br>
            <a class="btn btn-primary" href="${pageContext.request.contextPath}/employee/allEmployee">显示全部员工</a><br><br><br>
        </div>
    </div>


    <div class="row clearfix">
        <div class="col-md-12 column">
            <table class="table table-hover table-striped">
                <thead>
                <tr>
                    <th>员工编号</th>
                    <th>员工名字</th>
                    <th>员工年龄</th>
                    <th>员工薪资</th>
                    <th>员工居住地址</th>
                    <th>员工所在部门</th>
                    <th>操作</th>
                </tr>
                </thead>

                <tbody>
                <c:forEach var="employee" items="${requestScope.get('list')}">
                    <tr>
                        <td>${employee.getEno()}</td>
                        <td>${employee.getEname()}</td>
                        <td>${employee.getEage()}</td>
                        <td>${employee.getEsalary()}</td>
                        <td>${employee.getEaddress()}</td>
                        <td>${employee.getDno()}</td>
                        <td>
                            <a href="${pageContext.request.contextPath}/employee/toUpdateEmployee?no=${employee.getEno()}">更改</a> |
                            <a href="${pageContext.request.contextPath}/employee/del/${employee.getEno()}">删除</a>
                        </td>
                    </tr>
                </c:forEach>
                </tbody>
            </table>
        </div>
    </div>
</div>
</body>
</html>

