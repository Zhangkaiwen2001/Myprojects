package com.edu.dao;


import com.edu.pojo.Parts;

import java.util.List;

public interface PartMapper {
    //查询全部Factory,返回list集合
    List<Parts> queryAllParts();
}
