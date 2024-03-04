#ifndef ADDCUSTOMERDIALOG_H
#define ADDCUSTOMERDIALOG_H
#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "customer.h"

class AddCustomerDialog : public QDialog
{
public:
    explicit AddCustomerDialog(QWidget *parent = nullptr);
    Customer *getName();
public slots:
    void createCustomer();
private:
    QLineEdit *nameEdit2;
    Customer *customer;
};


#endif // ADDCUSTOMERDIALOG_H
