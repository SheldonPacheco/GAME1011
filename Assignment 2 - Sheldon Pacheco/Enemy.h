#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include <iostream>
#include <vector>

class Enemy : public GameObject {
public:
    Enemy() : health(0), tauntDamage(0), normalAttackDamage(0), level(0), exp(0) {}
    int GetHealth() const {
        return health;
    }
    void SetHealth(int health) {
        this->health = health;
    }
    virtual int GetNormalAttackDamage() const {
        return normalAttackDamage;
    }
    virtual int GetTauntDamage() const {
        return tauntDamage;
    }
    virtual int GetLevel() const {
        return level;
    }

    virtual int GetExp() const {
        return exp;
    }
    virtual void SetLevel(int level) {
        this->level = level;
    }
    virtual void SetExp(int exp) {
        this->exp = exp;
    }
    void NormalAttack() override {
        cout << "Enemy attacks.\n";
    }
    virtual void TauntPlayer() = 0;
    virtual string GetSpeciesName() const = 0;

    friend ostream& operator<<(ostream& output, const Enemy& enemy) {
        output << "Enemy health: " << enemy.health << "\n";
        return output;
    }

private:
    int health;
    int tauntDamage;
    int normalAttackDamage;
    int level;
    int exp;
};
class Orc : public Enemy {
public:
    Orc(const string& speciesName, const vector<string>& taunts, int tauntDamage, int health, int normalAttackDamage, int level, int exp) 
        : speciesName(speciesName), taunts(taunts), tauntDamage(tauntDamage), normalAttackDamage(normalAttackDamage), level(level), exp(exp) {
        SetHealth(health);
        SetLevel(level);
        SetExp(exp);
    }
    int GetNormalAttackDamage() const override {
        return normalAttackDamage;
    }

    int GetTauntDamage() const override {

        return tauntDamage;
    }
    string GetSpeciesName() const override {

        return speciesName;
    }
    int GetLevel() const override {
        return level;
    }

    int GetExp() const override {
        return exp;
    }
    void SetLevel(int level) override {
        this->level = level;
    }
    void SetExp(int exp) override {
        this->exp = exp;
    }
    void TauntPlayer() {
        int chosenTaunt = rand() % taunts.size();
        tauntDamage = 15;
        cout << speciesName << ": uses taunt: " << taunts[chosenTaunt] << " | dealing: " << tauntDamage << " damage" << "\n";
    }
    void NormalAttack() override {
        normalAttackDamage = rand() % 10 + 10;
        cout << speciesName << ": attacks | dealing: " << normalAttackDamage << " damage" << "\n";
    }

private:
    string speciesName;
    vector<string> taunts;
    int tauntDamage;
    int normalAttackDamage;
    int level;
    int exp;
};

class Undead : public Enemy {
public:
    Undead(const string& speciesName, const vector<string>& taunts, int tauntDamage, int health, int normalAttackDamage, int level, int exp)
        : speciesName(speciesName), taunts(taunts), tauntDamage(tauntDamage), normalAttackDamage(normalAttackDamage), level(level), exp(exp) {
        SetHealth(health);
        SetLevel(level);
        SetExp(exp);
    }
    int GetNormalAttackDamage() const override {
        return normalAttackDamage;
    }
    int GetTauntDamage() const override {
        return tauntDamage;
    }
    string GetSpeciesName() const override {
        return speciesName;
    }
    int GetLevel() const override {
        return level;
    }

    int GetExp() const override {
        return exp;
    }
    void SetLevel(int level) override {
        this->level = level;
    }

    void SetExp(int exp) override {
        this->exp = exp;
    }
    void TauntPlayer() {
        int chosenTaunt = rand() % taunts.size();
        tauntDamage = 20;
        cout << speciesName << ": uses taunt: " << taunts[chosenTaunt] << " | dealing: " << tauntDamage << " damage" << "\n";
    }

    void NormalAttack() override {
        normalAttackDamage = rand() % 5 + 10;
        cout << speciesName << ": attacks | dealing: " << normalAttackDamage << " damage" << "\n";
    }

private:
    string speciesName;
    vector<string> taunts;
    int tauntDamage;
    int normalAttackDamage;
    int level;
    int exp;
};

class BigOrc : public Orc {
public:
    BigOrc() : Orc("Big Orc", { "I'm a big orc, yells at player" }, 0, 120, 0,3,30) {}
};

class SmallOrc : public Orc {
public:
    SmallOrc() : Orc("Small Orc", { "I'm a small Orc, laughs at player" }, 0, 80, 0,0,0) {}
};

class RegularOrc : public Orc {
public:
    RegularOrc() : Orc("Orc", { "I'm an Orc, pushes player " }, 0,100,0,1,15) {}
};

class Zombie : public Undead {
public:
    Zombie() : Undead("Zombie", { "rrrrrrrr, I'm a zombie, bites player" }, 0, 100, 0,1,5) {}
};

class Skeleton : public Undead {
public:
    Skeleton() : Undead("Skeleton", { "I'm a boney skeleton, haunts player" }, 0, 110, 0,2,25) {}
};

class Ghost : public Undead {
public:
    Ghost() : Undead("Ghost", { "I'm something you cant see, fears player" }, 0, 90, 0,0,0) {}
};

#endif 
