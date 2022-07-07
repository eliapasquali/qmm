#ifndef JSON_IMPORT_H
#define JSON_IMPORT_H

#include <QJsonArray>
#include <iostream>
#include <vector>
#include <QJsonDocument>
#include "transaction.h"

class JSONImport
{
public:
    JSONImport();

    /**
     * @brief filePicker Sceglie il file da importare
     * @return path del file
     */
    static QString filePicker();

    /**
     * @brief getJSONObject Restituisce un oggetto di tipo JSONDocument
     * @return puntatore all'oggetto JSONDocument
     */
    static QJsonDocument* getJSONDocument(QString path);

    /**
     * @brief getTransactionList Estrae la lista delle transazioni dall'oggetto JSON
     * @param jObject Oggetto contenente le informazioni del JSON
     * @return std::vector delle transazioni
     */
    static std::vector<Transaction> getTransactionList(QJsonObject* jObject);
};

#endif // JSON_IMPORT_H
