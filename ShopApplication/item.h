
#ifndef ITEM_H
#define ITEM_H

#include <QString>


class Item
{
public:
    Item(QString n, QString y, int q = 0);

    QString getType() const;

    QString getName() const;

    int getQuantity() const;

    QString toString() const;

private:
    QString name, type;
    int quantity;
};

#endif // ITEM_H
