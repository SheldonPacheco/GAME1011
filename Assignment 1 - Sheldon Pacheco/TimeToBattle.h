#ifndef TIMETOBATTLE_H
#define TIMETOBATTLE_H

#include "Player.h"
#include "Enemy.h"
#include <iostream>

class TimeToBattle {
public:
    void GoToBattle(Player* player, Enemy* enemy) {
        int numberOfAttacksPlayer = 0;
        int numberOfAttacksEnemy = 0;

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
    }

private:
};

#endif 
