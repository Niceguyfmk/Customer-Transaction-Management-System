
#include "itemlistbackup.h"

ItemListBackup::ItemListBackup()
{

}

ItemListBackup::ItemListBackup(QList<Item *> s)
{
    foreach(Item* i, s){
        state.append(new Item(*i));
    }
}

QList<Item *> ItemListBackup::getState()
{
    return state;
}
