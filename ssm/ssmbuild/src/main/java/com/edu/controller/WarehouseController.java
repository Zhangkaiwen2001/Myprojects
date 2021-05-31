package com.edu.controller;

import com.edu.pojo.Warehouses;
import com.edu.service.WarehouseService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.List;

@Controller
@RequestMapping("/warehouse")
public class WarehouseController {
    @Autowired
    @Qualifier("WarehouseServiceImpl")

    private WarehouseService warehouseService;

    @RequestMapping("/allWarehouse")
    public String list(Model model) {
        List<Warehouses> list = warehouseService.queryAllWarehouse();
        model.addAttribute("list", list);
        return "allWarehouse";
    }
}
