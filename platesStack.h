#ifndef __STACK_H
#define __STACK_H
#include "Order.cpp"

//This is the generic Stack class 

template <class T>
class platesStack
{
  Order<T> list;

  public:

    platesStack();

    platesStack(platesStack<T>& otherplatesStack);

    ~platesStack();

    void pushPlate(T item);

    T topPlate();

    T popPlate();

    bool noPlates();

    int nnumberOfPlates();

};

#endif
