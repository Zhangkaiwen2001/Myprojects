package com.edu.service;

import com.edu.pojo.Projects;

import java.util.List;

public interface ProjectService {
    //增加一个Project
    int addProject(Projects projects);
    //根据no删除一个Project
    int deleteProjectByNo(String no);
    //更新Project
    int updateProject(Projects projects);
    //根据no查询,返回一个Project
    Projects queryProjectByNo(String no);
    //查询全部Project,返回list集合
    List<Projects> queryAllProject();
}
