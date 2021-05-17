import java.sql.*;

public class DBCLocal {
    public static void main(String[] args) {
        try{
            //1 加载驱动
            Class.forName("com.mysql.jdbc.Driver");

            //2 获取数据库连接
            //数据库账号
            String username="root";
            String password="root";
            //jdbc:mysql://ip地址（localhost）:3306（端口）/数据库名
            String url="jdbc:mysql://localhost:3306/crawler";
            //连接本机可以用三个‘/’简写省略ip和端口
            url="jdbc:mysql:///crawler";
            Connection con=DriverManager.getConnection(url,username,password);
            //System.out.println(con);

            //3、声明sql语句
            String sql="select * from `qunar_city`";

            //4、预编译
            PreparedStatement ps = con.prepareStatement(sql);

            //5、执行查询
            ResultSet rs = ps.executeQuery();

            //6、遍历结果取数据
            while(rs.next()){
                System.out.println(rs.getInt("id")+"-----"+rs.getString("name")+"-----"+rs.getString("url"));
            }

            //7、关闭资源
            rs.close();
            ps.close();
            con.close();
        }catch(ClassNotFoundException e){
            e.printStackTrace();
        } catch (SQLException e) {
            e.printStackTrace();
        }

    }
}
