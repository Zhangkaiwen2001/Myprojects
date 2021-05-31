package com.edu.controller;

import com.edu.pojo.Departments;
import com.edu.pojo.Factorys;
import com.edu.service.FactoryService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.ArrayList;
import java.util.List;

@Controller
@RequestMapping("/factory")
public class FactoryController {
    @Autowired
    @Qualifier("FactoryServiceImpl")

    private FactoryService factoryService;

    @RequestMapping("/allFactory")
    public String list(Model model) {
        List<Factorys> list = factoryService.queryAllFactory();
        model.addAttribute("list", list);
        return "allFactory";
    }

    @RequestMapping("/searchDepartment")
    public String searchEmployee(Model model) {
        List<Departments> list = new ArrayList<Departments>();
        list = factoryService.searchDepartment();
        model.addAttribute("list",list);
        return "/allDepartment";
    }
}
