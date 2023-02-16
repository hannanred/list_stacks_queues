#ifndef __platesStack_CPP
#define __STACK_CPP
#include "platesStack.h"


#include <iostream>
using namespace std;

template <class T>
platesStack<T>::platesStack()
{		
	list;
}
    
template <class T>
platesStack<T>::platesStack(platesStack<T>& otherplatesStack)
{

	 list = otherplatesStack.list;

}

template <class T>
platesStack<T>::~platesStack()
{
	OrderDetails<T> *p = new OrderDetails<T>;
	p=list.getFirstOrder();
	while (p!= NULL)
	{
		delete p;
		p = p->next;
	}
	

}

template <class T>
void platesStack<T>::pushPlate(T item)
{
	list.insertFirstOrder(item);
}

template <class T>
T platesStack<T>::topPlate()
{
	return list.getFirstOrder()->value;
}

template <class T>
T platesStack<T>::popPlate()
{
	OrderDetails<T> *temp = new OrderDetails<T>;
	temp = list.getFirstOrder();
	T var = temp->value;
	temp = NULL;
	delete temp;
	list.deleteFirstOrder();
	return var;
	
}

template <class T>
bool platesStack<T>::noPlates()
{

	if(list.getFirstOrder() == NULL){
	
		return true;
}

	else {

		return false;
	}
}

template <class T>
int platesStack<T>::nnumberOfPlates()
{
	return list.numberOfOrders();
}

#endif
