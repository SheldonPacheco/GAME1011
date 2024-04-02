#include "CharacterCreation.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

int main() {
    srand(static_cast<unsigned>(time(nullptr))); //set seed
    CharacterCreation creation;
    vector<Player*> players;
    creation.MainMenu(players);
    return 0;
}