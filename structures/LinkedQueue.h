#pragma once

#include "Node.h"
#include "QueueADT.h"

template <typename T>
class LinkedQueue : public QueueADT<T> {
   private:
    Node<T>* backPtr;
    Node<T>* frontPtr;
    int count;

   public:
    LinkedQueue() {
        backPtr = nullptr;
        frontPtr = nullptr;
        count = 0;
    }

    int getCount() const override { return count; }

    bool isEmpty() const override { return (frontPtr == nullptr); }

    bool enqueue(const T& newEntry) override {
        Node<T>* newNodePtr = new Node<T>(newEntry);
        if (isEmpty())
            frontPtr = newNodePtr;
        else
            backPtr->setNext(newNodePtr);

        backPtr = newNodePtr;
        count++;
        return true;
    }

    bool dequeue(T& frontEntry) override {
        if (isEmpty()) return false;

        Node<T>* nodeToDeletePtr = frontPtr;
        frontEntry = frontPtr->getItem();
        frontPtr = frontPtr->getNext();
        if (nodeToDeletePtr == backPtr) backPtr = nullptr;

        delete nodeToDeletePtr;
        count--;
        return true;
    }

    bool peek(T& frontEntry) const override {
        if (isEmpty()) return false;

        frontEntry = frontPtr->getItem();
        return true;
    }

    void printQueue() const override {
        Node<T>* temp = frontPtr;
        cout << "[";
        while (temp != nullptr) {
            cout << temp->getItem();
            if (temp->getNext() != nullptr) cout << ", ";
            temp = temp->getNext();
        }
        cout << "]" << endl;
    }

    ~LinkedQueue() {
        T temp;
        while (dequeue(temp))
            ;
    }
};
