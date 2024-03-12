#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Player : public GameObject {
public:
    Player() : name("No Player"), health(0), role("No Role"), race("No Race"), specialAttackDamage(0), normalAttackDamage(0), battleWins(0) {}


    string GetName() const {
        return name;
    }

    int GetHealth() const {
        return health;
    }

    string GetRole() const {
        return role;
    }

    void SetName(const string& name) {
        this->name = name;
    }

    void SetHealth(int health) {
        this->health = health;
    }

    void SetRole(const string& role) {
        this->role = role;
    }

    string GetRace() const {
        return race;
    }

    void SetRace(const string& race) {
        this->race = race;
    }
    int GetBattleWins() const {
        return battleWins;
    }

    void IncreaseBattleWins() {
        battleWins++;
    }
    void NormalAttack() override {

        cout << "Player attacks.\n";
    }

    virtual int GetNormalAttackDamage() const {
        return normalAttackDamage;
    }

    virtual int GetSpecialAttackDamage() const {
        return specialAttackDamage;
    }

    virtual void SpecialAttack() = 0;

    friend ostream& operator<<(ostream& output, const Player& player) {
        output << "Player Name: " << player.name << "\n";
        output << "Role: " << player.role << "\n";
        output << "Race: " << player.race << "\n";
        output << "Health: " << player.health << "\n";
        output << "Wins: " << player.battleWins << "\n";
        return output;
    }

private:
    string name;
    int health;
    string role;
    string race;
    int battleWins;
    const int specialAttackDamage;
    int normalAttackDamage;
};
class Wizard : public Player {
public:
    static const string specialAttackName;
    static const int specialAttackDamage;
    static int normalAttackDamage;
    Wizard() {
        SetHealth(90);
    }
    int GetNormalAttackDamage() const override {
        return normalAttackDamage;
    }

    int GetSpecialAttackDamage() const override {
        return specialAttackDamage;
    }

    void NormalAttack() override {
        normalAttackDamage = rand() % 1 + 10;
        cout << "Wizard: slams with staff | dealing: " << normalAttackDamage << " damage" << "\n";
    }

    void SpecialAttack() override {

        cout << "Wizard: casts " << specialAttackName << " | dealing: " << specialAttackDamage << " damage" << "\n";
    }
};
class Knight : public Player {
public:
    static const string specialAttackName;
    static const int specialAttackDamage;
    static int normalAttackDamage;
    Knight() {
        SetHealth(120);
    }
    int GetNormalAttackDamage() const override {
        return normalAttackDamage;
    }

    int GetSpecialAttackDamage() const override {
        return specialAttackDamage;
    }
    void NormalAttack() override {
        normalAttackDamage = rand() % 1 + 20;
        cout << "Knight: swings sword | dealing: " << normalAttackDamage << " damage" << "\n";
    }

    void SpecialAttack() override {

        cout << "Knight: uses " << specialAttackName << " with shield" << " | dealing: " << specialAttackDamage << " damage" << "\n";
    }

};
#endif 
