#pragma once
#include "QueueADT.h"

template <class T>
class DequeADT : public QueueADT<T> {
   public:
    virtual bool enqueueFront(const T& newEntry) = 0;

    virtual bool dequeueBack(T& backEntry) = 0;

    virtual bool peekBack(T& backEntry) const = 0;

    virtual ~DequeADT() {}
};