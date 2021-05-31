<%--
  Created by IntelliJ IDEA.
  User: HP
  Date: 2021/5/31
  Time: 17:16
  To change this template use File | Settings | File Templates.
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>工作信息列表</title>
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
                    <small>工作信息列表 —— 显示所有工作信息</small>
                </h1>
            </div>
        </div>
    </div>

    <div class="row">
        <div class="col-md-4 column">
            <a class="btn btn-primary" href="${pageContext.request.contextPath}">返回主界面</a><br><br><br>
        </div>
    </div>

    <div class="row">
        <div class="col-md-4 column">
            <%--根据名称查询部门--%>
            <form action="${pageContext.request.contextPath}/work/queryEmployee" method="post">
                <input type="text" name="queryEmployeeTime" class="form-control" placeholder="请输入工作时长下限">
                <input type="submit" value="查询" class="btn btn-primary"><br><br><br>
            </form>
        </div>
    </div>

    <div class="row clearfix">
        <div class="col-md-12 column">
            <table class="table table-hover table-striped">
                <thead>
                <tr>
                    <th>项目号</th>
                    <th>员工号</th>
                    <th>工作时长</th>
                </tr>
                </thead>

                <tbody>
                <c:forEach var="work" items="${requestScope.get('list')}">
                    <tr>
                        <td>
                            <a href="${pageContext.request.contextPath}/work/searchProject/${work.getPno()}">${work.getPno()}</a>
                        </td>
                        <td>
                            <a href="${pageContext.request.contextPath}/work/searchEmployee/${work.getEno()}">${work.getEno()}</a>
                        </td>
                        <td>${work.getHours()}</td>
                    </tr>
                </c:forEach>
                </tbody>
            </table>
        </div>
    </div>
</div>
</body>
</html>

