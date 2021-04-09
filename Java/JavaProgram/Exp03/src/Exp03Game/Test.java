package Exp03Game;

public class Test {
    public static void main(String args[]){
        Character cha1;
        Character cha2;
        Character cha3;
        Character cha4;
        cha1 = new King();
        cha1.fight();
        cha1.setWeapon(new KnifeBehavior());
        System.out.println("更换武器...");
        cha1.fight();
        System.out.println("======================");
        cha2 = new Queen();
        cha2.fight();
        cha2.setWeapon(new KnifeBehavior());
        System.out.println("更换武器...");
        cha2.fight();
        System.out.println("======================");
        cha3 = new Knight();
        cha3.fight();
        cha3.setWeapon(new SwordBehavior());
        System.out.println("更换武器...");
        cha3.fight();
        System.out.println("======================");
        cha4 = new Troll();
        cha4.fight();
        cha4.setWeapon(new SwordBehavior());
        System.out.println("更换武器...");
        cha4.fight();
    }
}
