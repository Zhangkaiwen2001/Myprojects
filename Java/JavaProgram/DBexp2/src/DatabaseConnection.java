import java.util.Scanner;
import java.sql.*;

public class DatabaseConnection
{
    public static void main(String args[]) {
        String connectionUrl= "jdbc:mysql://rm-bp1oo27t8762xhlob0o.mysql.rds.aliyuncs.com:3306/rds_mysql_15202iha";

        ResultSet resultSet;

        try (Connection connection=DriverManager.getConnection(connectionUrl,"lab_1153104193","e222500ba6a6_#@Aa");
             Statement statement = connection.createStatement()) {
            /* 1.
            Scanner in = new Scanner(System.in);
            System.out.println("请输入你要查询的参加项目号员工的项目号：");
            String PNO = in.nextLine();

            PreparedStatement ps1 = connection.prepareStatement("SELECT ENAME FROM `e2_employee`\n" +
                    "WHERE ESSN IN \n" +
                    "(SELECT ESSN FROM `e2_works_on` WHERE PNO = ?);");
            ps1.setString(1,PNO);

            resultSet = ps1.executeQuery();
            while (resultSet.next()) {
                // 输出courses表中的name字段
                System.out.println(resultSet.getString("ENAME"));
            }
             */

            /* 2.
            Scanner in = new Scanner(System.in);
            System.out.println("请输入你要查询的参加项目员工的项目名：");
            String PNAME = in.nextLine();

            PreparedStatement ps2 = connection.prepareStatement("SELECT ENAME FROM `e2_employee`" +
                    "WHERE ESSN IN \n" +
                    "(SELECT ESSN FROM `e2_works_on` WHERE `PNO` IN ( SELECT `PNO` FROM `project` WHERE `PNAME` = ?));");
            ps2.setString(1,PNAME);

            resultSet = ps2.executeQuery();
            while (resultSet.next()) {
                // 输出courses表中的name字段
                System.out.println(resultSet.getString("ENAME"));
            }
            */

            /* 3.
            Scanner in = new Scanner(System.in);
            System.out.println("请输入你要查询的在部门工作的部门名：");
            String DNAME = in.nextLine();

            PreparedStatement ps3 = connection.prepareStatement("SELECT ENAME, ADDRESS FROM `e2_employee` WHERE `DNO` IN \n" +
                    "( SELECT `DNO` FROM `department` WHERE `DNAME` = ?);\n");
            ps3.setString(1,DNAME);

            resultSet = ps3.executeQuery();
            while (resultSet.next()) {
                // 输出courses表中的name字段
                System.out.println(resultSet.getString("ENAME"));
                System.out.println(resultSet.getString("ADDRESS"));
            }
             */

             /* 4.
            Scanner in = new Scanner(System.in);
            System.out.println("请输入你要查询的在部门工作的部门名：");
            String DNAME = in.nextLine();
            System.out.println("请输入你要查询者工资的上限：");
            int SALARY = in.nextInt();

            PreparedStatement ps4 = connection.prepareStatement("SELECT ENAME, ADDRESS FROM `e2_employee` WHERE `DNO` IN \n" +
                    "( SELECT `DNO` FROM `e2_department` WHERE `DNAME` = ?  AND `SALARY` < ? );\n");
            ps4.setString(1,DNAME);
            ps4.setInt(2,SALARY);

            resultSet = ps4.executeQuery();
            while (resultSet.next()) {
                // 输出courses表中的name字段
                System.out.println(resultSet.getString("ENAME"));
                System.out.println(resultSet.getString("ADDRESS"));
            }
             */

            ///* 5.
            Scanner in = new Scanner(System.in);
            System.out.println("请输入你要查询的不在项目工作员工的项目名：");
            String PNO = in.nextLine();

            PreparedStatement ps5 = connection.prepareStatement("SELECT ENAME FROM `e2_employee` \n" +
                    "WHERE `ESSN` NOT IN \n" +
                    "( SELECT `ESSN` FROM `e2_works_on` WHERE `PNO` = ?);");
            ps5.setString(1,PNO);

            resultSet = ps5.executeQuery();
            while (resultSet.next()) {
                // 输出courses表中的name字段
                System.out.println(resultSet.getString("ENAME"));
            }
            //*/

            /* 6.
            Scanner in = new Scanner(System.in);
            System.out.println("请输入你要查询的领导工作员工的领导名：");
            String ENAME = in.nextLine();

            PreparedStatement ps6 = connection.prepareStatement("SELECT ENAME, DNAME FROM `e2_employee` JOIN `e2_department` USING(DNO)\n" +
                    "WHERE `ESSN` IN( SELECT `ESSN` FROM `e2_works_on` WHERE `PNO` IN \n" +
                    " ( SELECT `PNO` FROM `e2_project` WHERE `DNO` IN \n" +
                    " ( SELECT `DNO` FROM `e2_department` WHERE `MGRSSN` IN \n" +
                    " ( SELECT `ESSN` FROM `e2_employee` WHERE `ENAME` = ?)))); ");
            ps6.setString(1,ENAME);

            resultSet = ps6.executeQuery();
            while (resultSet.next()) {
                // 输出courses表中的name字段
                System.out.println(resultSet.getString("ENAME"));
                System.out.println(resultSet.getString("DNAME"));
            }
            */

            /* 7.
            Scanner in = new Scanner(System.in);
            System.out.println("请输入你要查询的参加项目的项目名1：");
            String PNO1 = in.nextLine();
            System.out.println("请输入你要查询的参加项目的项目名2：");
            String PNO2 = in.nextLine();

            PreparedStatement ps7 = connection.prepareStatement("SELECT ESSN FROM `e2_works_on` WHERE `PNO` = ?\n" +
                    "AND `ESSN` IN \n" +
                    "( SELECT `ESSN` FROM `e2_works_on` WHERE `PNO` = ?)\n");
            ps7.setString(1,PNO1);
            ps7.setString(2,PNO2);

            resultSet = ps7.executeQuery();
            while (resultSet.next()) {
                // 输出courses表中的name字段
                System.out.println(resultSet.getString("ESSN"));
            }
            */

            /* 8.
            Scanner in = new Scanner(System.in);
            System.out.println("请输入你要查询平均部门工资上限：");
            int SALARY = in.nextInt();

            PreparedStatement ps8 = connection.prepareStatement("SELECT DNAME FROM `e2_department` WHERE `DNO` IN \n" +
                    "( SELECT `DNO` FROM `e2_employee` GROUP BY `DNO` HAVING avg( `SALARY`) < ?);  ");
            ps8.setInt(1,SALARY);

            resultSet = ps8.executeQuery();
            while (resultSet.next()) {
                // 输出courses表中的name字段
                System.out.println(resultSet.getString("DNAME"));
            }
            */

            /* 9.
            Scanner in = new Scanner(System.in);
            System.out.println("请输入你要查询员工至少参加项目数：");
            int COUNT_P = in.nextInt();
            System.out.println("请输入你要查询员工工作时间上限：");
            int TIME = in.nextInt();

            PreparedStatement ps9 = connection.prepareStatement("SELECT ENAME FROM `e2_employee` WHERE `ESSN` IN \n" +
                    "( SELECT `ESSN` FROM `e2_works_on` GROUP BY `ESSN` HAVING COUNT( `PNO`) > ? AND SUM( `HOURS_PER_WEEK`) < ?);");
            ps9.setInt(1,COUNT_P);
            ps9.setInt(2,TIME);

            resultSet = ps9.executeQuery();
            while (resultSet.next()) {
                // 输出courses表中的name字段
                System.out.println(resultSet.getString("ENAME"));
            }
            */
        }
        catch (SQLException e) {
            e.printStackTrace();
        }
    }
}