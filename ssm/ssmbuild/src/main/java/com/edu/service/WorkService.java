package com.edu.service;

import com.edu.pojo.Employees;
import com.edu.pojo.Projects;
import com.edu.pojo.Works;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface WorkService {
    //查询全部Supplier,返回list集合
    List<Works> queryAllWork();
    //根据工作时间分组选取工作人员
    List<Employees> queryEmployeeByTime(int time);
    //查询部门人员
    List<Employees> searchEmployee(@Param("Eno") String no);
    //查询项目
    List<Projects> searchProject(@Param("Pno") String no);
}
