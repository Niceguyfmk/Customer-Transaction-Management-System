
#ifndef ADDTRANSACTIONDIALOG_H
#define ADDTRANSACTIONDIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include "customerlist.h"
#include <QStringList>
#include "transaction.h"

class AddTransactionDialog : public QDialog
{
public:
    explicit AddTransactionDialog(CustomerList cList, QWidget* parent = nullptr);

public slots:
    void updateItemTypeLabel(int index);

    void addItem();

    void createTransaction();

private:
    CustomerList customerList;
    QComboBox *cComboBox;
    QComboBox *itemCombo;
    QLabel *itemTypeLabel;
    QSpinBox* quantity;
    QTextEdit *txtEdit;
    QList<Item*> items;

};

#endif // ADDTRANSACTIONDIALOG_H
