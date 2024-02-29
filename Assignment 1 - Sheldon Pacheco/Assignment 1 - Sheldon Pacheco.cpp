#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ClearConsole() {
    system("cls");
}

class GameObject {
public:
    virtual void NormalAttack() = 0; 
};

class Player : public GameObject {
public:
    Player() : name("No Player"), health(0), role("No Role"), race("No Race"), specialAttackDamage(0) {}

    
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

    void NormalAttack() override {
        
        cout << "Player attacks.\n";
    }

    virtual int GetNormalAttackDamage() const {
        return rand() % 5 + 10;
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
        return output;
    }

private:
    string name;
    int health;
    string role;
    string race;
    const int specialAttackDamage;
};

class Wizard : public Player {
public:
    static const string specialAttackName;
    static const int specialAttackDamage;


    int GetNormalAttackDamage() const override {
        return rand() % 5 + 10;
    }

    int GetSpecialAttackDamage() const override {
        return specialAttackDamage;
    }

    void NormalAttack() override {
        int damage = rand() % 5 + 10;  
        cout << "Wizard slams with staff | dealing: " << damage << " damage" << "\n";
    }

    void SpecialAttack() override {
        
        cout << "Wizard casts: " << specialAttackName << " | dealing: " << specialAttackDamage << " damage" << "\n";
    }
};

const string Wizard::specialAttackName = "Ice Bolt";
const int Wizard::specialAttackDamage = 20;

class Knight : public Player {
public:
    static const string specialAttackName;
    static const int specialAttackDamage;


    int GetNormalAttackDamage() const override{
        return rand() % 5 + 30;
    }

    int GetSpecialAttackDamage() const override {
        return specialAttackDamage;
    }
    void NormalAttack() override {
        int damage = rand() % 5 + 30;  
        cout << "Knight swings sword | dealing: " << damage << " damage" << "\n";
    }

    void SpecialAttack() override {
        
        cout << "Knight uses: " << specialAttackName <<"with shield" << " dealing " << specialAttackDamage << " damage" << "\n";
    }
};

const string Knight::specialAttackName = "Bunt";
const int Knight::specialAttackDamage = 15;

class Enemy : public GameObject {
public:
    Enemy() : health(0), tauntDamage(0){}

    
    int GetHealth() const {
        return health;
    }

    void SetHealth(int health) {
        this->health = health;
    }
    virtual int GetNormalAttackDamage() const {
        return rand() % 10 + 10;  
    }

    virtual int GetTauntDamage() const {

        return tauntDamage;
    }
  
    void NormalAttack() override {
        
        cout << "Enemy attacks.\n";
    }

    virtual void TauntPlayer() = 0;  

    friend ostream& operator<<(ostream& output, const Enemy& enemy) {
        output << "Enemy health: " << enemy.health << "\n";
        return output;
    }

private:
    int health;
    int tauntDamage;
};

class Orc : public Enemy {
public:
    Orc(const string& speciesName, const vector<string>& taunts, int tauntDamage, int health) : speciesName(speciesName), taunts(taunts), tauntDamage(tauntDamage) {
        SetHealth(health);
    }
    int GetNormalAttackDamage() const override{
        return rand() % 10 + 10;  
    }

    int GetTauntDamage() const override{

        return tauntDamage;
    }
    
    void TauntPlayer() {
        
        int chosenTaunt = rand() % taunts.size();
        tauntDamage = 15;
        cout << speciesName << " Orc use taunt: " << taunts[chosenTaunt] << " | dealing: " << tauntDamage << " damage" << "\n";
        SetHealth(GetHealth() - tauntDamage);
    }

    void NormalAttack() override {
        
        int damage = rand() % 10 + 10;  
        cout << speciesName << " Orc attacks | dealing: " << damage << " damage" << "\n";
    }

private:
    string speciesName;
    vector<string> taunts;
    int tauntDamage;
};

