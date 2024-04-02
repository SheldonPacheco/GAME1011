#ifndef CHARACTERCREATION_H
#define CHARACTERCREATION_H
#include "Player.h"
#include "Enemy.h"
#include "TimeToBattle.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

inline void ClearConsole() {
    system("cls");
}
class CharacterCreation {
public:
    void MainMenu(vector<Player*>& players) {
        ClearConsole();
        LoadPlayerProgress(players);
        outputTextFromFile("WelcomeMessage.txt");
        cout << "\n";
        int menuChoice = 0;
        do {
            if (players.size() < 3) {
                outputTextFromFile("MainMenuCreateCharacterText.txt");
            }
            if (players.size() >= 2) {
                outputTextFromFile("MainMenuCompareCharacterText.txt");
            }
            if (players.size() >= 1) {
                outputTextFromFile("3to7MainMenuText.txt");
            }
            outputTextFromFile("EnterWhereYouWantToGoMainMenuAndExitText.txt");
            cin >> menuChoice;

            if (menuChoice == 1 && players.size() < 3) {
                CreatePlayer(players);
            }
            else if (menuChoice == 2 && players.size() >= 2) {
                ComparePlayers(players);
            }
            else if (menuChoice == 3 && players.size() >= 1) {
                DisplayPlayers(players);
            }
            else if (menuChoice == 4 && players.size() >= 1) {
                DisplayPlayers(players);
            }
            else if (menuChoice == 5 && players.size() >= 1) {
                GoToBattle(players, menuChoice);
                menuChoice = 0;
            }
            else if (menuChoice == 6 && players.size() >= 1) {
                GoToBattle(players, menuChoice);
            }
            else if (menuChoice == 7 && players.size() >= 1) {
                GoToBattle(players, menuChoice);
            }
            else if (menuChoice != 8) {
                outputTextFromFile("SelectAnotherOptionText.txt");
            }
            else if (menuChoice == 8) {
                ClearConsole();
                outputTextFromFile("GoodbyeMessage.txt");
            }
        } while (menuChoice != 8);
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
        outputTextFromFile("EnterPlayerNameText.txt");
        cin.ignore();
        getline(cin, name);
        ClearConsole();
        outputTextFromFile("RoleChoices.txt");
        int roleChoice;
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

        //for (int i = 0; i < raceChoices.size(); ++i) {
        //   cout << i + 1 << ". " << raceChoices[i] << "\n";
        //}
        outputTextFromFile("RaceChoices.txt");
        int raceChoice;
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
        SavePlayerProgress(players);
        ClearConsole();
        outputTextFromFile("PlayedAddedSavedText.txt");
    }

