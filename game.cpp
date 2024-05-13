#include "game.h"

int RandGen::earthID = MINEARTHID;
int RandGen::alienID = MINALIENID;

bool Game::loadParameters(const string &filename) {
    ifstream file(filename);

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
    int ESPercent, ETPercent, EGPercent;
    int ASPercent, AMPercent, ADPercent;
    range EPower, EHealth, EAttack;
    range APower, AHealth, AAttack;
    int generateProb;

    file >> N;
    file >> ESPercent >> ETPercent >> EGPercent;
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

Game::Game(const string &inputFile): randGen(this), timeStep(0) {
    bool loaded = loadParameters(inputFile);

    if (!loaded) {
        cout << "Could not load file: " << inputFile << endl;
        exit(1);
    }
}


void Game::runInteractive() {
    // This does phase 1.2 test code for now.

    int X;
    for (; timeStep < 50; timeStep++) {
        randGen.createUnits(timeStep);

        X = randGen.getRandomNumber();

        if (X < 10) {
            EarthSoldier* ES;
            EarthSoldierList* ESList = earth.getESList();
            if (ESList->remove(ES))
                ESList->add(ES);
        }
        else if (X < 20) {
            EarthTank* ET;
            EarthTankList* ETList = earth.getETList();
            if (ETList->remove(ET))
                killed.add(ET); 
        }
        else if (X < 30) {
            EarthGunnery* EG;
            EarthGunneryList* EGList = earth.getEGList();
            if (EGList->remove(EG)) {
                EG->setHealth(EG->getHealth() / 2);
                EGList->add(EG);
            }
        }
        else if (X < 40) {
            LinkedQueue<AlienSoldier*> tempList;
            AlienSoldierList* ASList = aliens.getASList();

            AlienSoldier* AS;
            for (int i = 0; i < 5; i++) {
                if (ASList->remove(AS)) {
                    AS->setHealth(AS->getHealth() - 1);
                    tempList.enqueue(AS);
                }
            }

            for (int i = 0; i < 5; i++) {
                if(tempList.dequeue(AS))
                    ASList->add(AS);
            }
        }
        else if (X < 50) {
            AlienMonsterList* AMList = aliens.getAMList();
            
            AlienMonster* AM;
            for (int i = 0; i < 5; i++) {
                if (AMList->remove(AM))
                    AMList->add(AM);
            }
        }
        else if (X < 60) {
            AlienDroneList* ADList = aliens.getADList();
            AlienDrone* begin, *end;
            for (int i = 0; i < 3; i++) {
                if (ADList->remove(begin, end)) {
                    killed.add(begin);
                    killed.add(end);
                }
            }
        }

        print();
    }
}

void Game::print() {
    cout << "Current Timestep " << timeStep << endl;
    earth.print();
    cout << endl;
    aliens.print();
    cout << endl;
    killed.print();
    cout << endl << endl;
}

EarthArmy* Game::getEarthArmy() const { return (EarthArmy*) &earth; }

AlienArmy* Game::getAlienArmy() const { return (AlienArmy*) &aliens; }

KilledList* Game::getKilled() const { return (KilledList*) &killed; }
