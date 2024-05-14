#pragma once

template <typename T>
class DoublyNode {
   private:
    T item;
    DoublyNode<T>* next;
    DoublyNode<T>* prev;

   public:
    DoublyNode() : next(nullptr), prev(nullptr) {}

    DoublyNode(const T& r_Item, DoublyNode<T>* nextNodePtr = nullptr,
               DoublyNode<T>* prevNodePtr = nullptr) {
        item = r_Item;
        next = nextNodePtr;
        prev = prevNodePtr;
    }

    void setItem(const T& r_Item) { item = r_Item; }

    void setNext(DoublyNode<T>* nextNodePtr) { next = nextNodePtr; }

    void setPrev(DoublyNode<T>* prevNodePtr) { prev = prevNodePtr; }

    T getItem() const { return item; }

    DoublyNode<T>* getNext() const { return next; }

    DoublyNode<T>* getPrev() const { return prev; }
};