
#ifndef ITEMLISTBACKUP_H
#define ITEMLISTBACKUP_H

#include <QList>
#include "item.h"
class ItemList;

class ItemListBackup
{
public:
    ItemListBackup();

private:
    friend class ItemList;
    ItemListBackup(QList<Item*> s);
    QList<Item*> getState();
    QList<Item*>  state;
};

#endif // ITEMLISTBACKUP_H
