#pragma once

template <class T>
class QueueADT {
   public:
    virtual bool isEmpty() const = 0;

    virtual int getCount() const = 0;

    virtual bool enqueue(const T& newEntry) = 0;

    virtual bool dequeue(T& frontEntry) = 0;

    virtual bool peek(T& frontEntry) const = 0;

    virtual void print() const = 0;

    virtual ~QueueADT() {}
};