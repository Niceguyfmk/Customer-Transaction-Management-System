
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QList>
#include <QString>
#include "transaction.h"

class Customer
{
public:
    Customer(QString n);

    QString getName() const;

    void addTransaction(Transaction *t);

    QList<Transaction*> getTransactions() const;

private:
    QString name;

    QList<Transaction*> transactions;
};

#endif // CUSTOMER_H
