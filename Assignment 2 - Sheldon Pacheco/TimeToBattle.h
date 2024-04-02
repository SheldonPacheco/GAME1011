#ifndef TIMETOBATTLE_H
#define TIMETOBATTLE_H

#include "Player.h"
#include "Enemy.h"
#include <iostream>

class TimeToBattle {
public:
    int playerSpecialAttackCount = 0;
    int enemyTauntAttackCount = 0;
    void StartAutoBattle(Player* player, Enemy* enemy) {
        int numberOfAttacksPlayer = 0;
        int numberOfAttacksEnemy = 0;
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
            cout << "  Player health: " << player->GetHealth() << " | " << enemy->GetSpeciesName() << " " << enemy->GetHealth() << "\n";
            cout << "\n";
            enemy->NormalAttack();
            enemyDamage = enemy->GetNormalAttackDamage();
            player->SetHealth(player->GetHealth() - enemyDamage);
            numberOfAttacksEnemy++;
            if (player->GetHealth() <= 0) {
                player->SetHealth(0);
                break;
            }
            cout << "  Player health: " << player->GetHealth() << " | " << enemy->GetSpeciesName() << " " << enemy->GetHealth() << "\n";
            cout << "\n";
            player->SpecialAttack();
            playerDamage = player->GetSpecialAttackDamage();
            enemy->SetHealth(enemy->GetHealth() - playerDamage);
            numberOfAttacksPlayer++;
            if (enemy->GetHealth() <= 0) {
                enemy->SetHealth(0);
                break;
            }
            cout << "  Player health: " << player->GetHealth() << " | " << enemy->GetSpeciesName() << " " << enemy->GetHealth() << "\n";
            cout << "\n";
            enemy->TauntPlayer();
            enemyDamage = enemy->GetTauntDamage();
            player->SetHealth(player->GetHealth() - enemyDamage);
            numberOfAttacksEnemy++;
            if (player->GetHealth() <= 0) {
                player->SetHealth(0);
                break;
            }
            cout << "  Player health: " << player->GetHealth() << " | " << enemy->GetSpeciesName() << " " << enemy->GetHealth() << "\n";
            cout << "\n";
        }
        cout << "\n";
        cout << "Player's hp after battle: " << player->GetHealth() << ", with " << numberOfAttacksPlayer << " attacks" << "\n";
        cout << "Enemy's hp after battle: " << enemy->GetHealth() << ", with " << numberOfAttacksEnemy << " attacks" << "\n";
        cout << "\n";

