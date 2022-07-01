#ifndef JSON_EXPORT_H
#define JSON_EXPORT_H

#include <QJsonArray>
#include <iostream>
#include <vector>
#include <QJsonDocument>
#include "transaction.h"
#include <QIODevice>
#include <qfile.h>
#include <qiodevice.h>
#include <qtextstream.h>

class json_export
{
public:
    
    static void exportTransaction(std::vector<Transaction> toBeExported);


};

#endif // JSON_EXPORT_H
