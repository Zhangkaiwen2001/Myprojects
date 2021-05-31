package com.edu.dao;

import com.edu.pojo.Employees;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface EmployeeMapper {
    //增加一个Employee
    int addEmployee(Employees employees);
    //根据no删除一个Employee
    int deleteEmployeeByNo(@Param("Eno")String no);
    //更新Employee
    int updateEmployee(Employees employees);
    //根据no查询,返回一个Employee
    Employees queryEmployeeByNo(@Param("Eno")String no);
    //查询全部Employee,返回list集合
    List<Employees> queryAllEmployee();
}
