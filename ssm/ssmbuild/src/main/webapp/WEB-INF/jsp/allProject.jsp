<%--
  Created by IntelliJ IDEA.
  User: HP
  Date: 2021/5/22
  Time: 15:36
  To change this template use File | Settings | File Templates.
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>项目列表</title>
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
                    <small>项目列表 —— 显示项目</small>
                </h1>
            </div>
        </div>
    </div>

    <div class="row">
        <div class="col-md-4 column">
            <a class="btn btn-primary" href="${pageContext.request.contextPath}">返回主界面</a><br><br><br>
            <a class="btn btn-primary" href="${pageContext.request.contextPath}/project/toAddProject">新增</a><br><br><br>
            <a class="btn btn-primary" href="${pageContext.request.contextPath}/project/allProject">显示全部项目</a><br><br><br>
        </div>
    </div>


    <div class="row clearfix">
        <div class="col-md-12 column">
            <table class="table table-hover table-striped">
                <thead>
                <tr>
                    <th>项目号</th>
                    <th>项目名称</th>
                    <th>项目预算</th>
                    <th>项目开工时间</th>
                    <th>部门号</th>
                    <th>操作</th>
                </tr>
                </thead>

                <tbody>
                <c:forEach var="project" items="${requestScope.get('list')}">
                    <tr>
                        <td>${project.getPno()}</td>
                        <td>${project.getPname()}</td>
                        <td>${project.getBudget()}</td>
                        <td>${project.getWork_time()}</td>
                        <td>${project.getDno()}</td>
                        <td>
                            <a href="${pageContext.request.contextPath}/project/toUpdateProject?no=${project.getPno()}">更改</a> |
                            <a href="${pageContext.request.contextPath}/project/del/${project.getPno()}">删除</a>
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
