#include "game.h"

int RandGen::earthID = MINEARTHID;
int RandGen::alienID = MINALIENID;

bool Game::loadParameters() {
    ifstream file(inputFile);

    if (!file.is_open()) {
        cerr << "Error: file not found" << endl;
        file.close();
        return false;
    }

    bool isEmpty = (file.peek() == ifstream::traits_type::eof());

    if (isEmpty) {
        cerr << "Error: input file is empty" << endl;
        file.close();
        return false;
    }

    int N;
    int ESPercent, ETPercent, EGPercent, HUPercent;
    int ASPercent, AMPercent, ADPercent;
    range EPower, EHealth, EAttack;
    range APower, AHealth, AAttack;
    int generateProb;

    file >> N;
    file >> ESPercent >> ETPercent >> EGPercent >> HUPercent;
    file >> ASPercent >> AMPercent >> ADPercent;
    file >> generateProb;
    file >> EPower.start >> EPower.end >> EHealth.start >>
        EHealth.end >> EAttack.start >> EAttack.end;
    file >> APower.start >> APower.end >> AHealth.start >>
        AHealth.end >> AAttack.start >> AAttack.end;

    EPower.end = abs(EPower.end);
    EHealth.end = abs(EHealth.end);
    EAttack.end = abs(EAttack.end);

    APower.end = abs(APower.end);
    AHealth.end = abs(AHealth.end);
    AAttack.end = abs(AAttack.end);

    file.close();

    randGen.setN(N);

    randGen.setGenerateProb(generateProb);

    randGen.setETPercent(ETPercent);
    randGen.setESPercent(ESPercent);
    randGen.setEGPercent(EGPercent);
      
    randGen.setHUPercent(HUPercent);
    
    randGen.setAMPercent(AMPercent);
    randGen.setASPercent(ASPercent);
    randGen.setADPercent(ADPercent);
   
    randGen.setEPower(EPower);
    randGen.setEHealth(EHealth);
    randGen.setEAttack(EAttack);

    randGen.setAPower(APower);
    randGen.setAHealth(AHealth);
    randGen.setAAttack(AAttack);


    return true;
}

Game::Game(const string &inputFile, const string &outputFile): randGen(this), timeStep(0), won(TBD), inputFile(inputFile), outputFile(outputFile) {
    bool loaded = loadParameters();

    if (!loaded) {
        cout << "Could not load file: " << inputFile << endl;
        exit(1);
    }
}

WON Game::checkWinCondition() {

    if (aliens.getCount() == 0 && earth.getCount() > 0) {
        return EARTH;
    }
    else if (aliens.getCount() > 0 && earth.getCount() == 0) {
        return ALIENS;
    }
    else if (aliens.getCount() == 0 && earth.getCount() == 0) {
        return DRAW;
    }
    else {
        return TBD;
    }
}

void Game::run(Mode operation) {
    while (true) {
        randGen.createUnits(timeStep);

        earth.attack(timeStep);
        aliens.attack(timeStep);

        if (operation == INTERACTIVE) {
            print();
            cout << "Press any key to move to the next timestep. " << endl;
            cin.get();
        }

        if (timeStep >= 40 && checkWinCondition() != TBD)
            break;

        timeStep++;
    }
}

void Game::print() {
    cout << "Current Timestep " << timeStep << endl;
    earth.print();
    cout << endl;
    aliens.print();
    cout << endl;
    killed.print();
    cout << endl;
    heal.print();
    cout << endl;
    tankMaintain.print();
    cout << endl;
    soldierMaintain.print();
    cout << endl << endl;
}

EarthArmy* Game::getEarthArmy() const { return (EarthArmy*) &earth; }

AlienArmy* Game::getAlienArmy() const { return (AlienArmy*) &aliens; }

KilledList* Game::getKilled() const { return (KilledList*) &killed; }


TankMaintainList* Game::getTankMaintainList() const { return (TankMaintainList*) &tankMaintain; }
HealList* Game::getHealList() const { return (HealList*) &heal; }
EarthSoldierMaintainList* Game::getEarthSoldierMaintainList() const { return (EarthSoldierMaintainList*) &soldierMaintain;  }

