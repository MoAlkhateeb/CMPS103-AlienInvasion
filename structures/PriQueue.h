#pragma once

#include <iostream>

#include "PriNode.h"

using namespace std;

template <typename T>
class PriQueue {
    PriNode<T>* head;
    int count;

   public:
    PriQueue() : head(nullptr), count(0) {}

    ~PriQueue() {
        T tmp;
        int p;
        while (dequeue(tmp, p));
    }

    int getCount() const { return count; }

    void enqueue(const T& data, int priority) {
        PriNode<T>* newNode = new PriNode<T>(data, priority);
        count++;

        if (head == nullptr || priority > head->getPri()) {
            newNode->setNext(head);
            head = newNode;
            return;
        }

        PriNode<T>* current = head;
        while (current->getNext() && priority <= current->getNext()->getPri()) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }

    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty()) return false;

        topEntry = head->getItem(pri);
        PriNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        count--;
        return true;
    }

    bool peek(T& topEntry, int& pri) {
        if (isEmpty()) return false;

        topEntry = head->getItem();
        pri = head->getPri();
        return true;
    }

    bool isEmpty() const { return count == 0; }

    void print() const {
        PriNode<T>* current = head;
        int p;
        cout << "[";
        while (current) {
            if constexpr (std::is_pointer_v<T>)
                cout << *current->getItem(p);
            else
                cout << current->getItem(p);
            if (current->getNext()) {
                cout << ", ";
            }
            current = current->getNext();
        }
        cout << "]" << endl;
    }
};