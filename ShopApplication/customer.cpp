
#include "customer.h"

Customer::Customer(QString n) : name(n)
{

}

QString Customer::getName() const
{
    return name;
}

void Customer::addTransaction(Transaction *t)
{
    transactions.append(t);
}

QList<Transaction *> Customer::getTransactions() const
{
    return transactions;
}
