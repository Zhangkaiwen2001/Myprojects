package com.edu.service;

import com.edu.pojo.Parts;

import java.util.List;

public interface PartService {
    //查询全部Part,返回list集合
    List<Parts> queryAllPart();
}
