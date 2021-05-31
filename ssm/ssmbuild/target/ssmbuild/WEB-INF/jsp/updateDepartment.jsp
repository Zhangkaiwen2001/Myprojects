<%--
  Created by IntelliJ IDEA.
  User: HP
  Date: 2021/5/19
  Time: 19:47
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

    <form action="${pageContext.request.contextPath}/department/updateDepartment" method="post">
        <input type="hidden" name="departmentNo" value="${department.getDepartmentNo()}"/>
        部门名称：<input type="text" name="departmentName" value="${department.getDepartmentName()}"/>
        部门主管号：<input type="text" name="leaderNo" value="${department.getLeaderNo()}"/>
        部门所在工厂：<input type="text" name="factoryName" value="${department.getFactoryName()}"/>
        <input type="submit" value="提交"/>
    </form>

</div>
</body>
</html>
