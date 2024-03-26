#include <iostream>

#include "ArrayBag.h"
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
    ArrayBag<int> arrayBag;

    int item;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout << endl << "Stack: " << stack.getCount() << endl;
    stack.print();

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    cout << endl << "Queue: " << queue.getCount() << endl;
    queue.print();

    priQueue.enqueue(1, 1);
    priQueue.enqueue(3, 1);
    priQueue.enqueue(2, 2);
    priQueue.enqueue(4, 1);
    priQueue.enqueue(5, 2);

    cout << endl << "Priority Queue: " << priQueue.getCount() << endl;
    priQueue.print();

    cout << endl << "Deque: " << endl;
    deque.enqueueFront(1);
    deque.print();
    deque.enqueue(2);
    deque.print();
    deque.enqueueFront(3);
    deque.print();

    deque.peek(item);
    cout << "Front Item: " << item << endl;
    deque.peekBack(item);
    cout << "Back item: " << item << endl;

    deque.dequeueBack(item);

    cout << endl;
    deque.print();
    cout << deque.getCount() << endl;

    deque.peek(item);
    cout << "Front Item: " << item << endl;
    deque.peekBack(item);
    cout << "Back item: " << item << endl;

    deque.dequeue(item);

    cout << endl;
    deque.print();

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
    deque.print();

    cout << "---- ARRAY BAG ----" << endl;
    arrayBag.add(1);
    arrayBag.add(2);
    arrayBag.add(3);
    arrayBag.add(4);
    arrayBag.add(5);
    arrayBag.add(6);

    arrayBag.print();

    return 0;
}