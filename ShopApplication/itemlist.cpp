
#include "itemlist.h"

ItemList* ItemList::instance = NULL;

ItemList::ItemList()
{

}

ItemList *ItemList::getInstance()
{
    if(instance == NULL)
        instance = new ItemList();

    return instance;
}

void ItemList::addItem(Item *i)
{
    items.append(i);
}

Item *ItemList::findItem(QString name)
{
    foreach(Item* i, items){
        if(name== i->getName())
            return i;
    }

    return NULL;
}

QList<Item *> ItemList::getItems() const
{
    return items;
}

ItemListBackup ItemList::createBackup()
{
    ItemListBackup backup(items);

    return backup;
}

void ItemList::restore(ItemListBackup backup)
{
    qDeleteAll(items);

    items.clear();

    foreach(Item* i,backup.getState()){
        items.append(i);
    }
}

