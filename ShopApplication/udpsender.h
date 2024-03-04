
#ifndef UDPSENDER_H
#define UDPSENDER_H

#include <QObject>
#include <QUdpSocket>
#include "xmlwriter.h"

class CustomerList;

class UDPSender : public QObject
{
    Q_OBJECT

public:
    UDPSender();

public slots:
    void sendMessage(CustomerList list);

signals:
    void finished();
};

#endif // UDPSENDER_H
