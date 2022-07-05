#include "json_export.h"

void json_export::exportTransaction(const std::vector<Transaction> toBeExported)
{
    if(!toBeExported.empty()){

        QString exportedPath = QFileDialog::getSaveFileName(nullptr, "Save File","untitled.json",".json");
        QFile exportFile(exportedPath);
        exportFile.open(QIODevice::WriteOnly | QIODevice::Text);

        QJsonArray json_list;

        for(auto t : toBeExported) {
            QJsonObject json_transaction;
            json_transaction.insert("name", t.getName());
            json_transaction.insert("value", abs(t.getValue()));
            json_transaction.insert("category", t.getCategory());
            json_transaction.insert("day", t.getDate().day());
            json_transaction.insert("month", t.getDate().month());
            json_transaction.insert("year", t.getDate().year());
            json_transaction.insert("type", t.isOutcome());
            json_transaction.insert("short_desc", t.getShortDesc());
            json_list.append(json_transaction);
        }

        QJsonObject transaction_list;
        transaction_list["transactionList"] = json_list;

        QJsonDocument jsonDoc(transaction_list);
        exportFile.write(jsonDoc.toJson());
        exportFile.close();
    }

}
