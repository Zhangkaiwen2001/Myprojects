<%--
  Created by IntelliJ IDEA.
  User: HP
  Date: 2021/5/31
  Time: 16:12
  To change this template use File | Settings | File Templates.
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <title>零件列表</title>
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
          <small>零件列表 —— 显示所有零件</small>
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
          <th>零件号</th>
          <th>零件名</th>
          <th>零件价格</th>
          <th>细节</th>
        </tr>
        </thead>

        <tbody>
        <c:forEach var="part" items="${requestScope.get('list')}">
          <tr>
            <td>${part.getNo()}</td>
            <td>${part.getName()}</td>
            <td>${part.getPrice()}</td>
            <td>${part.getDetail()}</td>
          </tr>
        </c:forEach>
        </tbody>
      </table>
    </div>
  </div>
</div>
</body>
</html>
