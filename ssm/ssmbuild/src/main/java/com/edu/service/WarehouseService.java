package com.edu.service;

import com.edu.pojo.Warehouses;

import java.util.List;

public interface WarehouseService {
    //查询全部Supplier,返回list集合
    List<Warehouses> queryAllWarehouse();
}
