
#include "item.h"

Item::Item(QString n, QString y, int q)
    : name(n), type(y), quantity(q)
{

}

QString Item::getType() const
{
    return type;
}

QString Item::getName() const
{
    return name;
}

int Item::getQuantity() const
{
    return quantity;
}

QString Item::toString() const
{
    return QString("Item name: %1, Type: %2, Quantity: %3").arg(name).arg(type).arg(quantity);
}
