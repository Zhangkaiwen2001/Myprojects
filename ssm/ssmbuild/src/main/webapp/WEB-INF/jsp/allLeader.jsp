<%--
  Created by IntelliJ IDEA.
  User: HP
  Date: 2021/5/19
  Time: 22:27
  To change this template use File | Settings | File Templates.
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>部门主管列表</title>
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
                    <small>部门主管列表 —— 显示部门主管</small>
                </h1>
            </div>
        </div>
    </div>

    <div class="row">
        <div class="col-md-4 column">
            <a class="btn btn-primary" href="${pageContext.request.contextPath}">返回主界面</a><br><br><br>
            <a class="btn btn-primary" href="${pageContext.request.contextPath}/leader/toAddLeader">新增</a><br><br><br>
            <a class="btn btn-primary" href="${pageContext.request.contextPath}/leader/allLeader">显示全部部门主管</a><br><br><br>
        </div>
    </div>


    <div class="row clearfix">
        <div class="col-md-12 column">
            <table class="table table-hover table-striped">
                <thead>
                <tr>
                    <th>部门主管号</th>
                    <th>部门主管名字</th>
                    <th>部门主管年龄</th>
                    <th>操作</th>
                </tr>
                </thead>

                <tbody>
                <c:forEach var="leader" items="${requestScope.get('list')}">
                    <tr>
                        <td>${leader.getLno()}</td>
                        <td>${leader.getLname()}</td>
                        <td>${leader.getLage()}</td>
                        <td>
                            <a href="${pageContext.request.contextPath}/leader/toUpdateLeader?no=${leader.getLno()}">更改</a> |
                            <a href="${pageContext.request.contextPath}/leader/del/${leader.getLno()}">删除</a>
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

