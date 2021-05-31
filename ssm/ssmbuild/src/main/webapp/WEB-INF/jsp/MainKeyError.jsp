<%--
  Created by IntelliJ IDEA.
  User: HP
  Date: 2021/5/22
  Time: 9:58
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>主键错误</title>
</head>
<body>
    <script>
        function backAndFresh(){
            var url =document.referrer;
            window.location=url;
        }
        alert("主键错误，请重新输入正确的主键（主键应该唯一）");
        document.addEventListener(
            'click',
            backAndFresh()
        )
    </script>

</body>
</html>