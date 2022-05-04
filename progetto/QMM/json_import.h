#ifndef JSON_IMPORT_H
#define JSON_IMPORT_H

#include "QJsonArray"
#include "transaction.h"
#include "iostream"
#include "vector"

#include <QJsonDocument>

class JSONImport
{
public:
    JSONImport();

    static QJsonObject* getJSONObject();
    static std::vector<Transaction> getTransactionList(QJsonObject* jObject);
};

#endif // JSON_IMPORT_H
