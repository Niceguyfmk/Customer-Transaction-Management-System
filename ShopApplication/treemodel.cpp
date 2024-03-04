
#include "treemodel.h"

#include <QDebug>

TreeModel::TreeModel(const CustomerList list, QObject *parent)
    : QAbstractItemModel(parent)
{
    rootItem = new TreeItem({tr("Transaction"), tr("Type"), tr("Quantity")});

    setUpModel(list, rootItem);
}

void TreeModel::setUpModel(CustomerList list, TreeItem *root)
{
    foreach(Customer *c, list.getCustomers()){

        TreeItem *customerTreeItem = new TreeItem({c->getName()}, root);

        root->appendChild(customerTreeItem);

        foreach(Transaction *t, c->getTransactions()){
            TreeItem* tr = new TreeItem({t->getDateTime()} , customerTreeItem);
            customerTreeItem->appendChild(tr);

            foreach(Item *i, t->getItems()){
                TreeItem* iti = new TreeItem({
                                                 i->getName(),
                                                 i->getType(),
                                                 i->getQuantity()
                                             }, tr);
                tr->appendChild(iti);
            }
        }
    }
}

TreeModel::~TreeModel()
{
    delete rootItem;
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->parentItem();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    return rootItem->columnCount();
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());

    return item->data(index.column());
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index);
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}
