#include "EarthSoldierList.h"

bool EarthSoldierList::add(EarthSoldier* unit) { 
    if (!unit) return false;
    return queue.enqueue(unit); }

bool EarthSoldierList::remove(EarthSoldier*& unit) {
    return queue.dequeue(unit);
}

void EarthSoldierList::print() {
    int count = queue.getCount();
    cout << count << " ES ";
    queue.print();
}
bool EarthSoldierList::isEmpty(){
    return queue.isEmpty();
}
int EarthSoldierList::getCount(){
    return queue.getCount();
}
bool EarthSoldierList::peek(EarthSoldier* unit){
    return queue.peek(unit);
}