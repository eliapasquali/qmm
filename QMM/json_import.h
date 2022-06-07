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

    /**
     * @brief filePicker Sceglie il file da importare
     * @return path del file
     */
    static QString filePicker();

    /**
     * @brief getJSONObject Costruisce l'oggetto JSON dal file importato
     * @return puntatore all'oggetto JSON
     */
    static QJsonObject* getJSONObject();

    /**
     * @brief getTransactionList Estrae la lista delle transazioni dall'oggetto JSON
     * @param jObject Oggetto contenente le informazioni del JSON
     * @return std::vector delle transazioni
     */
    static std::vector<Transaction> getTransactionList(QJsonObject* jObject);
};

#endif // JSON_IMPORT_H
