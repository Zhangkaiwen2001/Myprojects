package com.edu.service;

import com.edu.pojo.Departments;
import com.edu.pojo.Leaders;

import java.util.List;

public interface LeaderService {
    //增加一个Leader
    int addLeader(Leaders leaders);
    //根据no删除一个Leader
    int deleteLeaderByNo(String no);
    //更新Leader
    int updateLeader(Leaders leaders);
    //查询全部Leader,返回list集合
    List<Leaders> queryAllLeader();
    //根据no查询,返回一个Leader
    Leaders queryLeaderByNo(String no);
}
