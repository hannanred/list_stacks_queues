#ifndef __LIST_CPP
#define __LIST_CPP

#include "Order.h"

#include <cstdlib>
#include <iostream>
using namespace std;


template <class T>
Order<T>::Order()
{

	FirstOrder = NULL;
	LastOrder = NULL;

}

template <class T>
Order<T>::Order(const Order<T>& otherOrder)
{
	FirstOrder = NULL;
	LastOrder = NULL;
	OrderDetails<T> *p = new OrderDetails<T>;
	p = otherOrder.FirstOrder;
	insertFirstOrder(p->value);
	LastOrder = FirstOrder;
	p = p->next;
	while (p!= NULL)
	{
		insertLastOrder(p->value);
		p = p->next;
	} 
	p = NULL;
	delete p;
	
}
template <class T>
Order<T>::~Order()
{

	OrderDetails<T> *p = new OrderDetails<T>;
	p=FirstOrder;
	while (p!= NULL)
	{

		FirstOrder= FirstOrder->next;
		delete p;
		p = FirstOrder;
	}
	


}

template <class T>
void Order<T>::insertFirstOrder(T item)
{
	OrderDetails<T> *p = new OrderDetails<T>;
	p->value = item;
	if (FirstOrder == NULL)
	{

		p->next = NULL;
		p->prev = NULL;
		FirstOrder = p;
		LastOrder = p;
	}
	else if (FirstOrder != NULL)
	{
	
		p->next = FirstOrder;
		p-> prev = NULL;
		FirstOrder->prev = p;
		FirstOrder = p;
	}
	p = NULL;
	delete p;
	
}

template <class T>
void Order<T>::insertLastOrder(T item)
{
	OrderDetails<T> *p = new OrderDetails<T>;
	if (FirstOrder == NULL)
	{
		p->value = item;
		p->next = NULL;
		p->prev = NULL;
		FirstOrder = p;
		LastOrder = p;
	}
	else {
		p->value = item;
		p->next = NULL;
		p->prev = LastOrder;
		LastOrder->next = p;
		LastOrder = p;
	}
	 p = NULL;
	 delete p;
}

template <class T>
void Order<T>::insertAfter(T newOrder, T afterOrder)
{
	OrderDetails<T> *p = new OrderDetails<T>;
	OrderDetails<T> *temp = new OrderDetails<T>;
	p->value = newOrder;
	temp= FirstOrder;
	while( temp->next != NULL )
	{
		if(temp->value == afterOrder)
		{
			break;
		}
		temp=temp->next;
	}
	if(temp->value !=afterOrder)
	{
		cout <<"afterorder does not exist";
		return;
	}
	{
		p->next = temp-> next;
		p->prev = temp;
		temp->next = p;
	}
	p = NULL;
	temp = NULL;
	delete p;
	delete temp;
	// delete p;
	// delete temp;
}

template <class T>
OrderDetails<T>* Order<T>::getFirstOrder()
{
	return FirstOrder;
}

template <class T>
OrderDetails<T>* Order<T>::getLastOrder()
{
	return LastOrder;
}

template <class T>
OrderDetails<T> *Order<T>::searchForOrder(T item)
{
	//cout << "a" << endl;
	OrderDetails<T> *temp = new OrderDetails<T>;
	temp = getFirstOrder();
		//cout << "b" << endl;

	while( temp->next != NULL )
	{
		if(temp->value == item)
		{
			break;
		}
		temp=temp->next;
	}
		//cout << "c" << endl;

	if (temp->value == item)
	{
		return temp;
	}
	else
	{
		return NULL;
	}
		//cout << "d" << endl;

	temp = NULL;
	delete temp;
}

template <class T>
void Order<T>::deleteOrder(T item)
{
	OrderDetails<T> *temp = new OrderDetails<T>;    
	// cout << temp->value;
	 if(FirstOrder->value == item)
  {
  	deleteFirstOrder();
  }
  
 else if (LastOrder->value == item)
  {
            deleteLastOrder();
  }
         
  else {
  	//cout << "A" << endl;
  	 	temp = searchForOrder(item);
  	//cout << "B" << endl;
         temp->next->prev = temp->prev;
       // cout << "C" << endl;
         temp->prev->next = temp->next;
       
         temp = NULL;
		delete temp;            
    }
}

template <class T>
void Order<T>::deleteFirstOrder()
{
	if (FirstOrder == NULL)
	{
		return;
	}
	else if(FirstOrder != NULL)
	{
		if (FirstOrder == LastOrder)
		{
			delete FirstOrder;
			LastOrder = FirstOrder = NULL;
		}
		else
		{	
			OrderDetails<T> *temp = new OrderDetails<T>;
			temp = FirstOrder;
			FirstOrder = FirstOrder->next;
			FirstOrder->prev = NULL;
			delete temp;
		}
	}
}

template <class T>
void Order<T>::deleteLastOrder()
{
	if (FirstOrder == LastOrder)
		{
			deleteFirstOrder();
		}
	else
		{
			OrderDetails<T> *temp = new OrderDetails<T>;
			temp = LastOrder;
			LastOrder = LastOrder->prev;
			LastOrder->next = NULL;
			delete temp;
		}


}

template <class T>
int Order<T>::numberOfOrders()
{
	int i = 1;
	if(FirstOrder == NULL)
	{
		i = 0;
		return i;
	}
	else {
		OrderDetails<T> *temp = new OrderDetails<T>;
		temp = FirstOrder;
		while(temp->next != NULL)
		{
			i = i+1;
			temp=temp->next;
		}
		return i;
		//delete temp;
	}
}

 int main()
 {
  
 	return 0;

 }


#endif
