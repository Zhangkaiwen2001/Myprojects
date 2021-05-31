package com.edu.dao;

import com.edu.pojo.Employees;
import com.edu.pojo.Projects;
import com.edu.pojo.Works;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface WorkMapper {
    //查询全部Works,返回list集合
    List<Works> queryAllWorks();
    //根据工作时间分组选取工作人员
    List<Employees> queryEmployeeByTime(int time);
    //查询部门人员
    List<Employees> searchEmployee(@Param("Eno") String no);
    //查询项目
    List<Projects> searchProject(@Param("Pno") String no);
}
