#include <iostream>
#include <random>

#include "BagADT.h"

using namespace std;

template <typename T>
class ArrayBag : BagADT<T> {
   private:
    enum { MAX_SIZE = 1000 };

    T* array;
    int count;

    int getRandomIndex() const {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, count - 1);
        return dis(gen);
    }

   public:
    ArrayBag() : count(0) { array = new T[MAX_SIZE]; }

    bool add(const T& newEntry) override {
        if (count >= MAX_SIZE) return false;
        array[count++] = newEntry;
        return true;
    }

    bool removeRandom(T& randomEntry) override {
        if (isEmpty()) return false;
        int removeIndex = getRandomIndex();
        randomEntry = array[removeIndex];
        array[removeIndex] = array[count - 1];
        count--;
        return true;
    }

    void print() const override {
        cout << "[";
        for (int i = 0; i < count; i++) {
            if constexpr (std::is_pointer_v<T>)
                cout << *array[i];
            else
                cout << array[i];

            if (i != count - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    bool isEmpty() const override { return count == 0; }

    int getCount() const override { return count; }

    ~ArrayBag() { delete array; }
};