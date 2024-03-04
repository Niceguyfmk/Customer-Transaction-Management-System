
#ifndef XMLWRITER_H
#define XMLWRITER_H

#include<QDomDocument>
#include <QString>
#include "customerlist.h"

class XmlWriter
{
public:
    XmlWriter();

    static QString writeXml(CustomerList list);

};

#endif // XMLWRITER_H
