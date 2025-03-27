#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    string characterID, name, weaponType;
    int level, healthPoints;
public:
    Character(string id, string n, int lvl, int hp, string weapon = "")
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}
    virtual void attack() { cout << name << " attacks with " << (weaponType.empty() ? "bare hands" : weaponType) << "!" << endl; }
    virtual void defend() { cout << name << " defends!" << endl; }
    virtual void displayStats() {
        cout << "Character ID: " << characterID << "\nName: " << name << "\nLevel: " << level
             << "\nHealth: " << healthPoints;
        if (!weaponType.empty()) cout << "\nWeapon: " << weaponType;
        cout << endl;
    }
};

class Warrior : public Character {
    int armorStrength, meleeDamage;
public:
    Warrior(string id, string n, int lvl, int hp, string weapon, int armor, int damage)
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}
    void attack() override { cout << name << " swings " << weaponType << " dealing " << meleeDamage << " damage!" << endl; }
};

class Mage : public Character {
    int manaPoints, spellPower;
public:
    Mage(string id, string n, int lvl, int hp, int mana, int spell, string weapon = "Staff")
        : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(spell) {}
    void defend() override { cout << name << " conjures a magical barrier absorbing " << spellPower << " damage!" << endl; }
};

class Archer : public Character {
    int arrowCount, rangedAccuracy;
public:
    Archer(string id, string n, int lvl, int hp, int arrows, int accuracy, string weapon = "Bow")
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}
    void attack() override {
        if (arrowCount > 0) {
            cout << name << " fires an arrow with " << rangedAccuracy << "% accuracy!" << endl;
            arrowCount--;
        } else {
            cout << name << " has no arrows left!" << endl;
        }
    }
};

class Rogue : public Character {
    int stealthLevel, agility;
public:
    Rogue(string id, string n, int lvl, int hp, int stealth, int agi, string weapon = "Dagger")
        : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agi) {}
    void displayStats() override {
        Character::displayStats();
        cout << "\nStealth Level: " << stealthLevel << "\nAgility: " << agility << endl;
    }
};

int main() {
    Warrior warrior("W001", "Thor", 10, 150, "Greatsword", 50, 40);
    Mage mage("M001", "Merlin", 12, 100, 200, 60);
    Archer archer("A001", "Legolas", 8, 120, 15, 90);
    Rogue rogue("R001", "Ezio", 9, 110, 80, 95);
    
    warrior.attack();
    mage.defend();
    archer.attack();
    rogue.displayStats();
    
    return 0;
}
