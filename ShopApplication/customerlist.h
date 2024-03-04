
#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H


#include "customer.h"
#include <QList>

class CustomerList
{
public:
    CustomerList();

    void append(Customer* c);

    QList<Customer*> getCustomers();

private:
    QList<Customer*> customers;
};

#endif // CUSTOMERLIST_H
