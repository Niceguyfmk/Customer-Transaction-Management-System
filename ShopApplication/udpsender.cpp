
#include "udpsender.h"

UDPSender::UDPSender()
{

}

void UDPSender::sendMessage(CustomerList list)
{
    QUdpSocket socket(this);

    socket.bind(8888);

    QByteArray data;

    data.append(XmlWriter::writeXml(list).toUtf8());

    socket.writeDatagram(data,QHostAddress::LocalHost, 8888);

    emit finished();
}

