package com.edu.controller;


import com.edu.pojo.Employees;
import com.edu.pojo.Leaders;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import com.edu.service.EmployeeService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;


import java.util.List;

@Controller
@RequestMapping("/employee")
public class EmployeeController {
    @Autowired
    @Qualifier("EmployeeServiceImpl")

    private EmployeeService employeeService;

    @RequestMapping("/allEmployee")
    public String list(Model model) {
        List<Employees> list = employeeService.queryAllEmployee();
        model.addAttribute("list", list);
        return "allEmployee";
    }

    @RequestMapping("/toAddEmployee")
    public String toAddPaper() {
        return "addEmployee";
    }

    @RequestMapping("/addEmployee")
    public String addPaper(Employees employees) {
        try {
            employeeService.addEmployee(employees);
        }catch (Exception e){
            System.out.println(e);
            return "MainKeyError";
        }
        return "redirect:/employee/allEmployee";
    }

    @RequestMapping("/del/{Eno}")
    public String deleteBook(@PathVariable("Eno") String no) {
        try{
            employeeService.deleteEmployeeByNo(no);
        }catch (Exception e){
            System.out.println(e);
            return "ForeignKeyError";
        }
        return "redirect:/employee/allEmployee";
    }

    @RequestMapping("/toUpdateEmployee")
    public String toUpdateLeader(Model model, String no) {
        Employees employees = employeeService.queryEmployeeByNo(no);
        model.addAttribute("employee",employees);
        return "updateEmployee";
    }

    @RequestMapping("/updateEmployee")
    public String updateLeader(Model model, Employees employee) {
        employeeService.updateEmployee(employee);
        Employees employees = employeeService.queryEmployeeByNo(employee.getEno());
        model.addAttribute("employees", employees);
        return "redirect:/employee/allEmployee";
    }
}
