package com.edu.pojo;

public class Employees {
    private String Eno;
    private String Ename;
    private String Eaddress;
    private String Dno;
    private int Esalary;

    public int getEsalary() {
        return Esalary;
    }

    public void setEsalary(int esalary) {
        Esalary = esalary;
    }

    @Override
    public String toString() {
        return "Employees{" +
                "Eno='" + Eno + '\''+
                ", Ename='" + Ename + '\''+
                ", Eaddress='" + Eaddress + '\''+
                ", Esalary=" + Esalary +
                '}';
    }

    public String getDno() {
        return Dno;
    }

    public void setDno(String dno) {
        Dno = dno;
    }

    private int Eage;

    public String getEaddress() {
        return Eaddress;
    }

    public void setEaddress(String eaddress) {
        this.Eaddress = eaddress;
    }

    public String getEno() {
        return Eno;
    }

    public void setEno(String eno) {
        this.Eno = eno;
    }

    public String getEname() {
        return Ename;
    }

    public void setEname(String ename) {
        this.Ename = ename;
    }

    public int getEage() {
        return Eage;
    }

    public void setEage(int eage) {
        this.Eage = eage;
    }
}
