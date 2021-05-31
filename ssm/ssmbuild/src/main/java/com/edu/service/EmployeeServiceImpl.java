package com.edu.service;

import com.edu.dao.EmployeeMapper;
import com.edu.pojo.Employees;

import java.util.List;

public class EmployeeServiceImpl implements EmployeeService{
    //调用dao层的操作，设置一个set接口，方便Spring管理
    private EmployeeMapper employeeMapper;

    public void setEmployeeMapper(EmployeeMapper employeeMapper) {
        this.employeeMapper = employeeMapper;
    }

    public int addEmployee(Employees employees) {
        return employeeMapper.addEmployee(employees);
    }

    public int deleteEmployeeByNo(String no) {
        return employeeMapper.deleteEmployeeByNo(no);
    }

    public int updateEmployee(Employees employees) {
        return employeeMapper.updateEmployee(employees);
    }

    public Employees queryEmployeeByNo(String no) {
        return employeeMapper.queryEmployeeByNo(no);
    }

    public List<Employees> queryAllEmployee() {
        return employeeMapper.queryAllEmployee();
    }

}
