
#include "customerlist.h"

CustomerList::CustomerList()
{

}

void CustomerList::append(Customer *c)
{
    customers.append(c);
}

QList<Customer *> CustomerList::getCustomers()
{
    return customers;
}

