#include "../game.h"
#include "../units/AlienDrone.h"
#include "../units/AlienMonster.h"
#include "../units/AlienSoldier.h"
#include "../units/EarthGunnery.h"
#include "../units/EarthSoldier.h"
#include "../units/EarthTank.h"
#include "AlienDroneList.h"
#include "AlienMonsterList.h"
#include "AlienSoldierList.h"
#include "EarthGunneryList.h"
#include "EarthSoldierList.h"
#include "EarthTankList.h"
#include "KilledList.h"

int main() {
    Game game;
    EarthSoldier eSoldier1(1, 0, 100, 20, 2, &game);
    EarthSoldier eSoldier2(2, 0, 100, 20, 2, &game);
    EarthSoldier eSoldier3(3, 0, 100, 20, 2, &game);
    EarthSoldier eSoldier4(4, 0, 100, 20, 2, &game);
    EarthSoldier eSoldier5(5, 0, 100, 20, 2, &game);

    EarthGunnery gunnery1(6, 0, 50, 60, 2, &game);
    EarthGunnery gunnery2(7, 0, 100, 5, 2, &game);
    EarthGunnery gunnery3(8, 0, 80, 10, 2, &game);
    EarthGunnery gunnery4(9, 0, 20, 30, 2, &game);
    EarthGunnery gunnery5(10, 0, 5, 30, 2, &game);

    EarthTank tank1(11, 0, 100, 20, 2, &game);
    EarthTank tank2(12, 0, 100, 20, 2, &game);
    EarthTank tank3(13, 0, 100, 20, 2, &game);
    EarthTank tank4(14, 0, 100, 20, 2, &game);
    EarthTank tank5(15, 0, 100, 20, 2, &game);

    AlienSoldier aSoldier1(16, 0, 100, 20, 2, &game);
    AlienSoldier aSoldier2(17, 0, 100, 20, 2, &game);
    AlienSoldier aSoldier3(18, 0, 100, 20, 2, &game);
    AlienSoldier aSoldier4(19, 0, 100, 20, 2, &game);
    AlienSoldier aSoldier5(20, 0, 100, 20, 2, &game);

    AlienMonster monster1(21, 0, 100, 20, 2, &game);
    AlienMonster monster2(22, 0, 100, 20, 2, &game);
    AlienMonster monster3(23, 0, 100, 20, 2, &game);
    AlienMonster monster4(24, 0, 100, 20, 2, &game);
    AlienMonster monster5(25, 0, 100, 20, 2, &game);

    AlienDrone drone1(26, 0, 100, 20, 2, &game);
    AlienDrone drone2(27, 0, 100, 20, 2, &game);
    AlienDrone drone3(28, 0, 100, 20, 2, &game);
    AlienDrone drone4(29, 0, 100, 20, 2, &game);
    AlienDrone drone5(30, 0, 100, 20, 2, &game);
    AlienDrone drone6(31, 0, 100, 20, 2, &game);

    EarthSoldierList earthSoldierList;
    EarthGunneryList earthGunneryList;
    EarthTankList earthTankList;

    AlienSoldierList alienSoldierList;
    AlienMonsterList monsterList;
    AlienDroneList droneList;

    KilledList deathList;

    earthSoldierList.add(&eSoldier1);
    earthSoldierList.add(&eSoldier2);
    earthSoldierList.add(&eSoldier3);
    earthSoldierList.add(&eSoldier4);
    earthSoldierList.add(&eSoldier5);

    earthGunneryList.add(&gunnery1);
    earthGunneryList.add(&gunnery2);
    earthGunneryList.add(&gunnery3);
    earthGunneryList.add(&gunnery4);
    earthGunneryList.add(&gunnery5);

    earthTankList.add(&tank1);
    earthTankList.add(&tank2);
    earthTankList.add(&tank3);
    earthTankList.add(&tank4);
    earthTankList.add(&tank5);

    cout << "\n\nEARTH UNITS: \n";
    earthSoldierList.print();
    earthGunneryList.print();
    earthTankList.print();

    alienSoldierList.add(&aSoldier1);
    alienSoldierList.add(&aSoldier2);
    alienSoldierList.add(&aSoldier3);
    alienSoldierList.add(&aSoldier4);
    alienSoldierList.add(&aSoldier5);

    monsterList.add(&monster1);
    monsterList.add(&monster2);
    monsterList.add(&monster3);
    monsterList.add(&monster4);
    monsterList.add(&monster5);

    droneList.add(&drone1, &drone2);
    droneList.add(&drone3, &drone4);
    droneList.add(&drone5, &drone6);

    cout << "\n\nALIEN UNITS: \n";
    alienSoldierList.print();
    monsterList.print();
    droneList.print();

    AlienSoldier* rmASoldier;
    AlienMonster* rmMonster;
    AlienDrone* rmDrone1;
    AlienDrone* rmDrone2;
    EarthSoldier* rmESoldier;
    EarthGunnery* rmGunnery;
    EarthTank* rmTank;

    alienSoldierList.remove(rmASoldier);
    monsterList.remove(rmMonster);
    droneList.remove(rmDrone1, rmDrone2);
    earthSoldierList.remove(rmESoldier);
    earthGunneryList.remove(rmGunnery);
    earthTankList.remove(rmTank);

    cout << "\n\nEARTH UNITS: \n";
    earthSoldierList.print();
    earthGunneryList.print();
    earthTankList.print();

    cout << "\n\nALIEN UNITS: \n";
    alienSoldierList.print();
    monsterList.print();
    droneList.print();

    deathList.add(rmASoldier);
    deathList.add(rmMonster);
    deathList.add(rmDrone1);
    deathList.add(rmDrone2);
    deathList.add(rmESoldier);
    deathList.add(rmGunnery);
    deathList.add(rmTank);

    cout << "\n\n";
    deathList.print();
    cout << "\n\n";

    Unit* unit;
    deathList.remove(unit);
    deathList.print();

    return 0;
}