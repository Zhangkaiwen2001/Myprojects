package com.edu.dao;

import com.edu.pojo.Warehouses;

import java.util.List;

public interface WarehouseMapper {
    //查询全部Warehouse,返回list集合
    List<Warehouses> queryAllWarehouses();
}
