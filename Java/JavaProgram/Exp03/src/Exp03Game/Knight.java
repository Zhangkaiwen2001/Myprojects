package Exp03Game;

public class Knight extends Character{
    public void fight(){
        System.out.println("fighting with Knight");
        this.getWeapon().useWeapon();
    }
    public Knight(){
        setWeapon(new KnifeBehavior());
    }
}
