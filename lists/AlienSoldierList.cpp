#include "AlienSoldierList.h"

bool AlienSoldierList::add(AlienSoldier* unit) { 
    if (!unit) return false;
    return queue.enqueue(unit); 
}

bool AlienSoldierList::remove(AlienSoldier*& unit) {
    return queue.dequeue(unit);
}

void AlienSoldierList::print() {
    int count = queue.getCount();
    cout << count << " AS ";
    queue.print();
}
bool AlienSoldierList::isEmpty(){
    return queue.isEmpty();
}
int AlienSoldierList::getCount(){
    return queue.getCount();
}
bool AlienSoldierList::peek(AlienSoldier* unit){
    return queue.peek(unit);
}