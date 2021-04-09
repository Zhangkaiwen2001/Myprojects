package Exp03Game;

public class Troll extends Character{
    public void fight(){
        System.out.println("fighting with Troll");
        this.getWeapon().useWeapon();
    }
    public Troll(){
        setWeapon(new AxeBehavior());
    }
}