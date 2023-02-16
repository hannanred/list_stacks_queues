#ifndef __LIST_H
#define __LIST_H
#include <cstdlib>

//This class holds details of a single order.

template <class T>
struct OrderDetails
{
    T value;
    OrderDetails<T> *next;
    OrderDetails<T> *prev;
    // OrderDetails()
    // {
    //     this->next = NULL;
    //     this->prev = NULL;
    // }
    OrderDetails(T orderValue)
    {
        this->value = orderValue;
        this->next = NULL;
        this->prev = NULL;
    }

};

//This is the generic List class 
template <class T>
class Order
{
    OrderDetails<T> *FirstOrder;
    OrderDetails<T> *LastOrder;

public:

    Order();

    Order(const Order<T>& otherOrder);

    ~Order();

    void insertFirstOrder(T item);

    void insertLastOrder(T item);

    void insertAfter(T newOrder, T afterOrder);

    OrderDetails<T> *getFirstOrder();

    OrderDetails<T> *getLastOrder();

    OrderDetails<T> *searchForOrder(T item);

    void deleteOrder(T item);

    void deleteFirstOrder();
    
    void deleteLastOrder();

    int numberOfOrders();
};

#endif