class Undead : public Enemy {
public:
    Undead(const string& speciesName, const vector<string>& taunts, int tauntDamage, int health) : speciesName(speciesName), taunts(taunts), tauntDamage(tauntDamage) {
        SetHealth(health);
    }
    int GetNormalAttackDamage() const override {
        return rand() % 5 + 10;
    }

    int GetTauntDamage() const override{

        return tauntDamage;
    }
   
    void TauntPlayer() {
        
        int chosenTaunt = rand() % taunts.size();
        tauntDamage = 20;
        cout << speciesName << " Undead uses taunt: " << taunts[chosenTaunt] << " | dealing: " << tauntDamage << "damage" << "\n";
        SetHealth(GetHealth() - tauntDamage);
    }

    void NormalAttack() override {
        
        int damage = rand() % 5 + 10;  
        cout << speciesName << " Undead attacks | dealing: " << damage << " damage" << "\n";
    }

private:
    string speciesName;
    vector<string> taunts;
    int tauntDamage;
};

class BigOrc : public Orc {
public:
    BigOrc() : Orc("Big Orc", { "I'm a big orc, yells at player"},20, 120) {}
};

class SmallOrc : public Orc {
public:
    SmallOrc() : Orc("Small Orc", { "I'm a small Orc, laughs at player"},20, 80) {}
};

class RegularOrc : public Orc {
public:
    RegularOrc() : Orc("Orc", { "I'm an Orc, pushes player "},20, 100) {}
};

class Zombie : public Undead {
public:
    Zombie() : Undead("Zombie", { "Brrrrr, I'm a zombie, bites player"},20, 100) {}
};

class Skeleton : public Undead {
public:
    Skeleton() : Undead("Skeleton", { "I'm a boney skeleton, haunts player"},20, 110) {}
};

class Ghost : public Undead {
public:
    Ghost() : Undead("Ghost", { "I'm something you cant see, fears player"},20, 90) {}
};

class TimeToBattle {
public:
    void GoToBattle(Player* player, Enemy* enemy) {
        player->NormalAttack();
        enemy->NormalAttack();

        player->SpecialAttack();
        enemy->TauntPlayer();

        AdjustHealth(player, enemy);
    }

private:
    void AdjustHealth(Player* player, Enemy* enemy) {
        int playerDamage = player->GetNormalAttackDamage() + player->GetSpecialAttackDamage();
        int enemyDamage = enemy->GetNormalAttackDamage() + enemy->GetTauntDamage();

        player->SetHealth(player->GetHealth() - enemyDamage);
        enemy->SetHealth(enemy->GetHealth() - playerDamage);

        cout << "Player's hp after battle: " << player->GetHealth() << "\n";
        cout << "Enemy's hp after battle: " << enemy->GetHealth() << "\n";
    }
};

class CharacterCreation {
public:
    void MainMenu(vector<Player*>& players) {
        ClearConsole();
        cout << "Welcome :)\n";

        int menuChoice = 0;
        do {
            if (players.size() <= 3) {
                cout << "1. Create a character\n";
            }
            if (players.size() >= 2) {
                cout << "2. Compare characters\n";
                cout << "3. Display all characters\n";
            }
            if (players.size() >= 1) {             
                cout << "3. Display all characters\n";
                cout << "4. Start Battle\n";
            }
            
            cout << "5. Exit\n";
            cout << "Enter the number of where you want to go: ";
            cin >> menuChoice;

            if (menuChoice == 1 && players.size() <= 3) {
                CreatePlayer(players);
            }
            else if (menuChoice == 2 && players.size() >= 2) {
                ComparePlayers(players);
            }
            else if (menuChoice == 3 && players.size() >= 1) {
                DisplayPlayers(players);
            }
            else if (menuChoice == 4 && players.size() >= 1) {
                GoToBattle(players);
            }
            else if (menuChoice != 5) {
                cout << "Select another option\n";
            }
            else if (menuChoice == 5) {
                ClearConsole();
                cout << "bye bye\n";
            }
        } while (menuChoice != 5);
    }

private:
    vector<string> raceChoices = {
        "Human",
        "Elf",
        "Vampire"
    };

