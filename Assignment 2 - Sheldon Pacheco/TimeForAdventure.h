#ifndef TIMEFORADVENTURE_H
#define TIMEFORADVENTURE_H

#include <vector>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "TimeToBattle.h"

using namespace std;

class TimeForAdventure {
public:
    int choice;
    bool hasKey;
    bool hasPet;
    bool hasCrown;
    Enemy* enemy = ChooseRandomEnemy(choice);
    TimeToBattle BattleEncounter;
    void StartAdventure(Player* player) {
        srand(time(nullptr));
        Rooms();
        currentArea = areas.begin();
        hasKey = false;


        ExploreArea(player);
    }

private:
    struct Area {
        string description;
        string description2;
        string description3;
        string description4;
        string description5;
        string AreaName;       
        list<string> objects;
        vector<string> exits;
    };

    list<Area> areas;
    list<Area>::iterator currentArea;

    void Rooms() {

        Area Area1;
        Area1.AreaName = "Cave";
        Area1.description = "You find yourself in a dark cave...\n";
        Area1.description2 = "It feels vast with echoes and is very dark...\n";
        Area1.description3 = "Move forward? yes? no?:\n";
        Area1.exits = { "yes", "no"};
        areas.push_back(Area1);


        Area Area2;
        Area2.description5 = "\n";
        Area2.AreaName = "Ditch";
        Area2.description = "There's a big ditch that is quite big...\n";
        Area2.description2 = "and hard to see down in..jump or go around\n";
        Area2.exits = { "jump", "go around"};
        areas.push_back(Area2);

        Area Area3;
        Area3.description5 = "\n";
        Area3.AreaName = "Rusted Gate";
        Area3.description = "There's a big great rusted gate...\n";
        Area3.description2 = "that is locked and can be opened with a key...\n";
        Area3.description3 = "'Smash the gate' with rage or 'pickup the key' and 'open gate'\n";
        Area3.exits = { "open gate", "smash gate" };
        Area3.objects = { "Rusted Key" };
        areas.push_back(Area3);


        Area Area4;
        Area4.description5 = "\n";
        Area4.AreaName = "A tree";
        Area4.description = "The tree seems to have giant bite marks...\n";
        Area4.description2 = "Which looks like it came from a very vile beast.... 'walk past tree' or 'shout' to bring the beast out of hiding \n";
        Area4.exits = { "walk past tree", "shout" };
        areas.push_back(Area4);


        Area Area5;
        Area4.description5 = "\n";
        Area5.AreaName = "Village";
        Area5.description = "There's a beautiful village made of oak and glass...\n";
        Area5.description2 = "that is under attack by creepy and scary, ";
        enemy = ChooseRandomEnemy(4);
        Area5.description3 = enemy->GetSpeciesName();
        Area5.description4 = "\n Lots of them. With cries and screams from the villagers. 'help them' or 'run away'\n";
        Area5.exits = { "help them", "run away" };
        areas.push_back(Area5);


        Area Area6;
        Area6.description5 = "\n";
        Area6.AreaName = "Castle Gates";
        Area6.description = "There's a big great rusted gate...\n";
        Area6.description2 = "that is locked and can be opened with a key. 'enjoy the view' or 'go through gate'\n";
        Area6.exits = { "enjoy the view", "go through gate" };
        areas.push_back(Area6);

        Area Area7;
        Area7.description5 = "\n";
        Area7.AreaName = "Village Leader's house";
        Area7.description = "The leader is about to dead by an Undead skeleton in laughter\n";
        Area7.description2 = "that is locked and can be opened with a key. 'help the leader'?\n";
        Area7.exits = { "help the leader" };
        areas.push_back(Area7);

        Area Area8;
        Area8.description5 = "\n";
        Area8.AreaName = "Castle Throne Room";
        Area8.description = "There's a beautiful hall, encrusted in red gold...\n";
        Area8.description2 = "with the distressed look of the king, that is surrounded by big evil goblins. help the king?\n";
        Area8.exits = { "help the king" };
        areas.push_back(Area8);

        Area Area9;
        Area9.description5 = "\n";
        Area9.AreaName = "Grateful King";
        Area9.description = "Thank you so much for the help!\n";
        Area9.description2 = "Take this crown.\n";
        Area9.description3 = "You saved us! and the whole kingdoms. Say 'no problem'? and 'take crown'\n";
        Area9.exits = { "no problem" };
        Area3.objects = { "crown" };
        areas.push_back(Area9);

        Area Area10;
        Area10.description5 = "\n";
        Area10.AreaName = "Grateful Villagers";
        Area10.description = "Thank you, thank you...\n";
        Area10.description2 = "here take this. 'take pet bear'?\n";
        Area10.exits = { "take pet bear" };
        Area10.objects = { "pet bear" };
        areas.push_back(Area10);
    }

