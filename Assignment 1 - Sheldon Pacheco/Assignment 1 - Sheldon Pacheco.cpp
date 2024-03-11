#include <iostream>
#include <string>
#include <vector>
#include <ctime>
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
    Player() : name("No Player"), health(0), role("No Role"), race("No Race"), specialAttackDamage(0), normalAttackDamage(0), battleWins(0){}

    
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

const string Wizard::specialAttackName = "Ice Bolt";
const int Wizard::specialAttackDamage = 30;
int Wizard::normalAttackDamage;

class Knight : public Player {
public:
    static const string specialAttackName;
    static const int specialAttackDamage;
    static int normalAttackDamage;
    Knight() {
        SetHealth(120);
    }
    int GetNormalAttackDamage() const override{
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
        
        cout << "Knight: uses " << specialAttackName <<" with shield" << " | dealing: " << specialAttackDamage << " damage" << "\n";
    }

};

const string Knight::specialAttackName = "Bunt";
const int Knight::specialAttackDamage = 15;
int Knight::normalAttackDamage;

class Enemy : public GameObject {
public:
    Enemy() : health(0), tauntDamage(0), normalAttackDamage(0){}

    
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
};

class Orc : public Enemy {
public:
    Orc(const string& speciesName, const vector<string>& taunts, int tauntDamage, int health, int normalAttackDamage) : speciesName(speciesName), taunts(taunts), tauntDamage(tauntDamage), normalAttackDamage(normalAttackDamage){
        SetHealth(health);
    }
    int GetNormalAttackDamage() const override{
        return normalAttackDamage;
    }

    int GetTauntDamage() const override{

        return tauntDamage;
    }
    string GetSpeciesName() const override {

        return speciesName;
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
};

class Undead : public Enemy {
public:
    Undead(const string& speciesName, const vector<string>& taunts, int tauntDamage, int health, int normalAttackDamage) : speciesName(speciesName), taunts(taunts), tauntDamage(tauntDamage), normalAttackDamage(normalAttackDamage){
        SetHealth(health);
    }
    int GetNormalAttackDamage() const override {
        return normalAttackDamage;
    }

