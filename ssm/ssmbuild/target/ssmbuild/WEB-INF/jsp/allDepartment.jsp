<%--
  Created by IntelliJ IDEA.
  User: HP
  Date: 2021/5/18
  Time: 22:40
  To change this template use File | Settings | File Templates.
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>部门列表</title>
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
                    <small>部门列表 —— 显示所有部门</small>
                </h1>
            </div>
        </div>
    </div>

    <div class="row">
        <div class="col-md-4 column">
            <a class="btn btn-primary" href="${pageContext.request.contextPath}">返回主界面</a><br><br><br>
            <a class="btn btn-primary" href="${pageContext.request.contextPath}/department/toAddDepartment">新增</a><br><br><br>
            <a class="btn btn-primary" href="${pageContext.request.contextPath}/department/allDepartment">显示全部部门</a><br><br><br>
        </div>
    </div>

    <div class="row">
        <div class="col-md-4 column">
            <%--根据名称查询部门--%>
            <form action="${pageContext.request.contextPath}/department/queryDepartment" method="post">
                <input type="text" name="queryDepartmentName" class="form-control" placeholder="请输入要查询的部门">
                <input type="submit" value="查询" class="btn btn-primary"><br><br><br>
            </form>
        </div>
    </div>

    <div class="row clearfix">
        <div class="col-md-12 column">
            <table class="table table-hover table-striped">
                <thead>
                <tr>
                    <th>部门编号</th>
                    <th>部门名字</th>
                    <th>部门所属工厂名</th>
                    <th>部门主管号</th>
                    <th>操作</th>
                </tr>
                </thead>

                <tbody>
                <c:forEach var="department" items="${requestScope.get('list')}">
                    <tr>
                        <td>
                            <a href="${pageContext.request.contextPath}/department/searchEmployee/${department.getDepartmentNo()}">${department.getDepartmentNo()}</a>
                        </td>
                        <td>${department.getDepartmentName()}</td>
                        <td>${department.getFactoryName()}</td>
                        <td>
                            <a href="${pageContext.request.contextPath}/department/searchLeaderName/${department.getDepartmentNo()}">${department.getLeaderNo()}</a>
                        </td>
                        <td>
                            <a href="${pageContext.request.contextPath}/department/toUpdateDepartment?no=${department.getDepartmentNo()}">更改</a> |
                            <a href="${pageContext.request.contextPath}/department/del/${department.getDepartmentNo()}">删除</a>
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
