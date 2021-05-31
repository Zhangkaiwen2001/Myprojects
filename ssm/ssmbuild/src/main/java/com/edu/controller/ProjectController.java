package com.edu.controller;

import com.edu.pojo.Leaders;
import com.edu.pojo.Projects;
import com.edu.service.ProjectService;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;

import java.util.List;

@Controller
@RequestMapping("/project")
public class ProjectController {
    @Autowired
    @Qualifier("ProjectServiceImpl")

    private ProjectService projectService;
    @RequestMapping("/allProject")
    public String list(Model model) {
        List<Projects> list = projectService.queryAllProject();
        model.addAttribute("list", list);
        return "allProject";
    }

    @RequestMapping("/toAddProject")
    public String toAddPaper() {
        return "addProject";
    }

    @RequestMapping("/addProject")
    public String addPaper(Projects projects) {
        try {
            projectService.addProject(projects);
        }catch (Exception e){
            return "MainKeyError";
        }
        return "redirect:/project/allProject";
    }

    @RequestMapping("/del/{Pno}")
    public String deleteBook(@PathVariable("Pno") String Pno) {
        try{
            projectService.deleteProjectByNo(Pno);
        }catch (Exception e){
            return "ForeignKeyError";
        }
        return "redirect:/project/allProject";
    }

    @RequestMapping("/toUpdateProject")
    public String toUpdateLeader(Model model, String no) {
        Projects projects = projectService.queryProjectByNo(no);
        model.addAttribute("projects",projects);
        return "updateProject";
    }

    @RequestMapping("/updateProject")
    public String updateLeader(Model model, Projects project) {
        projectService.updateProject(project);
        Projects projects = projectService.queryProjectByNo(project.getPno());
        model.addAttribute("projects", projects);
        return "redirect:/project/allProject";
    }
}