#pragma once

#include <iostream>

#include "StackADT.h"

using namespace std;

template <typename T>
class ArrayStack : public StackADT<T> {
    enum { MAX_SIZE = 1000 };

   private:
    T items[MAX_SIZE];
    int top, count;

   public:
    ArrayStack() : top(-1), count(0) {}

    bool isEmpty() const override { return count == 0; }

    int getCount() const override { return count; }

    bool push(const T& newEntry) override {
        if (top == MAX_SIZE - 1) return false;

        top++;
        items[top] = newEntry;
        count++;
        return true;
    }

    bool pop(T& TopEntry) override {
        if (isEmpty()) return false;

        TopEntry = items[top];
        top--;
        count--;
        return true;
    }

    bool peek(T& TopEntry) const override {
        if (isEmpty()) return false;

        TopEntry = items[top];
        return true;
    }

    virtual void print() const override {
        T x;
        cout << "[";
        for (int i = top; i >= 0; i--) {
            x = items[i];
            if constexpr (std::is_pointer_v<T>)
                cout << *x;
            else
                cout << x;
            if (i > 0) cout << ", ";
        }
        cout << "]" << endl;
    }
};
