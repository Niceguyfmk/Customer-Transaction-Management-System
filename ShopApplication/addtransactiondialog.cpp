
#include "addtransactiondialog.h"

#include <QGridLayout>
#include "itemlist.h"

AddTransactionDialog::AddTransactionDialog(CustomerList cList, QWidget *parent)
    : QDialog(parent), customerList(cList)
{
    QGridLayout* layout = new QGridLayout();

    cComboBox = new QComboBox();
    itemCombo = new QComboBox();
    itemTypeLabel = new QLabel();
    itemTypeLabel->setEnabled(false);
    quantity = new QSpinBox();
    txtEdit = new QTextEdit();
    QPushButton *addItemBtn = new QPushButton("Add item");
    QPushButton *doneBtn = new QPushButton("Done");

    foreach(Customer *c, cList.getCustomers()){
        cComboBox->addItem(c->getName());
    }

    foreach(Item* i, ItemList::getInstance()->getItems()){
        itemCombo->addItem(i->getName());
    }

    layout->addWidget(new QLabel("Customer"), 0, 0);
    layout->addWidget(cComboBox, 0, 1);
    layout->addWidget(new QLabel("Item"), 1, 0);
    layout->addWidget(itemCombo, 1, 1);
    layout->addWidget(itemTypeLabel, 2, 1);
    layout->addWidget(new QLabel("Item quantity"), 3, 0);
    layout->addWidget(quantity, 3, 1);
    layout->addWidget(addItemBtn, 3, 2);
    layout->addWidget(txtEdit, 4, 0, 1, 3);
    layout->addWidget(doneBtn,5, 1);

    setLayout(layout);

    setWindowTitle("Add transaction");

    connect(itemCombo, &QComboBox::currentIndexChanged, this, &AddTransactionDialog::updateItemTypeLabel);

    connect(addItemBtn, &QPushButton::clicked, this, &AddTransactionDialog::addItem);

    connect(doneBtn, &QPushButton::clicked, this, &AddTransactionDialog::createTransaction);
}

void AddTransactionDialog::updateItemTypeLabel(int index)
{
    itemTypeLabel->setText(ItemList::getInstance()->getItems().at(index)->getType());
}

void AddTransactionDialog::addItem()
{
    Item* i = new Item(*(ItemList::getInstance()->findItem(itemCombo->currentText())));

    items.append(i);

    foreach(Item* i, items){
        txtEdit->setText(txtEdit->toPlainText() + "\n" + i->toString());
    }
}

void AddTransactionDialog::createTransaction()
{
    Customer *customer = NULL;

    foreach(Customer *c, customerList.getCustomers()){
        if(c->getName() == cComboBox->currentText()){
            customer = c;
        }
    }

    if(customer != NULL){
        Transaction *t = new Transaction(QDateTime::currentDateTime(), items);

        customer->addTransaction(t);
    }

    close();
}
