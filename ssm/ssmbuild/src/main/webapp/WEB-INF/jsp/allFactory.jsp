<%--
  Created by IntelliJ IDEA.
  User: HP
  Date: 2021/5/22
  Time: 17:22
  To change this template use File | Settings | File Templates.
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>工厂列表</title>
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
                    <small>工厂列表 —— 显示所有工厂</small>
                </h1>
            </div>
        </div>
    </div>

    <div class="row">
        <div class="col-md-4 column">
            <a class="btn btn-primary" href="${pageContext.request.contextPath}">返回主界面</a><br><br><br>
        </div>
    </div>


    <div class="row clearfix">
        <div class="col-md-12 column">
            <table class="table table-hover table-striped">
                <thead>
                <tr>
                    <th>工厂名</th>
                    <th>工厂法人</th>
                    <th>工厂联系电话</th>
                    <th>工厂位置</th>
                </tr>
                </thead>

                <tbody>
                <c:forEach var="factory" items="${requestScope.get('list')}">
                    <tr>
                        <td>
                            <a href="${pageContext.request.contextPath}/factory/searchDepartment">${factory.getFname()}</a>
                        </td>
                        <td>${factory.getLegal_person()}</td>
                        <td>${factory.getFphoneNumber()}</td>
                        <td>${factory.getFlocation()}</td>
                    </tr>
                </c:forEach>
                </tbody>
            </table>
        </div>
    </div>
</div>
</body>
</html>
