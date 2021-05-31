package com.edu.service;

import com.edu.pojo.Departments;
import com.edu.pojo.Factorys;

import java.util.List;

public interface FactoryService {
    //查询全部Factory,返回list集合
    List<Factorys> queryAllFactory();
    //查询部门
    List<Departments> searchDepartment();
}
