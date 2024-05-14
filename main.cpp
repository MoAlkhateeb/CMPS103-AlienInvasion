#include <iostream>

#include "game.h"

using namespace std;

int main() {
    string inFile = "data/input.txt";
    string outFile = "data/output.txt";
   
    Mode operation;
    int opNum;

    cout << "Please Enter the number for Mode of Operation: " << endl;
    cout << INTERACTIVE << ": Interactive Mode" << endl;
    cout << SILENT << ": Silent Mode" << endl << endl;
    cin >> opNum;

    operation = (Mode)opNum;

    Game game(inFile, outFile);

    switch (operation) {
    case INTERACTIVE:
        game.run(INTERACTIVE);
        break;
    case SILENT:
        game.run(SILENT);
        break;
    default:
        cout << "Invalid Running Mode." << endl;
        break;
    }

    return 0;
}
