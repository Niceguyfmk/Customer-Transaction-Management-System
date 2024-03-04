
#include "addcustomerdialog.h"

AddCustomerDialog::AddCustomerDialog(QWidget *parent)
    : QDialog(parent)
{

    QGridLayout *layout = new QGridLayout();
    QPushButton *addButton2 = new QPushButton("Add Customer");
    nameEdit2 = new QLineEdit();

    layout->addWidget(new QLabel("Complete the required data"), 0, 0);
    layout->addWidget(new QLabel("Name of Customer"), 1, 0);
    layout->addWidget(nameEdit2, 1, 1);

    layout->addWidget(addButton2, 4, 1);

    setWindowTitle("Add Customer Names");

    setLayout(layout);
    //to create item
    connect(addButton2, &QPushButton::clicked, this, &AddCustomerDialog::createCustomer);
}

Customer *AddCustomerDialog::getName()
{
    return customer;
}

void AddCustomerDialog::createCustomer()
{
    customer = new Customer(nameEdit2->text());

    close();
}

