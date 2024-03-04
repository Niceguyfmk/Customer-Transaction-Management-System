
#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "item.h"
#include <QList>
#include "itemlistbackup.h"

class ItemList
{
public:
    static ItemList* getInstance();
    void addItem(Item* i);
    Item* findItem(QString name);
    QList<Item*> getItems() const;
    ItemListBackup createBackup();
    void restore(ItemListBackup backup);

private:
    ItemList();
    QList<Item*> items;
    static ItemList *instance;
};

#endif // ITEMLIST_H
