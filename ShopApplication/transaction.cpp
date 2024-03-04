
#include "transaction.h"

Transaction::Transaction(QDateTime dt, QList<Item *> i)
    : dateTime(dt), items(i)
{

}

void Transaction::append(Item *i)
{
    items.append(i);
}

QDateTime Transaction::getDateTime() const
{
    return dateTime;
}

QList<Item *> Transaction::getItems() const
{
    return items;
}

