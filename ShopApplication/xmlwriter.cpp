
#include "xmlwriter.h"

XmlWriter::XmlWriter()
{

}

QString XmlWriter::writeXml(CustomerList list)
{
    QDomDocument doc;

    QDomElement root = doc.createElement("ModelData");

    doc.appendChild(root);

    foreach(Customer *c, list.getCustomers()){
        QDomElement cElement = doc.createElement("customer");
        cElement.setAttribute("name", c->getName());
        root.appendChild(cElement);
        foreach(Transaction* t, c->getTransactions()){
            QDomElement tElement = doc.createElement("transaction");
            cElement.appendChild(tElement);
            tElement.setAttribute("date", t->getDateTime().toString());
            foreach(Item *i, t->getItems()){
                QDomElement iElement = doc.createElement("lineitem");
                tElement.appendChild(iElement);
                iElement.setAttribute("name", i->getName());
                iElement.setAttribute("type", i->getType());
                iElement.setAttribute("quantity", i->getQuantity());
            }
        }
    }

    return doc.toString();
}

