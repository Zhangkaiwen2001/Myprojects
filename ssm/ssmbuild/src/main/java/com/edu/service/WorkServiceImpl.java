package com.edu.service;

import com.edu.dao.WorkMapper;
import com.edu.pojo.Employees;
import com.edu.pojo.Projects;
import com.edu.pojo.Works;

import java.util.List;

public class WorkServiceImpl implements WorkService{
    private WorkMapper workMapper;

    public void setWorkMapper(WorkMapper workMapper) {
        this.workMapper = workMapper;
    }

    public List<Works> queryAllWork() {
        return workMapper.queryAllWorks();
    }

    public List<Employees> queryEmployeeByTime(int time){return workMapper.queryEmployeeByTime(time);}

    public List<Employees> searchEmployee(String no){return workMapper.searchEmployee(no);};

    public List<Projects> searchProject(String no){return workMapper.searchProject(no);}
}
