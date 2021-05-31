package com.edu.service;

import com.edu.dao.SupplierMapper;
import com.edu.pojo.Suppliers;

import java.util.List;

public class SupplierServiceImpl implements SupplierService{
    private SupplierMapper supplierMapper;

    public void setSupplierMapper(SupplierMapper supplierMapper) {
        this.supplierMapper = supplierMapper;
    }

    public List<Suppliers> queryAllSupplier() {
        return supplierMapper.queryAllSuppliers();
    }
}
