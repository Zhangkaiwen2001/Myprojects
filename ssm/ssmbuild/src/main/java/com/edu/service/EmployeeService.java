package com.edu.service;

import com.edu.pojo.Employees;

import java.util.List;

public interface EmployeeService {
    //增加一个Employee
    int addEmployee(Employees employees);
    //根据no删除一个Employee
    int deleteEmployeeByNo(String no);
    //更新Employee
    int updateEmployee(Employees employees);
    //根据no查询,返回一个Employee
    Employees queryEmployeeByNo(String no);
    //查询全部Employee,返回list集合
    List<Employees> queryAllEmployee();

}
