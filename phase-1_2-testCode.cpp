#include <iostream>

#include "game.h"

using namespace std;

int main() {
    string filename = "data/input.txt";

    Game game(filename);

    game.runInteractive();

    return 0;
}