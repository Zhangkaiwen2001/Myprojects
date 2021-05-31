package com.edu.dao;

import com.edu.pojo.Projects;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface ProjectMapper {
    //增加一个Project
    int addProject(Projects projects);

    //根据no删除一个Project
    int deleteProjectByNo(@Param("Pno") String Pno);

    //更新Project
    int updateProject(Projects projects);

    //根据no查询,返回一个Project
    Projects queryProjectByNo(@Param("Pno") String Pno);

    //查询全部Project,返回list集合
    List<Projects> queryAllProject();
}