bool Game::generateOutput() {
    ofstream file(outputFile, 'w');
    if (!file.is_open()) {
        cout << "Error Creating File. " << endl;
        return false;
    }

    int totalDfEarth = 0, totalDdEarth = 0, totalDbEarth = 0;
    int ESDestructed = 0, ETDestructed = 0, EGDestructed = 0, HUDestructed = 0;

    int totalDfAlien = 0, totalDdAlien = 0, totalDbAlien = 0;
    int ASDestructed = 0, AMDestructed = 0, ADDestructed = 0;

 
    file << "Td ID Tj Df Dd Db" << endl;
    Unit* unit;
    bool isEarth;
    while (killed.remove(unit)) {
        file << *unit << endl;

        switch (unit->getType()) {
        case E_GUNNERY:
            EGDestructed++;
            isEarth = true;
            break;
        case E_HEAL:
            HUDestructed++;
            isEarth = true;
            break;
        case E_SOLDIER:
            ESDestructed++;
            isEarth = true;
            break;
        case E_TANK:
            ETDestructed++;
            isEarth = true;
            break;
        case A_SOLDIER:
            ASDestructed++;
            isEarth = false;
            break;
        case A_MONSTER:
            AMDestructed++;
            isEarth = false;
            break;
        case A_DRONE:
            ADDestructed++;
            isEarth = false;
            break;
        }

        if (isEarth) {
            totalDfEarth += unit->getFirstAttackDelay();
            totalDdEarth += unit->getDestructionTime();
            totalDbEarth += unit->getBattleTime();
        }
        else {
            totalDfAlien += unit->getFirstAttackDelay();
            totalDdAlien += unit->getDestructionTime();
            totalDbAlien += unit->getBattleTime();
        }
    }

    float totalEarthDestructed = EGDestructed + ESDestructed + ETDestructed + HUDestructed;
    float totalAliensDestructed = ASDestructed + AMDestructed + ADDestructed;

    file << "Battle Result: ";

    switch (won) {
    case EARTH:
        file << "Win" << endl;
        break;
    case ALIENS:
        file << "Loss" << endl;
        break;
    case DRAW:
        file << "Draw" << endl;
        break;
    default:
        file << "TBD" << endl;
    }

    int ESCount = earth.getESList()->getCount();
    int EGCount = earth.getEGList()->getCount();
    int ETCount = earth.getETList()->getCount();
    int HUCount = heal.getCount();
    float EarthTotal = ESCount + EGCount + ETCount + HUCount + totalEarthDestructed;


    file << endl << endl << "EARTH ARMY STATS: " << endl;
    file << "ES: " << ESCount << endl;
    file << "ET: " << ETCount << endl;
    file << "EG: " << EGCount << endl;
    file << "HU: " << HUCount << endl;

    file << endl << "% Destructed ES: " << ESDestructed / ESCount * 100;
    file << endl << "% Destructed ET: " << ETDestructed / ETCount * 100;
    file << endl << "% Destructed EG: " << EGDestructed / EGCount * 100;
    file << endl << "% Destructed HU: " << HUDestructed / HUCount * 100 << endl;


    file << endl << "% Destructed: " << totalEarthDestructed / EarthTotal * 100 << endl;

    file << endl << "Average Df: " << totalDfEarth / totalEarthDestructed * 100;
    file << endl << "Average Dd: " << totalDdEarth / totalEarthDestructed * 100;
    file << endl << "Average Db: " << totalDbEarth / totalEarthDestructed * 100 << endl;


    file << "%Df/Db: " << totalDfEarth / (float)totalDbEarth * 100 << endl;
    file << "%Dd/Db: " << totalDdEarth / (float)totalDbEarth * 100 << endl << endl;


    int ASCount = aliens.getASList()->getCount();
    int AMCount = aliens.getAMList()->getCount();
    int ADCount = aliens.getADList()->getCount();
    float AliensTotal = ASCount + AMCount + ADCount + totalAliensDestructed;

    file << endl << endl << "ALIEN ARMY STATS: " << endl;
    file << "AS: " << ASCount << endl;
    file << "AM: " << AMCount << endl;
    file << "AD: " << ADCount << endl;

    file << endl << "% Destructed AS: " << ASDestructed / ASCount * 100;
    file << endl << "% Destructed AM: " << AMDestructed / AMCount * 100;
    file << endl << "% Destructed AD: " << ADDestructed / ADCount * 100;


    file << endl << "% Destructed: " << totalAliensDestructed / AliensTotal * 100 << endl;

    file << endl << "Average Df: " << totalDfAlien / totalAliensDestructed * 100;
    file << endl << "Average Dd: " << totalDdAlien / totalAliensDestructed * 100;
    file << endl << "Average Db: " << totalDbAlien / totalAliensDestructed * 100 << endl;


    file << "%Df/Db: " << totalDfAlien / (float)totalDbAlien * 100 << endl;
    file << "%Dd/Db: " << totalDdAlien / (float)totalDbAlien * 100 << endl << endl;


    return true;
}
