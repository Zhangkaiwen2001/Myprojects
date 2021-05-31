package com.edu.controller;

import com.edu.pojo.Suppliers;
import com.edu.service.SupplierService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.List;

@Controller
@RequestMapping("/supplier")
public class SupplierController {
    @Autowired
    @Qualifier("SupplierServiceImpl")

    private SupplierService supplierService;

    @RequestMapping("/allSupplier")
    public String list(Model model) {
        List<Suppliers> list = supplierService.queryAllSupplier();
        model.addAttribute("list", list);
        return "allSupplier";
    }
}
