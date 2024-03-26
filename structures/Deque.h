#pragma once

#include <iostream>

#include "DequeADT.h"
#include "DoublyNode.h"

template <typename T>
class Deque : public DequeADT<T> {
   private:
    DoublyNode<T>* frontPtr;
    DoublyNode<T>* backPtr;
    int count;

   public:
    Deque() : frontPtr(nullptr), backPtr(nullptr), count(0) {}

    int getCount() const override { return count; }
    bool isEmpty() const override { return count == 0; }

    bool enqueueFront(const T& newEntry) override {
        DoublyNode<T>* newNodePtr = new DoublyNode<T>(newEntry);
        if (isEmpty()) {
            frontPtr = newNodePtr;
            backPtr = newNodePtr;
        } else {
            newNodePtr->setNext(frontPtr);
            frontPtr->setPrev(newNodePtr);
            frontPtr = newNodePtr;
        }
        count++;
        return true;
    }

    bool enqueue(const T& newEntry) override {
        DoublyNode<T>* newNodePtr = new DoublyNode<T>(newEntry);
        if (isEmpty()) {
            frontPtr = newNodePtr;
            backPtr = newNodePtr;
        } else {
            newNodePtr->setPrev(backPtr);
            backPtr->setNext(newNodePtr);
            backPtr = newNodePtr;
        }
        count++;
        return true;
    }

    bool dequeue(T& frontEntry) override {
        if (isEmpty()) return false;

        DoublyNode<T>* nodeToDeletePtr = frontPtr;
        frontEntry = nodeToDeletePtr->getItem();
        if (frontPtr == backPtr) {
            frontPtr = nullptr;
            backPtr = nullptr;
        } else {
            frontPtr = frontPtr->getNext();
            frontPtr->setPrev(nullptr);
        }
        delete nodeToDeletePtr;
        count--;
        return true;
    }

    bool dequeueBack(T& backEntry) override {
        if (isEmpty()) return false;

        DoublyNode<T>* nodeToDeletePtr = backPtr;
        backEntry = nodeToDeletePtr->getItem();
        if (frontPtr == backPtr) {
            frontPtr = nullptr;
            backPtr = nullptr;
        } else {
            backPtr = backPtr->getPrev();
            backPtr->setNext(nullptr);
        }
        delete nodeToDeletePtr;
        count--;
        return true;
    }

    bool peek(T& frontEntry) const override {
        if (isEmpty()) return false;
        frontEntry = frontPtr->getItem();
        return true;
    }

    bool peekBack(T& backEntry) const override {
        if (isEmpty()) return false;
        backEntry = backPtr->getItem();
        return true;
    }

    void print() const override {
        DoublyNode<T>* current = frontPtr;
        cout << "[";
        while (current) {
            if constexpr (std::is_pointer_v<T>)
                cout << *current->getItem();
            else
                cout << current->getItem();
            if (current != backPtr) cout << ", ";
            current = current->getNext();
        }
        cout << "]" << endl;
    }

    ~Deque() {
        T temp;
        while (dequeue(temp))
            ;
    }
};