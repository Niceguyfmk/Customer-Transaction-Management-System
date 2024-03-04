
#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>

#include "treeitem.h"

#include "customerlist.h"

class CustomerList;

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit TreeModel(const CustomerList list, QObject *parent = nullptr);

    void setUpModel(CustomerList list, TreeItem *root);

    ~TreeModel();

    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

private:
    TreeItem *rootItem;
};

#endif // TREEMODEL_H
