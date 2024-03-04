
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "customerlist.h"
#include "itemlistbackup.h"
#include <QTreeView>
#include <QTableView>
#include "treemodel.h"
#include <QMainWindow>
#include <QStandardItemModel>
#include <QString>
#include <QThread>
#include "udpsender.h"

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addCustomer();
    void addItem();
    void addTransaction();
    void backup();
    void restore();
    void sendXml();

private:
    TreeModel* model;
    QTreeView *view;
    CustomerList list;
    ItemListBackup itemListBackup;
    UDPSender sender;
    QThread thread;
};

#endif // MAINWINDOW_H
