package com.edu.pojo;

public class Leaders {
    private String Lno;
    private int Lage;
    private String Lname;

    @Override
    public String toString() {
        return "leaders{" +
                "Lno='" + Lno + '\''+
                ", Lage=" + Lage +
                ", Lname=" + Lname + '\''+
                '}';
    }

    public String getLno() {
        return Lno;
    }

    public String getLname() {
        return Lname;
    }

    public void setLname(String lname) {
        Lname = lname;
    }

    public void setLno(String lno) {
        Lno = lno;
    }

    public int getLage() {
        return Lage;
    }

    public void setLage(int lage) {
        Lage = lage;
    }

    public Leaders(String Lno, int Lage, String Lname) {
        this.Lno = Lno;
        this.Lage = Lage;
        this.Lname = Lname;
    }
}
