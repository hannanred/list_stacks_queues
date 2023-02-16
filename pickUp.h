#ifndef __QUEUE_H
#define __QUEUE_H

#include "Order.cpp"

// This is the Queue class.
template <class T>
class pickUp
{
  
  Order<T> list;

  public:

    pickUp();

    pickUp(pickUp<T>& otherpickUp);

    ~pickUp();

    void enqueue(T item);

    T front();

    T dequeue();

    int lengthpickUp();

    bool isEmpty();
};

#endif
