package Exp03Game;

public abstract class Character {
    private WeaponBehavior weapon = null;
    public void setWeapon(WeaponBehavior weapon) {
        this.weapon = weapon;
    }
    public WeaponBehavior getWeapon() {
        return weapon;
    }
    public abstract void fight();
}