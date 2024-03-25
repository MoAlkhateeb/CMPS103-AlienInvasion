#include <iostream>

#include "ArrayStack.h"
#include "Deque.h"
#include "LinkedQueue.h"
#include "PriQueue.h"

using namespace std;

int main() {
    ArrayStack<int> stack;
    LinkedQueue<int> queue;
    PriQueue<int> priQueue;
    Deque<int> deque;

    int item;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout << endl << "Stack: " << stack.getCount() << endl;
    stack.printStack();

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    cout << endl << "Queue: " << queue.getCount() << endl;
    queue.printQueue();

    priQueue.enqueue(1, 1);
    priQueue.enqueue(2, 2);
    priQueue.enqueue(3, 1);
    priQueue.enqueue(4, 1);
    priQueue.enqueue(5, 2);

    cout << endl << "Priority Queue: " << priQueue.getCount() << endl;
    priQueue.printQueue();

    cout << endl << "Deque: " << endl;
    deque.enqueueFront(1);
    deque.printQueue();
    deque.enqueue(2);
    deque.printQueue();
    deque.enqueueFront(3);
    deque.printQueue();

    deque.peek(item);
    cout << "Front Item: " << item << endl;
    deque.peekBack(item);
    cout << "Back item: " << item << endl;

    deque.dequeueBack(item);

    cout << endl;
    deque.printQueue();

    deque.peek(item);
    cout << "Front Item: " << item << endl;
    deque.peekBack(item);
    cout << "Back item: " << item << endl;

    deque.dequeue(item);

    cout << endl;
    deque.printQueue();

    deque.peek(item);
    cout << "Front Item: " << item << endl;
    deque.peekBack(item);
    cout << "Back item: " << item << endl;

    deque.dequeue(item);
    deque.dequeue(item);
    deque.dequeue(item);
    deque.dequeueBack(item);
    deque.dequeueBack(item);
    deque.dequeueBack(item);

    cout << endl << "Deque: " << deque.getCount() << endl;
    deque.printQueue();

    return 0;
}