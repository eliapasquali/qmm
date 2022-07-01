#include "json_export.h"

void json_export::exportTransaction(std::vector<Transaction> toBeExported)
{
    QString val;
    QString path ="ExportedTransaction.json"; //Risolto così
    QFile exportFile(path);

    exportFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&exportFile);   // serve a gestire i flussi di testo siccome il metodo file.write non accetta le stringhe (out << String --> scrive sul file)

    out <<  "{\n \"transactionList\": [\n";

    // qui ci vanno un po di escape per le virgolette
    for(auto t : toBeExported){
        out << "{\n"
        << "\"name\": " << "\"" << t.getName() << " \" , \n"
        << "\"value\": " << t.getValue() << ", \n"
        << "\"category\": " << t.getCategory() << ", \n"
        << "\"day\": " << t.getDate().day() << ", \n"
        << "\"month\": " << t.getDate().month() << ", \n"
        << "\"year\": " << t.getDate().year() << ", \n"
        << "\"type\": " << t.isOutcome() << ", \n"
        << "\"short_desc\": " << "\"" << t.getShort_desc() << " \" \n"
        << "},\n";
    }

    out << "]\n" << "}";

    exportFile.close();
}
