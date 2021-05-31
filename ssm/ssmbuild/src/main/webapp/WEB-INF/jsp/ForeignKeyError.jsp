<%--
  Created by IntelliJ IDEA.
  User: HP
  Date: 2021/5/22
  Time: 10:45
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <title>外键错误</title>
</head>
<body>
<script>
  function backAndFresh(){
    var url =document.referrer;
    window.location=url;
  }
  alert("存在外键冲突，无法删除");
  document.addEventListener(
          'click',
          backAndFresh()
  )
</script>

</body>
</html>
