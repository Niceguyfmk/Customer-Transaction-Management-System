
#ifndef ADDITEMDIALOG_H
#define ADDITEMDIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include "item.h"


class AddItemDialog : public QDialog
{
public:
    explicit AddItemDialog(QWidget *parent = nullptr);

    Item* getItem();

public slots:
    void createItem();

private:
    QLineEdit *nameEdit;
    QComboBox* tComboBox;
    Item *item;
};

#endif // ADDITEMDIALOG_H
