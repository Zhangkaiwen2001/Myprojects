package com.edu.service;

import com.edu.dao.DepartmentMapper;
import com.edu.pojo.Departments;
import com.edu.pojo.Employees;
import com.edu.pojo.Leaders;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class DepartmentServiceImpl implements DepartmentService {
    //调用dao层的操作，设置一个set接口，方便Spring管理
    private DepartmentMapper departmentMapper;

    public void setDepartmentMapper(DepartmentMapper departmentMapper) {
        this.departmentMapper = departmentMapper;
    }

    public int addDepartment(Departments department) {
        return departmentMapper.addDepartment(department);
    }

    public int deleteDepartmentByNo(String no) {
        return departmentMapper.deleteDepartmentByNo(no);
    }

    public int updateDepartment(Departments department) {
        return departmentMapper.updateDepartment(department);
    }

    public Departments queryDepartmentByNo(String no) {
        return departmentMapper.queryDepartmentByNo(no);
    }

    public List<Departments> queryAllDepartment() {
        return departmentMapper.queryAllDepartment();
    }

    public Departments queryDepartmentByName(String departmentName){ return departmentMapper.queryDepartmentByName(departmentName);}

    public Leaders searchLeaderName(String no){return departmentMapper.searchLeaderName(no);}

    public List<Employees> searchEmployee(String no){return departmentMapper.searchEmployee(no);}
}
