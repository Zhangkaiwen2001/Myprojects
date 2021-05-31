package com.edu.service;

import com.edu.pojo.Departments;
import com.edu.pojo.Employees;
import com.edu.pojo.Leaders;

import java.util.List;

public interface DepartmentService {
    //增加一个Department
    int addDepartment(Departments departments);
    //根据no删除一个Department
    int deleteDepartmentByNo(String no);
    //更新Department
    int updateDepartment(Departments departments);
    //根据no查询,返回一个Department
    Departments queryDepartmentByNo(String no);
    //查询全部Department,返回list集合
    List<Departments> queryAllDepartment();
    //查询特定书籍
    Departments queryDepartmentByName(String departmentName);
    //查询部门主管名称
    Leaders searchLeaderName(String no);
    //查询部门人员
    List<Employees> searchEmployee(String no);
}
