
#include "mainwindow.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include "addcustomerdialog.h"
#include "additemdialog.h"
#include "addtransactiondialog.h"
#include "itemlist.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    model = new TreeModel(list);

    QMenu* addCustomerMenu = menuBar()->addMenu("Add");
    QMenu* restoreMenu = menuBar()->addMenu("Restore");
    QMenu* udpMenu = menuBar()->addMenu("UDP");

    QAction* act = addCustomerMenu->addAction("Add new customer");
    QAction* addItemsAction = addCustomerMenu->addAction("Add new item");
    QAction* addTransactionAction = addCustomerMenu->addAction("Add transaction");
    QAction* backupAction = restoreMenu->addAction("Backup item list");
    QAction* restoreAction = restoreMenu->addAction("Restore item list");
    QAction* udpAction = udpMenu->addAction("Send XML over UDP");

    view = new QTreeView();

    view->setModel(model);

    setCentralWidget(view);

    connect(act, &QAction::triggered, this, &MainWindow::addCustomer);
    connect(addItemsAction, &QAction::triggered, this, &MainWindow::addItem);
    connect(addTransactionAction, &QAction::triggered, this, &MainWindow::addTransaction);
    connect(backupAction, &QAction::triggered, this, &MainWindow::backup);
    connect(restoreAction, &QAction::triggered, this, &MainWindow::restore);
    connect(udpAction, &QAction::triggered, this, &MainWindow::sendXml);

    showMaximized();
}

MainWindow::~MainWindow()
{
}

void MainWindow::addCustomer()
{
    QString name = QInputDialog::getText(0, "Customer name", "Enter customer name");

    Customer* customer = new Customer(name);

    list.append(customer);


    QMessageBox::information(0, "Customer added", QString("%1 added as a new customer").arg(name));

}

void MainWindow::addItem()
{
    AddItemDialog d(this);

    d.exec();

    Item* i = d.getItem();

    ItemList::getInstance()->addItem(i);

    d.close();

    QMessageBox::information(0, "Item added", "Item added");
}

void MainWindow::addTransaction()
{
    AddTransactionDialog d(list, this);

    d.exec();

    delete model;

    model = new TreeModel(list);

    view->setModel(model);
}

void MainWindow::backup()
{
    ItemList* list = ItemList::getInstance();

    itemListBackup = list->createBackup();

    QMessageBox::information(0, "Backup created", "Item list backup crated");
}

void MainWindow::restore()
{
    ItemList* list = ItemList::getInstance();

    list->restore(itemListBackup);

    QMessageBox::information(0, "Restored", "Item list restored.");
}

void MainWindow::sendXml()
{
    sender.moveToThread(&thread);

    connect(&thread, SIGNAL(started()), &sender, SLOT(sendMessage(list)));

    thread.start();

    QMessageBox::information(0, "Message sent", "Message has been send. Please check the clien");
}


