package com.edu.controller;

import com.edu.pojo.Departments;
import com.edu.pojo.Leaders;
import com.edu.pojo.Employees;
import com.edu.service.DepartmentService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.PathVariable;

import java.util.ArrayList;
import java.util.List;

@Controller
@RequestMapping("/department")
public class DepartmentController {
    @Autowired
    @Qualifier("DepartmentServiceImpl")
    private DepartmentService departmentService;

    @RequestMapping("/allDepartment")
    public String list(Model model) {
        List<Departments> list = departmentService.queryAllDepartment();
        model.addAttribute("list", list);
        return "allDepartment";
    }

    @RequestMapping("/toAddDepartment")
    public String toAddPaper() {
        return "addDepartment";
    }

    @RequestMapping("/addDepartment")
    public String addPaper(Departments departments) {
        try {
            departmentService.addDepartment(departments);
        }catch (Exception e){
            return "MainKeyError";
        }
        return "redirect:/department/allDepartment";
    }

    @RequestMapping("/toUpdateDepartment")
    public String toUpdateDepartment(Model model, String no) {
        Departments departments = departmentService.queryDepartmentByNo(no);
        System.out.println(departments);
        model.addAttribute("department",departments);
        return "updateDepartment";
    }

    @RequestMapping("/updateDepartment")
    public String updateBook(Model model, Departments department) {
        System.out.println(department);
        try {
            departmentService.updateDepartment(department);
            Departments departments = departmentService.queryDepartmentByNo(department.getDepartmentNo());
            model.addAttribute("departments", departments);
        }catch (Exception e){
            return "ForeignKeyError";
        }
        return "redirect:/department/allDepartment";
    }

    @RequestMapping("/del/{departmentNo}")
    public String deleteBook(@PathVariable("departmentNo") String no) {
        try {
            departmentService.deleteDepartmentByNo(no);
        }catch (Exception e){
            return "ForeignKeyError";
        }
        return "redirect:/department/allDepartment";
    }

    @RequestMapping("/queryDepartment")
    public String queryDepartment(String queryDepartmentName,Model model) {
        Departments departments = departmentService.queryDepartmentByName(queryDepartmentName);
        List<Departments> list = new ArrayList<Departments>();
        list.add(departments);
        model.addAttribute("list", list);
        return "allDepartment";
    }

    @RequestMapping("/searchLeaderName/{departmentNo}")
    public String searchLeaderName(@PathVariable("departmentNo") String no,Model model){
        Leaders leaders = departmentService.searchLeaderName(no);
        List<Leaders> list = new ArrayList<Leaders>();
        list.add(leaders);
        model.addAttribute("list", list);
        return "/allLeader";
    }

    @RequestMapping("/searchEmployee/{departmentNo}")
    public String searchEmployee(@PathVariable("departmentNo") String no, Model model) {
        List<Employees> list = new ArrayList<Employees>();
        list = departmentService.searchEmployee(no);
        model.addAttribute("list",list);
        return "/allEmployee";
    }
}
