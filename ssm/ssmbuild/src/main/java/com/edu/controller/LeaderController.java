package com.edu.controller;

import com.edu.pojo.Leaders;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import com.edu.service.LeaderService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;

import java.util.List;

@Controller
@RequestMapping("/leader")
public class LeaderController {
    @Autowired
    @Qualifier("LeaderServiceImpl")

    private LeaderService leaderService;
    @RequestMapping("/allLeader")
    public String list(Model model) {
        List<Leaders> list = leaderService.queryAllLeader();
        model.addAttribute("list", list);
        return "allLeader";
    }

    @RequestMapping("/toAddLeader")
    public String toAddPaper() {
        return "addLeader";
    }

    @RequestMapping("/addLeader")
    public String addPaper(Leaders leaders) {
        try {
            leaderService.addLeader(leaders);
        }catch (Exception e){
            return "MainKeyError";
        }
        return "redirect:/leader/allLeader";
    }

    @RequestMapping("/del/{Lno}")
    public String deleteBook(@PathVariable("Lno") String no) {
        try{
            leaderService.deleteLeaderByNo(no);
        }catch (Exception e){
            return "ForeignKeyError";
        }
        return "redirect:/leader/allLeader";
    }

    @RequestMapping("/toUpdateLeader")
    public String toUpdateLeader(Model model, String no) {
        Leaders leaders = leaderService.queryLeaderByNo(no);
        model.addAttribute("leader",leaders);
        return "updateLeader";
    }

    @RequestMapping("/updateLeader")
    public String updateLeader(Model model, Leaders leader) {
        leaderService.updateLeader(leader);
        Leaders leaders = leaderService.queryLeaderByNo(leader.getLno());
        model.addAttribute("leaders", leaders);
        return "redirect:/leader/allLeader";
    }
}
