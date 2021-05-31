package com.edu.service;

import com.edu.dao.LeaderMapper;
import com.edu.pojo.Leaders;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class LeaderServiceImpl implements LeaderService{
    //调用dao层的操作，设置一个set接口，方便Spring管理
    private LeaderMapper leaderMapper;

    public void setLeaderMapper(LeaderMapper leaderMapper) {
        this.leaderMapper = leaderMapper;
    }

    public int addLeader(Leaders leader) {
        return leaderMapper.addLeader(leader);
    }

    public int deleteLeaderByNo(String no) {
        return leaderMapper.deleteLeaderByNo(no);
    }

    public int updateLeader(Leaders leaders) {
        return leaderMapper.updateLeader(leaders);
    }

    public List<Leaders> queryAllLeader() {
        return leaderMapper.queryAllLeader();
    }

    public Leaders queryLeaderByNo(String no){return leaderMapper.queryLeaderByNo(no);}
}
