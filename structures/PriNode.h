#pragma once

template <typename T>
class PriNode {
   private:
    T item;
    int pri;
    PriNode<T>* next;

   public:
    PriNode(const T& r_Item, int PRI) {
        setItem(r_Item, PRI);
        next = nullptr;
    }
    void setItem(const T& r_Item, int PRI) {
        item = r_Item;
        pri = PRI;
    }
    void setNext(PriNode<T>* nextNodePtr) { next = nextNodePtr; }

    T getItem(int& PRI) const {
        PRI = pri;
        return item;
    }

    PriNode<T>* getNext() const { return next; }

    int getPri() const { return pri; }
};
