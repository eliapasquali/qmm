#include "json_export.h"

#include <qfiledialog.h>

void json_export::exportTransaction(std::vector<Transaction> toBeExported)
{
    if(!toBeExported.empty()){

        QString exportedPath = QFileDialog::getSaveFileName(nullptr, "Save File","untitled.json",".json");
        QFile exportFile(exportedPath);
        exportFile.open(QIODevice::WriteOnly | QIODevice::Text);

        QTextStream out(&exportFile);   // serve a gestire i flussi di testo siccome il metodo file.write non accetta le stringhe (out << String --> scrive sul file)

        //riempimento del file da esportare
        out <<  "{\n \"transactionList\": [\n";


        auto fine = toBeExported.end();
        fine--;

        // qui ci vanno un po di escape per le virgolette
        for(auto t = toBeExported.begin(); t != toBeExported.end(); t++){
            out << "{\n"
            << "\"name\": " << "\"" << t->getName() << " \" , \n"
            << "\"value\": " << abs(t->getValue()) << ", \n"
            << "\"category\": " << t->getCategory() << ", \n"
            << "\"day\": " << t->getDate().day() << ", \n"
            << "\"month\": " << t->getDate().month() << ", \n"
            << "\"year\": " << t->getDate().year() << ", \n"
            << "\"type\": " << t->isOutcome() << ", \n"
            << "\"short_desc\": " << "\"" << t->getShort_desc() << " \" \n";

            // vedere se c'è metodo migliore

            if(t == fine)
                out << "}\n";
            else
                out << "},\n";

        }

        out << "]\n" << "}";

        exportFile.close();
    }

}
