package com.edu.dao;

import com.edu.pojo.Departments;
import com.edu.pojo.Employees;
import com.edu.pojo.Leaders;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface DepartmentMapper {
    //增加一个Department
    int addDepartment(Departments departments);
    //根据no删除一个Department
    int deleteDepartmentByNo(@Param("departmentNo")String no);
    //更新Department
    int updateDepartment(Departments departments);
    //根据no查询,返回一个Department
    Departments queryDepartmentByNo(@Param("departmentNo")String no);
    //查询全部Department,返回list集合
    List<Departments> queryAllDepartment();
    //查询特定Department
    Departments queryDepartmentByName(@Param("departmentName")String departmentName);
    //查询部门主管名称
    Leaders searchLeaderName(@Param("departmentNo")String no);
    //查询部门人员
    List<Employees> searchEmployee(@Param("departmentNo") String no);
}
