#include "CharacterCreation.h"
#include <cstdlib>
#include <ctime>
int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    CharacterCreation creation;
    vector<Player*> players;
    creation.MainMenu(players);
    return 0;
}