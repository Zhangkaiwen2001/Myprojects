<%--
  Created by IntelliJ IDEA.
  User: HP
  Date: 2021/5/31
  Time: 15:39
  To change this template use File | Settings | File Templates.
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>供应商列表</title>
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
                    <small>供应商列表 —— 显示所有供应商</small>
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
                    <th>供应商号</th>
                    <th>供应商名</th>
                    <th>供应商联系电话</th>
                    <th>供应商位置</th>
                </tr>
                </thead>

                <tbody>
                <c:forEach var="supplier" items="${requestScope.get('list')}">
                    <tr>
                        <td>${supplier.getSno()}</td>
                        <td>${supplier.getSname()}</td>
                        <td>${supplier.getPhoneNumber()}</td>
                        <td>${supplier.getSaddress()}</td>
                    </tr>
                </c:forEach>
                </tbody>
            </table>
        </div>
    </div>
</div>
</body>
</html>
