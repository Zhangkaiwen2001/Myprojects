package com.edu.dao;

import com.edu.pojo.Departments;
import com.edu.pojo.Leaders;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface LeaderMapper {
    //增加一个Leader
    int addLeader(Leaders departments);
    //根据no删除一个Leader
    int deleteLeaderByNo(@Param("Lno")String no);
    //根据no查询,返回一个Leader
    Leaders queryLeaderByNo(@Param("Lno")String no);
    //更新Leader
    int updateLeader(Leaders leader);
    //查询全部Leader,返回list集合
    List<Leaders> queryAllLeader();
}
