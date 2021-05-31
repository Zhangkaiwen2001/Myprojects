<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE HTML>
<html>
<head>
    <title>首页</title>
    <style type="text/css">
        a {
            text-decoration: none;
            color: black;
            font-size: 18px;
        }
        h3 {
            width: 180px;
            height: 38px;
            margin: 100px auto;
            text-align: center;
            line-height: 38px;
            background: deepskyblue;
            border-radius: 4px;
        }
    </style>
</head>
<body>
<h3>
    <a href="${pageContext.request.contextPath}/department/allDepartment">点击进入部门页</a>
</h3>
<h3>
    <a href="${pageContext.request.contextPath}/leader/allLeader">点击进入部门主管页</a>
</h3>
<h3>
    <a href="${pageContext.request.contextPath}/employee/allEmployee">点击进入员工页</a>
</h3>
<h3>
    <a href="${pageContext.request.contextPath}/project/allProject">点击进入项目页</a>
</h3>
<h3>
    <a href="${pageContext.request.contextPath}/work/allWork">点击进入工作信息页</a>
</h3>
<h3>
    <a href="${pageContext.request.contextPath}/factory/allFactory">点击进入工厂页</a>
</h3>
<h3>
    <a href="${pageContext.request.contextPath}/supplier/allSupplier">点击进入供应商页</a>
</h3>
<h3>
    <a href="${pageContext.request.contextPath}/warehouse/allWarehouse">点击进入仓库页</a>
</h3>
<h3>
    <a href="${pageContext.request.contextPath}/part/allPart">点击进入零件页</a>
</h3>
</body>
</html>
