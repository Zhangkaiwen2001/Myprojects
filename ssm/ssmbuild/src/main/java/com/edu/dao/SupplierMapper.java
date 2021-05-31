package com.edu.dao;

import com.edu.pojo.Suppliers;

import java.util.List;

public interface SupplierMapper {
    //查询全部Suppliers,返回list集合
    List<Suppliers> queryAllSuppliers();
}
