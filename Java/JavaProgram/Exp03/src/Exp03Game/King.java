package Exp03Game;

public class King extends Character{
    public void fight(){
        System.out.println("fighting with King");
        this.getWeapon().useWeapon();
    }
    public King(){
        setWeapon(new SwordBehavior());
    }
}