    void ExploreArea(Player* player) {

        if (player->GetHealth() > 0) {
            Area current = *currentArea;
            cout << current.description5 << current.description << current.description2 << current.description3 << current.description4;

            if (!current.objects.empty()) {
                if (current.AreaName == "Rusted Gate") {
                    if (hasKey == false) {
                        cout << "You find something on the floor\n";
                        for (const auto& obj : current.objects) {
                            cout << "- " << obj << endl;
                        }
                    }
                }
                if (current.AreaName == "Grateful King") {
                    if (hasCrown == false) {
                        cout << "king hands you crown:\n";
                        for (const auto& obj : current.objects) {
                            cout << "- " << obj << endl;
                        }
                    }
                }
                if (current.AreaName == "Grateful Villagers") {
                    if (hasPet == false) {
                        cout << "Leader hands you pet:\n";
                        for (const auto& obj : current.objects) {
                            cout << "- " << obj << endl;
                        }
                    }
                }
            }
            string action;
            getline(cin, action);
            if (current.AreaName == "Grateful Villagers") {
                if (action == "take pet bear" && current.objects.size() > 0 && current.objects.front() == "pet bear") {
                    cout << "You took the pet.\n";
                    current.objects.pop_front();
                    hasPet = true;
                }
                else {
                    cout << "Invalid action.\n";

                }
                if (action == "take pet bear") {
                    MoveToRoom("take pet bear", player);
                }
            }
            if (current.AreaName == "Grateful King") {
                if (action == "take crown" && current.objects.size() > 0 && current.objects.front() == "crown") {
                    cout << "You took the crown.\n";
                    current.objects.pop_front();
                    hasCrown = true;
                }
                else {
                    cout << "Invalid action.\n";

                }
                if (action == "no problem") {
                    MoveToRoom("no problem", player);
                }
            }
            if (current.AreaName == "Castle Throne Room") {
                if (action == "help the king") {
                    cout << "walk past tree and 8 wild Zombies appears.\n";
                    enemy = ChooseRandomEnemy(1);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(1);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(2);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(3);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(3);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(2);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(2);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(3);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    MoveToRoom("help the king", player);
                }
                else {
                    cout << "Invalid action.\n";
                }
            }
            if (current.AreaName == "Village Leader's house") {
                if (action == "help the leader") {
                    cout << "8 zombies stand in your way.\n";
                    enemy = ChooseRandomEnemy(8);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(8);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(8);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(8);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(8);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(8);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(8);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(8);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    MoveToRoom("help the leader", player);
                }
                else {
                    cout << "Invalid action.\n";
                }
            }
            if (current.AreaName == "Castle Gates") {
                if (action == "enjoy the view") {
                    cout << "enjoyed the view and 4 wild Zombies appears.\n";
                    enemy = ChooseRandomEnemy(0);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(0);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(0);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(0);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    MoveToRoom("enjoy the view", player);

                }
                else {
                    cout << "Invalid action.\n";
                }
                if (action == "go through gate") {
                    cout << "oof, skeletons appear.\n";
                    enemy = ChooseRandomEnemy(0);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(0);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(0);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    MoveToRoom("move forward", player);
                }
                else {
                    cout << "Invalid action.\n";
                }
            }
            if (current.AreaName == "Village") {
                if (action == "help them") {
                    cout << "walk past tree and 4 wild Zombies appears.\n";
                    enemy = ChooseRandomEnemy(4);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(4);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(4);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(4);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    MoveToRoom("help them", player);

                }
                else {
                    cout << "Invalid action.\n";
                }
                if (action == "run away") {
                    cout << "oof, a terrible werewolf appears.\n";
                    enemy = ChooseRandomEnemy(5);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    MoveToRoom("run away", player);
                }
                else {
                    cout << "Invalid action.\n";
                }
            }
            if (current.AreaName == "A tree") {
                if (action == "walk past tree") {
                    cout << "walk past tree and 3 Orcs appears.\n";
                    enemy = ChooseRandomEnemy(1);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(2);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    enemy = ChooseRandomEnemy(2);
                    BattleEncounter.StartAutoBattle(player, enemy);

                    MoveToRoom("walk past tree", player);

                }
                else {
                    cout << "Invalid action.\n";
                }
                if (action == "shout") {
                    enemy = ChooseRandomEnemy(5);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    MoveToRoom("shout", player);
                }
                else {
                    cout << "Invalid action.\n";
                }
            }
            if (current.AreaName == "Ditch") {
                if (action == "jump") {
                    if (rand() % 2 == 0) {
                        cout << "You successfully jumped over the ditch!\n";
                        MoveToRoom("jump", player);
                    }
                    else {
                        cout << "You failed to jump over and tripped and lost 50% HP\n";
                        player->SetHealth(player->GetHealth() * -50);
                        MoveToRoom("jump", player);
                    }
                }
                else {
                    cout << "Invalid action.\n";
                }
                if (action == "go around") {
                    enemy = ChooseRandomEnemy(4);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    MoveToRoom("go around", player);
                }
                else {
                    cout << "Invalid action.\n";
                }
            }
            if (current.AreaName == "Rusted Gate") {
                if (action == "pickup the key" && hasKey == false && current.objects.size() > 0 && current.objects.front() == "Rusted Key") {
                    cout << "You picked up the key.\n";

                    hasKey = true;
                }
                else if (action == "open gate" && hasKey == true) {
                    MoveToRoom("open gate", player);
                }
                else if (action == "smash the gate") {
                    MoveToRoom("smash the gate", player);
                }
                else {
                    cout << "Invalid action.\n";
                }
            }
            if (current.AreaName == "Cave") {
                if (action == "yes") {
                    enemy = ChooseRandomEnemy(2);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    MoveToRoom("yes", player);
                }
                else if (action == "no") {
                    enemy = ChooseRandomEnemy(3);
                    BattleEncounter.StartAutoBattle(player, enemy);
                    MoveToRoom("no", player);
                }
                else {
                    cout << "Invalid action.\n";
                }
            }
            if (current.exits.empty() && current.objects.empty()) {
                cout << "There's nothing more to do here.\n";
            }
            else {
                ExploreArea(player);
            }
        }
        else {
            cin.ignore();
            cout << "Your journey has ended :( You died.";
        }
    }
    void MoveToRoom(const string& direction, Player* player) {
        if (player->GetHealth() > 0) {
            Area current = *currentArea;
            bool canMove = false;

            for (const auto& exit : current.exits) {
                if (exit == direction) {
                    canMove = true;
                    break;
                }
            }
            if (current.AreaName == "Cave") {
                if (canMove) {

                    if (direction == "yes") {
                        cout << "You moved forward and found a " << (++currentArea)->AreaName << ".\n";
                    }
                    else if (direction == "no") {
                        ++currentArea;
                        cout << "You moved forward and found a " << (++currentArea)->AreaName << ".\n";
                    }
                    ExploreArea(player);
                }
                else {
                    cout << "Invalid action.\n";
                }
            }
            if (current.AreaName == "Rusted Gate") {
                if (canMove) {

                    if (direction == "open gate") {
                        ++currentArea;
                        cout << "You moved forward and found a beautiful " << (++currentArea)->AreaName << ".\n";
                    }
                    else if (direction == "smash the gate") {
                        cout << "You moved past the gate the riddled gate and lost 10% hp and found a " << (++currentArea)->AreaName << ".\n";
                        player->SetHealth(player->GetHealth() * -10);
                    }
                    ExploreArea(player);
                }
                else {
                    cout << "Invaild action.\n";
                }
            }
            if (current.AreaName == "Ditch") {
                if (canMove) {

                    if (direction == "jump") {
                        cout << "and found a " << (++currentArea)->AreaName << ".\n";
                    }
                    else if (direction == "go around") {
                        cout << "You walk around and find a " << (++currentArea)->AreaName << ".\n";
                    }
                    ExploreArea(player);
                }
                else {
                    cout << "Invaild action.\n";
                }
            }
            if (current.AreaName == "A tree") {
                if (canMove) {

                    if (direction == "walk past tree") {
                        ++currentArea;
                        cout << "You moved forward and found a grand big " << (++currentArea)->AreaName << ".\n";
                    }
                    else if (direction == "shout") {
                        cout << "You defeated the beast, after a sore throat and found a  " << (++currentArea)->AreaName << ".\n";
                    }
                    ExploreArea(player);
                }
                else {
                    cout << "Invaild action.\n";
                }
            }
            if (current.AreaName == "Village") {
                if (canMove) {

                    if (direction == "help them") {
                        ++currentArea;
                        cout << "You moved forward through the burning city and find the " << (++currentArea)->AreaName << ".\n";
                    }
                    else if (direction == "run away") {
                        cout << "After defeating the beast you find yourself at the  " << (++currentArea)->AreaName << ".\n";
                    }
                    ExploreArea(player);
                }
                else {
                    cout << "Invaild action.\n";
                }
            }
            if (current.AreaName == "Castle Gate") {
                if (canMove) {

                    if (direction == "enjoy the view") {
                        ++currentArea;
                        cout << "You enjoyed the view and defeated the skeletons that jumped you and move forward to the  " << (++currentArea)->AreaName << ".\n";
                    }
                    else if (direction == "move forward") {
                        ++currentArea;
                        cout << "you and move forward and found the " << (++currentArea)->AreaName << ".\n";
                    }
                    ExploreArea(player);
                }
                else {
                    cout << "Invaild action.\n";
                }
            }
            if (current.AreaName == "Castle Throne Room") {
                if (canMove) {

                    if (direction == "help the king") {
                        cout << "You helped the king and castle and all of the kingdoms, you now go and talk to the " << (++currentArea)->AreaName << ".\n";
                    }
                    ExploreArea(player);
                }
                else {
                    cout << "Invaild action.\n";
                }
            }
            if (current.AreaName == "Grateful King") {
                if (canMove) {

                    if (direction == "no problem" && hasCrown == true) {
                        cout << "You beat the game, good job :).\n";
                    }
                    ExploreArea(player);
                }
                else {
                    cout << "Invaild action.\n";
                }
            }
            if (current.AreaName == "Village Leader's house") {
                if (canMove) {
                    if (direction == "help the leader") {
                        ++currentArea;
                        ++currentArea;
                        cout << "You helped the village and saved the leader and speak to the " << (++currentArea)->AreaName << ".\n";
                    }
                    ExploreArea(player);
                }
                else {
                    cout << "Invaild action.\n";
                }
            }
            if (current.AreaName == "Grateful villagers " && hasPet == true) {
                if (canMove) {
                    if (direction == "take the pet") {
                        cout << "You beat the game good job :)\n";
                    }
                }
                else {
                    cout << "Invaild action.\n";
                }
            }
        }
        else {
           
        }
    }
    Enemy* ChooseRandomEnemy(int choice) const {
        choice = choice;

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
        else if (choice == 5) {
            return new Werewolf();
        }
    }
};

#endif