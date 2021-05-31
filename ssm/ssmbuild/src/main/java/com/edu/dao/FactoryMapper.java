package com.edu.dao;

import com.edu.pojo.Departments;
import com.edu.pojo.Factorys;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface FactoryMapper {
    //查询全部Factory,返回list集合
    List<Factorys> queryAllFactory();
    //查询部门
    List<Departments> searchDepartment();
}