    int GetTauntDamage() const override{

        return tauntDamage;
    }
    string GetSpeciesName() const override {

        return speciesName;
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
};

class BigOrc : public Orc {
public:
    BigOrc() : Orc("Big Orc", { "I'm a big orc, yells at player"},20, 120, 0) {}
};

class SmallOrc : public Orc {
public:
    SmallOrc() : Orc("Small Orc", { "I'm a small Orc, laughs at player"},20, 80, 0) {}
};

class RegularOrc : public Orc {
public:
    RegularOrc() : Orc("Orc", { "I'm an Orc, pushes player "},20, 100, 0) {}
};

class Zombie : public Undead {
public:
    Zombie() : Undead("Zombie", { "rrrrrrrr, I'm a zombie, bites player"},20, 100, 0) {}
};

class Skeleton : public Undead {
public:
    Skeleton() : Undead("Skeleton", { "I'm a boney skeleton, haunts player"},20, 110, 0) {}
};

class Ghost : public Undead {
public:
    Ghost() : Undead("Ghost", { "I'm something you cant see, fears player"},20, 90, 0) {}
};

class TimeToBattle {
public:
    void GoToBattle(Player* player, Enemy* enemy) {
        int numberOfAttacksPlayer=0;
        int numberOfAttacksEnemy=0;

        cout << "A wild " << enemy->GetSpeciesName() << " appears\n";
        cout << player->GetName() << " the " << player->GetRole() << " HP: " << player->GetHealth() << " | " << enemy->GetSpeciesName() << " HP: " << enemy->GetHealth() << "\n";
        cout << "\n";


        while (player->GetHealth() > 0 || enemy->GetHealth() > 0) {
            int playerDamage;
            int enemyDamage;


            player->NormalAttack();
            playerDamage = player->GetNormalAttackDamage();
            enemy->SetHealth(enemy->GetHealth() - playerDamage);
            numberOfAttacksPlayer++;
            if (enemy->GetHealth() <= 0) {
                enemy->SetHealth(0);
                break;
            }

            enemy->NormalAttack();
            enemyDamage = enemy->GetNormalAttackDamage();
            player->SetHealth(player->GetHealth() - enemyDamage);
            numberOfAttacksEnemy++;
            if (player->GetHealth() <= 0) {
                player->SetHealth(0);
                break;
            }

            player->SpecialAttack();
            playerDamage = player->GetSpecialAttackDamage();
            enemy->SetHealth(enemy->GetHealth() - playerDamage);
            numberOfAttacksPlayer++;
            if (enemy->GetHealth() <= 0) {
                enemy->SetHealth(0);
                break;
            }

            enemy->TauntPlayer();
            enemyDamage = enemy->GetTauntDamage();
            player->SetHealth(player->GetHealth() - enemyDamage);
            numberOfAttacksEnemy++;
            if (player->GetHealth() <= 0) {
                player->SetHealth(0);
                break;
            }  

        }  
        cout <<"\n";
        cout << "Player's hp after battle: " << player->GetHealth() << ", with " << numberOfAttacksPlayer << " attacks" << "\n";
        cout << "Enemy's hp after battle: " << enemy->GetHealth() << ", with " << numberOfAttacksEnemy << " attacks" << "\n";
        cout << "\n";

        if (player->GetHealth() <= 0) {
            cout <<"The " << enemy->GetSpeciesName() << " wins the battle!!!! " << "\n";
            cout << player->GetName() << " the " << player->GetRole() << " will be deleted :( " << "\n";

        }
        if (enemy->GetHealth() <= 0) {
            cout << player->GetName() << " the " << player->GetRole() << " wins the battle!! " << "\n";
            cout << "Heals to full HP." << "\n";
            player->IncreaseBattleWins();

        }
    }

private:
};

class CharacterCreation {
public:
    void MainMenu(vector<Player*>& players) {
        ClearConsole();
        cout << "Welcome :)\n";
        cout << "\n";
        int menuChoice = 0;
        do {
            if (players.size() <= 3) {
                cout << "1. Create a character\n";
            }
            if (players.size() >= 2) {
                cout << "2. Compare characters\n";
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
                cout << "bye :)\n";
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
        cout << "Enter player's name: ";
        cin.ignore();
        getline(cin, name);
        ClearConsole();
        cout << "Roles:\n";
        cout << "1. Wizard\n";
        cout << "2. Knight\n";
        int roleChoice;
        cout << "Choose a role (enter the number you want):";
        cin >> roleChoice;

        if (roleChoice == 1) {
            role = "Wizard";
        }
        else if (roleChoice == 2) {
            role = "Knight";
        }
        else {
            cin >> roleChoice;
        }
        ClearConsole();
        
        for (int i = 0; i < raceChoices.size(); ++i) {
            cout << i + 1 << ". " << raceChoices[i] << "\n";
        }

        int raceChoice;
        cout << "Choose a race (enter the number you want):";
        cin >> raceChoice;
        
        if (raceChoice >= 1 && raceChoice <= raceChoices.size()) {
            race = raceChoices[raceChoice - 1];
        }
        else {
            cin >> raceChoice;
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
            cout << *(players[firstPlayer - 1]);
            cout << "\n";
            cout << "Second Player:\n";
            cout << *(players[secondPlayer - 1]);
            cout << "\n";
            if (players[firstPlayer - 1]->GetRole() == players[secondPlayer - 1]->GetRole()){
                cout << "Classes are the same. " << "\n";
            }
            else {
                cout << "Classes are different. " << "\n";
            }
            if (players[firstPlayer - 1]->GetRace() == players[secondPlayer - 1]->GetRace()) {
                cout << "Races are the same. " << "\n";
            }
            else {
                cout << "Races are different. " << "\n";
            }
            cout << "\n";
        }
        else {
            
        }
    }

    void DisplayPlayers(const vector<Player*>& players) const {
        ClearConsole();
        for (int i = 0; i < players.size(); ++i) {
            cout << "Player " << i + 1 << ":\n";
            cout << *(players[i]);
            cout << "\n";
        }
    }

    void GoToBattle(vector<Player*>& players) const {
        ClearConsole();
        TimeToBattle timeToBattle;

        cout << "Select a player to go to battle (1 to " << players.size() << "): ";
        int playerChoice;
        cin >> playerChoice;
        ClearConsole();
        if (playerChoice >= 1 && playerChoice <= players.size()) {
            Player* selectedPlayer = players[playerChoice - 1];

            Enemy* enemy = ChooseRandomEnemy();
            cout << "Battle Log:\n";
            timeToBattle.GoToBattle(selectedPlayer, enemy);

            cout << "\n";
            cout << "Battle report:\n";
            cout << "Player~\n";
            cout << *selectedPlayer;
            cout << "\n";
            cout << "Enemy~\n";
            cout << *enemy;
            cout << "\n";
            if (selectedPlayer->GetHealth() <= 0) {
                delete selectedPlayer;
                players.erase(players.begin() + (playerChoice - 1));
            }
            if (enemy->GetHealth() <= 0) { //heals player if wins
                if (selectedPlayer->GetRole() == "Knight") {
                    selectedPlayer->SetHealth(120);
                }
                else if (selectedPlayer->GetRole() == "Wizard") {
                    selectedPlayer->SetHealth(90);
                }
            }
        }
        else {
            
        }
    }

    Enemy* ChooseRandomEnemy() const {
        int choice = rand() % 5;

        if (choice == 0) {
            return new Skeleton();
        }
        else if (choice == 1) {
            return new BigOrc();
        }
        else if (choice == 2) {
            return new SmallOrc();
        }
        else if (choice == 3) {
            return new RegularOrc();
        }
        else if (choice == 4) {
            return new Zombie();
        }
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    CharacterCreation creation;
    vector<Player*> players;
    creation.MainMenu(players);
    return 0;
}