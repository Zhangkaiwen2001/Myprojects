package com.edu.controller;

import com.edu.pojo.Employees;
import com.edu.pojo.Projects;
import com.edu.pojo.Works;
import com.edu.service.WorkService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.ArrayList;
import java.util.List;

@Controller
@RequestMapping("/work")
public class WorkController {
    @Autowired
    @Qualifier("WorkServiceImpl")

    private WorkService workService;

    @RequestMapping("/allWork")
    public String list(Model model) {
        List<Works> list = workService.queryAllWork();
        model.addAttribute("list", list);
        return "allWork";
    }

    @RequestMapping("/queryEmployee")
    public String queryEmploye(int queryEmployeeTime ,Model model) {
        List<Employees> list = workService.queryEmployeeByTime(queryEmployeeTime);
        model.addAttribute("list", list);
        return "allEmployee";
    }

    @RequestMapping("/searchEmployee/{Eno}")
    public String searchEmployee(@PathVariable("Eno") String no, Model model) {
        List<Employees> list = new ArrayList<Employees>();
        list = workService.searchEmployee(no);
        model.addAttribute("list",list);
        return "/allEmployee";
    }

    @RequestMapping("/searchProject/{Pno}")
    public String searchProject(@PathVariable("Pno") String no, Model model) {
        List<Projects> list = new ArrayList<Projects>();
        list = workService.searchProject(no);
        model.addAttribute("list",list);
        return "/allProject";
    }
}
