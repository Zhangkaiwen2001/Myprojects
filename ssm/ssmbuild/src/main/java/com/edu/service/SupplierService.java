package com.edu.service;

import com.edu.pojo.Suppliers;

import java.util.List;

public interface SupplierService {
    //查询全部Supplier,返回list集合
    List<Suppliers> queryAllSupplier();
}
