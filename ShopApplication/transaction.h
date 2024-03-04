
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QList>
#include <QDateTime>
#include "item.h"

class Transaction
{
public:
    Transaction(QDateTime dt, QList<Item*> i);

    void append(Item* i);

    QDateTime getDateTime() const;

    QList<Item*> getItems() const;

private:
    QList<Item*> items;
    QDateTime dateTime;
};

#endif // TRANSACTION_H
