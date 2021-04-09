package Exp03Game;

public class Queen extends Character{
    public void fight(){
        System.out.println("fighting with Queen");
        this.getWeapon().useWeapon();
    }
    public Queen(){
        setWeapon(new BowAndArrowBehavior());
    }
}