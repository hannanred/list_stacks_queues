#ifndef __QUEUE_CPP
#define __QUEUE_CPP

#include "pickUp.h"

template <class T>
pickUp<T>::pickUp()
{
	list;
}
    
template <class T>
pickUp<T>::pickUp(pickUp<T>& otherpickUp)
{
	 list = otherpickUp.list;
}

template <class T>
pickUp<T>::~pickUp()
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
void pickUp<T>::enqueue(T item)
{
	list.insertLastOrder(item);
}

template <class T>
T pickUp<T>::front()
{
	return list.getFirstOrder()->value;
}

template <class T>
T pickUp<T>::dequeue()
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
int pickUp<T>::lengthpickUp()
{
	return list.numberOfOrders();
}

template <class T>
bool pickUp<T>::isEmpty()
{
	if(list.getFirstOrder() == NULL){
	
		return true;
}

	else {

		return false;
	}
}

#endif
