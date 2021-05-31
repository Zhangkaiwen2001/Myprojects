package com.edu.service;

import com.edu.dao.FactoryMapper;
import com.edu.pojo.Departments;
import com.edu.pojo.Factorys;
import com.edu.pojo.Leaders;

import java.util.List;

public class FactoryServiceImpl implements FactoryService {
    private FactoryMapper factoryMapper;

    public void setFactoryMapper(FactoryMapper factoryMapper) {
        this.factoryMapper = factoryMapper;
    }

    public List<Factorys> queryAllFactory() {
        return factoryMapper.queryAllFactory();
    }
    //查询部门
    public List<Departments> searchDepartment() {return factoryMapper.searchDepartment();}
}