    void CreatePlayer(vector<Player*>& players) {
        ClearConsole();
        string name = "";
        string role = "";
        string race = "";
        cout << "Enter player name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Choose a role (Wizard or Knight): ";
        cin >> role;

        cout << "Choose a race (enter the number you want):\n";
        for (int i = 0; i < raceChoices.size(); ++i) {
            cout << i + 1 << ". " << raceChoices[i] << "\n";
        }

        int raceChoice;
        cin >> raceChoice;

        if (raceChoice >= 1 && raceChoice <= raceChoices.size()) {
            race = raceChoices[raceChoice - 1];
        }
        else {
            cout << "Invalid choice: \n";
            cin >> raceChoice;
            race = raceChoices[raceChoice - 1];
        }

        if (role == "Wizard") {
            Wizard* wizard = new Wizard();  
            wizard->SetName(name);
            wizard->SetRole(role);
            wizard->SetRace(race);
            players.push_back(wizard);  
        }
        else if (role == "Knight") {
            Knight* knight = new Knight();  
            knight->SetName(name);
            knight->SetRole(role);
            knight->SetRace(race);
            players.push_back(knight);  
        }

        ClearConsole();
        cout << "Player added, congrats!\n";
        cout << "\n";
    }

    void ComparePlayers(const vector<Player*>& players) const {
        ClearConsole();
        int firstPlayer = 0;
        int secondPlayer = 0;
        cout << "Enter the first player (1 to " << players.size() << "): ";
        cin >> firstPlayer;
        ClearConsole();
        cout << "Enter the second player (1 to " << players.size() << "): ";
        cin >> secondPlayer;
        ClearConsole();

        if (firstPlayer >= 1 && firstPlayer <= players.size() && secondPlayer >= 1 && secondPlayer <= players.size() && firstPlayer != secondPlayer) {
            ClearConsole();
            cout << "First Player:\n";
            cout << players[firstPlayer - 1];
            cout << "\n";
            cout << "Second Player:\n";
            cout << players[secondPlayer - 1];
            cout << "\n";
        }
        else {
            
        }
    }

    void DisplayPlayers(const vector<Player*>& players) const {
        ClearConsole();
        for (int i = 0; i < players.size(); ++i) {
            cout << "Player " << i + 1 << ":\n";
            cout << players[i];
            cout << "\n";
        }
    }

    void GoToBattle(vector<Player*>& players) const {
        ClearConsole();
        TimeToBattle timeToBattle;

        cout << "Select a player to go to battle (1 to " << players.size() << "): ";
        int playerIndex;
        cin >> playerIndex;

        if (playerIndex >= 1 && playerIndex <= players.size()) {
            Player* selectedPlayer = players[playerIndex - 1];

            Enemy* enemy = ChooseRandomEnemy();
            cout << "Battle started!\n";
            timeToBattle.GoToBattle(selectedPlayer, enemy);

            
            cout << "\nBattle report:\n";
            cout << "Player:\n";
            cout << *selectedPlayer;
            cout << "Enemy:\n";
            cout << *enemy;
        }
        else {
            
        }
    }

    Enemy* ChooseRandomEnemy() const {
        int choice = rand() % 9;
        if (choice <= 1) {
            return new Skeleton();
        }
        else if (choice <= 4) {
            return new BigOrc();
        }
        else if (choice <= 6) {
            return new SmallOrc();
        }
        else if (choice <= 8) {
            return new RegularOrc();
        }
        else {
            return new Zombie();
        }
    }
};

int main() {
    CharacterCreation creation;
    vector<Player*> players;
    creation.MainMenu(players);
    return 0;
}