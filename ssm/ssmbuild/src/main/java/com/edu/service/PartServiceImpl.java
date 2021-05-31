package com.edu.service;

import com.edu.dao.PartMapper;
import com.edu.pojo.Parts;

import java.util.List;

public class PartServiceImpl implements PartService{
    private PartMapper partMapper;

    public void setPartMapper(PartMapper partMapper) {
        this.partMapper = partMapper;
    }

    public List<Parts> queryAllPart() {
        return partMapper.queryAllParts();
    }
}
