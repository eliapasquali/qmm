#include "json_import.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

QJsonObject* JSONImport::getJSONObject(){

    QString val;
    QString path ="/Volumes/GoogleDrive/My Drive/UNIPD/C++/Progetto/qmm/progetto/qmm/transactions.json";     // vedere come fare in modo che sia dinamico e non fisso, tra l'altro non so perchè ma mi va solo se metto il percorso globale
    QFile fileRead(path);

    fileRead.open(QIODevice::ReadOnly | QIODevice::Text);
    val = fileRead.readAll(); // legge il file e lo inserisce dentro la QString "val"
    fileRead.close();   // chiude il file (importante)

    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());

    QJsonObject* jObject = new QJsonObject(doc.object()); // comando che ottiene l'oggetto JSON

    return jObject;
}

// metodo che prende l'oggetto JSON e costruisce un vettore di transactions da utilizzare poi nel modello
std::vector<Transaction> JSONImport::getTransactionList(QJsonObject* jObject){

    QJsonValue value = jObject->value("transactionList");
    QJsonArray JSONarray = value.toArray();

    std::vector<Transaction> tmp_transaction_vector;    // array delle transizioni da ritornare

    //itero array JSON
    for(int i = 0; i < JSONarray.size(); i++){
        QJsonObject arrayObject = JSONarray[i].toObject();  //ottengo il singolo elemento dell'array JSON da cui estrarre le informazioni

        QDate date(arrayObject["year"].toInt(),arrayObject["month"].toString().toInt(),arrayObject["name"].toString().toInt());
        Category tmp_category = (Category)arrayObject["category"].toInt();

        //costtruisco la transaction usando le informazioni dell'oggetto JSON
        Transaction tmp_transaction(
            arrayObject["name"].toString().toStdString(),
            arrayObject["value"].toDouble(),
            date,
            tmp_category,
            arrayObject["type"].toBool(),
            arrayObject["short_desc"].toString().toStdString()
        );

        tmp_transaction_vector.push_back(tmp_transaction);

    }
    return tmp_transaction_vector;
}



