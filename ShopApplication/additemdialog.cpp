
#include "additemdialog.h"

#include <QLabel>

AddItemDialog::AddItemDialog(QWidget *parent)
    : QDialog(parent)
{

    QGridLayout *layout = new QGridLayout();
    QPushButton *addButton = new QPushButton("Add item");
    nameEdit = new QLineEdit();
    tComboBox = new QComboBox();
    layout->addWidget(new QLabel("Complete the required data"), 0, 0);
    layout->addWidget(new QLabel("Item type"), 1, 0);
    layout->addWidget(tComboBox, 1, 1);
    layout->addWidget(new QLabel("Name of item:"), 2, 0);
    layout->addWidget(nameEdit, 2, 1);
    layout->addWidget(addButton, 4, 1);
    //comboBox items
    tComboBox->addItem("Book");
    tComboBox->addItem("Magazine");

    setWindowTitle("Adding Items to Shop");

    setLayout(layout);
    //to create item
    connect(addButton, &QPushButton::clicked, this, &AddItemDialog::createItem);
}

Item *AddItemDialog::getItem()
{
    return item;
}

void AddItemDialog::createItem()
{
    item = new Item(nameEdit->text(), tComboBox->currentText());

    close();
}

