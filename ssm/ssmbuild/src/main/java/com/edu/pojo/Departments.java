package com.edu.pojo;

//@Data  //除了有参构造，其他都有
//@AllArgsConstructor //加入有参构造，但无参没了
//@NoArgsConstructor  //加入无参
public class Departments {
    private String departmentName;
    private String departmentNo;
    private String factoryName;
    private String leaderNo;

    public String getLeaderNo() {
        return leaderNo;
    }

    public void setLeaderNo(String leaderNo) {
        this.leaderNo = leaderNo;
    }

    public String getFactoryName() {
        return factoryName;
    }

    public void setFactoryName(String factoryName) {
        this.factoryName = factoryName;
    }

    @Override
    public String toString() {
        return "Departments{" +
                "departmentNo='" + departmentNo + '\''+
                ", departmentName='" + departmentName + '\''+
                ", factoryName=" + factoryName + '\''+
                ", leaderNo='" + leaderNo + '\'' +
                '}';
    }
    public Departments() {
    }

    public Departments(String departmentNo, String departmentName ,String factoryName) {
        this.departmentNo = departmentNo;
        this.departmentName = departmentName;
        this.factoryName = factoryName;
    }
    public String getDepartmentNo() {
        return departmentNo;
    }

    public void setDepartmentNo(String departmentNo) {
        this.departmentNo = departmentNo;
    }

    public String getDepartmentName() {
        return departmentName;
    }

    public void setDepartmentName(String departmentName) {
        this.departmentName = departmentName;
    }

}
