package com.edu.controller;

import com.edu.pojo.Parts;
import com.edu.service.PartService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.List;

@Controller
@RequestMapping("/part")
public class PartController {
    @Autowired
    @Qualifier("PartServiceImpl")

    private PartService partService;

    @RequestMapping("/allPart")
    public String list(Model model) {
        List<Parts> list = partService.queryAllPart();
        model.addAttribute("list", list);
        return "allPart";
    }
}
