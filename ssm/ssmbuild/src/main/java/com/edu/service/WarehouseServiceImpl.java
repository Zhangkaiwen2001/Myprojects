package com.edu.service;

import com.edu.dao.WarehouseMapper;
import com.edu.pojo.Warehouses;

import java.util.List;

public class WarehouseServiceImpl implements WarehouseService{
    private WarehouseMapper warehouseMapper;

    public void setWarehouseMapper(WarehouseMapper warehouseMapper) {
        this.warehouseMapper = warehouseMapper;
    }

    public List<Warehouses> queryAllWarehouse() {
        return warehouseMapper.queryAllWarehouses();
    }

}
