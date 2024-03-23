#include <iostream>

#include "ArrayStack.h"
#include "LinkedQueue.h"
#include "PriQueue.h"

using namespace std;

int main() {
    ArrayStack<int> stack;
    LinkedQueue<int> queue;
    PriQueue<int> priQueue;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout << "Stack: " << stack.getCount() << endl;
    stack.printStack();

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    cout << "Queue: " << queue.getCount() << endl;
    queue.printQueue();

    priQueue.enqueue(1, 1);
    priQueue.enqueue(2, 2);
    priQueue.enqueue(3, 1);
    priQueue.enqueue(4, 1);
    priQueue.enqueue(5, 2);

    cout << "Priority Queue: " << priQueue.getCount() << endl;
    priQueue.printQueue();

    return 0;
}