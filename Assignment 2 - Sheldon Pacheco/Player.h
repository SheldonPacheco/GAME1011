#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Player : public GameObject {
public:
    Player() : name("No Player"), health(0), role("No Role"), race("No Race"), specialAttackDamage(0), normalAttackDamage(0), battleWins(0), level(1), exp(0) {}
    string GetName() const {
        return name;
    }
    int GetHealth() const {
        return health;
    }
    string GetRole() const {
        return role;
    }
    int GetLevel() const {
        return level;
    }
    int GetExp() const {
        return exp;
    }
    void SetName(const string& name) {
        this->name = name;
    }
    void SetHealth(int health) {
        this->health = health;
    }
    void SetWins(const int&battleWins) {
        this->battleWins = battleWins;
    }
    void SetExp(int exp) {
        this->exp += exp;
        CheckLevelUp(); //level up player if goal reached
    }
    void SetLevel(const int& level) {
        this->level = level;
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
    void CheckLevelUp() {
        if (GetExp() >= GetLevel() * 100) {
            SetLevel(GetLevel() + 1);
            cout << GetName() << " the " << GetRole() << " Leveled up!!\n";
        }
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
    virtual void SetNormalAttackDamage(int normalAttackDamage) {
        this->normalAttackDamage = normalAttackDamage;
    }
    virtual void SetSpecialAttackDamage(int specialAttackDamage) {
        this->specialAttackDamage = specialAttackDamage;
    }
    virtual void SpecialAttack() = 0;
    virtual void Serialize(std::ostream& os) const = 0;
    virtual void Deserialize(std::istream& is) = 0;
    friend ostream& operator<<(ostream& output, const Player& player) {
        output << "Player Name: " << player.name << "\n";
        output << "Role: " << player.role << "\n";
        output << "Race: " << player.race << "\n";
        output << "Health: " << player.health << "\n";
        output << "Wins: " << player.battleWins << "\n";
        output << "Level: " << player.level << " (exp: " << player.exp << ", needed to level up: " << player.level * 100 - player.exp <<") \n";
        return output;
    }
    string role;
    string race;
    string name;
    int health;
    int battleWins;
    int level;
    int exp;
    int specialAttackDamage;
    int normalAttackDamage;
private:   

};
class Wizard : public Player {
public:
    string specialAttackName = "Ice bolt";
    int specialAttackDamage;
    int normalAttackDamage;
    Wizard() {
        SetHealth(90 + GetLevel() * rand() % 10 + 10),SetSpecialAttackDamage(0), SetSpecialAttackDamage(0);
    }
    int GetNormalAttackDamage() const override {
        return normalAttackDamage;
    }

    int GetSpecialAttackDamage() const override {
        return specialAttackDamage;
    }
    void SetNormalAttackDamage(int normalAttackDamage) override {
        this->normalAttackDamage = normalAttackDamage;
    }
    void SetSpecialAttackDamage(int specialAttackDamage) override {
        this->specialAttackDamage = specialAttackDamage;
    }

    void NormalAttack() override {
        normalAttackDamage = GetLevel() * rand() % 10 + 15; //scale damage 
        cout << "Wizard: slams with staff | dealing: " << normalAttackDamage << " damage" << "\n";
    }

    void SpecialAttack() override {
        specialAttackDamage = GetLevel() * rand() % 10 + 40; //scale damage 
        cout << "Wizard: casts " << specialAttackName << " | dealing: " << specialAttackDamage << " damage" << "\n";
    }
    void Serialize(std::ostream& os) const override {
        os << role << " " << name << " " << race << " " << battleWins << " " << level << " " << exp << " ";
    }

    void Deserialize(std::istream& is) override {
        is >> role >> name >> race >> battleWins >> level >> exp;
    }
};
class Knight : public Player {
public:
    string specialAttackName = "Bunt";
    int specialAttackDamage;
    int normalAttackDamage;
    Knight() {
        SetHealth(120 + GetLevel() * rand() % 10 + 10), SetSpecialAttackDamage(0), SetSpecialAttackDamage(0);
    }
    int GetNormalAttackDamage() const override {
        return normalAttackDamage;
    }

    int GetSpecialAttackDamage() const override {
        return specialAttackDamage;
    }
    void SetNormalAttackDamage(int normalAttackDamage) {
        this->normalAttackDamage = normalAttackDamage;
    }
    void SetSpecialAttackDamage(int specialAttackDamage) {
        this->specialAttackDamage = specialAttackDamage;
    }
    void NormalAttack() override {
        normalAttackDamage = GetLevel() * rand() % 10 + 20; //scale damage 
        cout << "Knight: swings sword | dealing: " << normalAttackDamage << " damage" << "\n";
    }

    void SpecialAttack() override {
        specialAttackDamage = GetLevel() * rand() % 10 + 30; //scale damage 
        cout << "Knight: uses " << specialAttackName << " with shield" << " | dealing: " << specialAttackDamage << " damage" << "\n";
    }
    void Serialize(std::ostream& os) const override {
        os << role << " " << name << " " << race << " " << battleWins << " " << level << " " << exp << " ";
    }

    void Deserialize(std::istream& is) override {
        is >> role >> name >> race >> battleWins >> level >> exp;
    }
};
#endif 