        if (player->GetHealth() <= 0) {
            cout << "The " << enemy->GetSpeciesName() << " wins the battle!!!! " << "\n";
            cout << player->GetName() << " the " << player->GetRole() << " will be deleted :( " << "\n";

        }
        if (enemy->GetHealth() <= 0) {
            cout << player->GetName() << " the " << player->GetRole() << " wins the battle!! " << "\n";
            cout << "Heals to full HP." << "\n";
            player->IncreaseBattleWins();

        }
        if (enemy->GetHealth() <= 0 && player->GetHealth() <= 0) {
            cout << "No one wins :( " << "\n";
            enemyTauntAttackCount = 0;
            playerSpecialAttackCount = 0;
        }
    }
    void StartBattle(const string& choice, Player* player, Enemy* enemy) {
        int playerDamage;
        int enemyDamage;
        if (choice == "swing sword" || choice == "slam with staff") {
            cout << "\n";
            player->NormalAttack();
            playerDamage = player->GetNormalAttackDamage();
            enemy->SetHealth(enemy->GetHealth() - playerDamage);
            if (enemy->GetHealth() <= 0) {
                enemy->SetHealth(0);
            }

            if (enemyTauntAttackCount == 1) {
                enemy->NormalAttack();
                enemyDamage = enemy->GetNormalAttackDamage();
                player->SetHealth(player->GetHealth() - enemyDamage);
                enemyTauntAttackCount = 0;
                if (player->GetHealth() <= 0) {
                    player->SetHealth(0);
                }

            } else if (enemyTauntAttackCount == 0) {
                enemy->TauntPlayer();
                enemyDamage = enemy->GetTauntDamage();
                player->SetHealth(player->GetHealth() - enemyDamage);
                enemyTauntAttackCount++;
                if (player->GetHealth() <= 0) {
                    player->SetHealth(0);
                }
            }


            playerSpecialAttackCount = 0;
            cout << "  Player health: " << player->GetHealth() << " | " << enemy->GetSpeciesName() << " " << enemy->GetHealth() << "\n";
            cout << "\n";



            if (player->GetHealth() <= 0) {
                cout << "The " << enemy->GetSpeciesName() << " wins the battle!!!! " << "\n";
                cout << player->GetName() << " the " << player->GetRole() << " will be deleted :( " << "\n";
                enemyTauntAttackCount = 0;
                playerSpecialAttackCount = 0;
            }
            if (enemy->GetHealth() <= 0) {
                cout << player->GetName() << " the " << player->GetRole() << " wins the battle!! " << "\n";
                cout << "Heals to full HP." << "\n";
                player->IncreaseBattleWins();
                enemyTauntAttackCount = 0;
                playerSpecialAttackCount = 0;
            }
            if (enemy->GetHealth() <= 0 && player->GetHealth() <= 0) {
                cout << "No one wins :( " << "\n";
                enemyTauntAttackCount = 0;
                playerSpecialAttackCount = 0;
            }
        }
        
        else if (choice == "bunt with shield" || choice == "cast ice bolt") {
            if (playerSpecialAttackCount != 1) {
                cout << "\n";
                player->SpecialAttack();
                playerDamage = player->GetSpecialAttackDamage();
                enemy->SetHealth(enemy->GetHealth() - playerDamage);
                if (enemy->GetHealth() <= 0) {
                    enemy->SetHealth(0);
                }

                
                if (enemyTauntAttackCount == 1) {
                    enemy->NormalAttack();
                    enemyDamage = enemy->GetNormalAttackDamage();
                    player->SetHealth(player->GetHealth() - enemyDamage);
                    enemyTauntAttackCount = 0;
                    if (player->GetHealth() <= 0) {
                        player->SetHealth(0);
                    }

                }
                else if (enemyTauntAttackCount == 0) {
                    enemy->TauntPlayer();
                    enemyDamage = enemy->GetTauntDamage();
                    player->SetHealth(player->GetHealth() - enemyDamage);
                    enemyTauntAttackCount++;
                    if (player->GetHealth() <= 0) {
                        player->SetHealth(0);
                    }
                }


                playerSpecialAttackCount++;
                cout << "  Player health: " << player->GetHealth() << " | " << enemy->GetSpeciesName() << " " << enemy->GetHealth() << "\n";
                cout << "\n";



                if (player->GetHealth() <= 0) {
                    cout << "The " << enemy->GetSpeciesName() << " wins the battle!!!! " << "\n";
                    cout << player->GetName() << " the " << player->GetRole() << " will be deleted :( " << "\n";
                    enemyTauntAttackCount = 0;
                    playerSpecialAttackCount = 0;
                }
                if (enemy->GetHealth() <= 0) {
                    cout << player->GetName() << " the " << player->GetRole() << " wins the battle!! " << "\n";
                    cout << "Heals to full HP." << "\n";
                    player->IncreaseBattleWins();
                    enemyTauntAttackCount = 0;
                    playerSpecialAttackCount = 0;
                }
                if (enemy->GetHealth() <= 0 && player->GetHealth() <= 0) {
                    cout << "No one wins :( " << "\n";
                    enemyTauntAttackCount = 0;
                    playerSpecialAttackCount = 0;
                }
            }
            else {
                cout << "Too early to special attack, wait " << playerSpecialAttackCount << " turn \n";
            }
            
        }
    }

private:
};

#endif 
