#ifndef CHARACTERCREATION_H
#define CHARACTERCREATION_H
#include "Player.h"
#include "Enemy.h"
#include "TimeToBattle.h"
#include <iostream>
#include <vector>
using namespace std;

inline void ClearConsole() {
    system("cls");
}
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

#endif
