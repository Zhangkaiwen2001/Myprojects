package edu.hitwh.jdbc;

import java.sql.*;


/**
 * 程序的耦合
 */
public class JdbcDemo1 {
    public static void main(String[] args) throws Exception {
        //1.注册驱动
        DriverManager.registerDriver(new com.mysql.jdbc.Driver());
//        Class.forName("com.mysql.jdbc.Driver");
        //2.获取连接
        Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/eesy","root","root");
        //3.获取数据操作的预处理对象
        PreparedStatement pstm = con.prepareStatement("select  * from account");
        //4.执行sql，得到结果集
        ResultSet rs = pstm.executeQuery();
        //5.遍历结果集
        while (rs.next()){
            System.out.println(rs.getString("name"));
        }
        //6.释放资源
        rs.close();
        pstm.close();
        con.close();
    }
}