    void ComparePlayers(vector<Player*>& players) {
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
            outputTextFromFile("CompareCharacterDisplayText1.txt");
            cout << *(players[firstPlayer - 1]);
            outputTextFromFile("CompareCharacterDisplayText2.txt");
            cout << *(players[secondPlayer - 1]);

            
            
            if (players[firstPlayer - 1]->GetRole() == players[secondPlayer - 1]->GetRole()) {
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

    void DisplayPlayers(vector<Player*>& players) {
        ClearConsole();
        for (int i = 0; i < players.size(); ++i) {
            cout << "Player " << i + 1 << ":\n";
            cout << *(players[i]);
            cout << "\n";
        }
    }

    void GoToBattle(vector<Player*>& players, int menuChoice) {
        ClearConsole();
        TimeToBattle timeToBattle;
        DisplayPlayers(players);
        cout << "Select a player to go to battle (1 to " << players.size() << "): ";
        int playerChoice;
        cin >> playerChoice;
        ClearConsole();
        if (playerChoice >= 1 && playerChoice <= players.size()) {
            Player* selectedPlayer = players[playerChoice - 1];

            Enemy* enemy = ChooseRandomEnemy();

            //scaling enemies based off player
            enemy->SetLevel(selectedPlayer->GetLevel() + 2); //Scale level
            enemy->SetExp(enemy->GetExp() + enemy->GetLevel() * rand() % 30 + 50); //scale EXP reward
            enemy->SetHealth(enemy->GetHealth() + rand() % 1 + enemy->GetLevel() * 10); //scale health
            
            cout << "A wild " << enemy->GetSpeciesName() << " appears (" << "Health: " << enemy->GetHealth() <<", level: " << enemy->GetLevel() << ") (Reward: " << enemy->GetExp() << " EXP)\n";
            cout << selectedPlayer->GetName() << " the " << selectedPlayer->GetRole() << " (HP: " << selectedPlayer->GetHealth() << ", Level: " << selectedPlayer->GetLevel() << ")\n";
            cout << "\n";

            cout << "Battle Log:\n";
            if (menuChoice == 5) {
                timeToBattle.StartAutoBattle(selectedPlayer, enemy);
            }
            else if (menuChoice == 6) {
                if (selectedPlayer->GetRole() == "Wizard") {
                    cout << "Enter your move (slam with staff (every turn) or cast ice bolt (once every other turn)): ";
                }
                else if (selectedPlayer->GetRole() == "Knight") {
                    cout << "Enter your move (swing sword (every turn) or bunt with shield (once every other turn)): ";
                }
                cin.ignore();
                do {
                    string choice;
                    getline(cin, choice);
                    timeToBattle.StartBattle(choice, selectedPlayer, enemy);
                    if ((selectedPlayer->GetHealth() > 0 && enemy->GetHealth() > 0)) {
                        cout << "move: ";
                    }
                } while (selectedPlayer->GetHealth() > 0 && enemy->GetHealth() > 0);
            }            
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
                players[playerChoice - 1] = nullptr;
                players.erase(players.begin() + (playerChoice - 1));
                SavePlayerProgress(players);
            }
            if (enemy->GetHealth() <= 0) { 
                if (selectedPlayer->GetHealth() > 0) {
                    if (selectedPlayer->GetRole() == "Knight") {
                        //heals player if wins
                        selectedPlayer->SetHealth(120);
                        selectedPlayer->SetExp(enemy->GetExp());
                        SavePlayerProgress(players);
                    }
                    else if (selectedPlayer->GetRole() == "Wizard") {
                        //heals player if wins
                        selectedPlayer->SetHealth(90);
                        selectedPlayer->SetExp(enemy->GetExp());
                        SavePlayerProgress(players);
                    }
                }
                else {
                    
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
    void SavePlayerProgress(const vector<Player*>& players) {
        ofstream outFile("players.dat", ios::binary);
        for (const Player* player : players) {
            outFile << player->GetRole() << " " << player->GetName() << " " << player->GetRace() << " " << player->GetBattleWins() << " " << player->GetLevel() << " " << player->GetExp() << " ";
            player->Serialize(outFile);
        }
        outFile.close();
    }

    void LoadPlayerProgress(vector<Player*>& players) {
        players.clear();
        ifstream inFile("players.dat", ios::binary);
        while (true) {
            string role;
            string name;
            string race;
            int wins;
            int level;
            int exp;
            if (!(inFile >> role)) break; 
            inFile >> name >> race >> wins >> level >> exp;
            Player* player = nullptr;
            if (role == "Wizard") {
                player = new Wizard();
            }
            else if (role == "Knight") {
                player = new Knight();
            }
            if (player) {
                player->SetName(name);
                player->SetRole(role);
                player->SetRace(race);
                player->SetWins(wins);
                player->SetLevel(level);
                player->SetExp(exp);
                player->Deserialize(inFile);
                players.push_back(player);
            }
        }
        inFile.close();
    }
    void outputTextFromFile(const std::string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Failed to open file " << filename << "\n";
            return;
        }

        string line;
        while (getline(file, line)) {
            cout << line;
            if (!line.empty() && line.back() != ':') {
                cout << "\n";
            }
        }

        file.close();
    }
};

#endif
