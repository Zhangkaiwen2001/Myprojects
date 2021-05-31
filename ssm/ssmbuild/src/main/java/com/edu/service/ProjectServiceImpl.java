package com.edu.service;

import com.edu.dao.ProjectMapper;
import com.edu.pojo.Projects;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class ProjectServiceImpl implements ProjectService{
    //调用dao层的操作，设置一个set接口，方便Spring管理
    private ProjectMapper projectMapper;

    public void setProjectMapper(ProjectMapper projectMapper) {
        this.projectMapper = projectMapper;
    }

    public int addProject(Projects projects) {
        return projectMapper.addProject(projects);
    }

    public int deleteProjectByNo(String no) {
        return projectMapper.deleteProjectByNo(no);
    }

    public int updateProject(Projects projects) {
        return projectMapper.updateProject(projects);
    }

    public List<Projects> queryAllProject() {
        return projectMapper.queryAllProject();
    }

    public Projects queryProjectByNo(String no){return projectMapper.queryProjectByNo(no);}
}
