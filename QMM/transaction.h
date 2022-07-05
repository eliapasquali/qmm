#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDate>
#include <QString>
#include <map>

enum Category {
    Lavoro,
    Casa,
    Intrattenimento,
    Salute,
    Risparmi,
    Tasse
};

const std::map<Category, QString> enumToString {
    {Lavoro, "Lavoro"},
    {Casa, "Casa"},
    {Intrattenimento, "Intrattenimento"},
    {Salute, "Salute"},
    {Risparmi, "Risparmi"},
    {Tasse, "Tasse"}
};

class Transaction
{

private:
    QString name;
    double value;
    Category category;
    QDate date;
    bool type; // 0 income, 1 outcome
    QString short_desc;

public:
    Transaction(const QString &n, const double v, const QDate &d, const Category cat, const bool t=1, const QString &sd = QString());
    ~Transaction() = default;

    const QString& getName() const;
    void setName(const QString& newName);

    double getValue() const;
    void setValue(const double newValue);

    Category getCategory() const;
    void setCategory(Category newCategory);


    const QDate &getDate() const;
    void setDate(const QDate &newDate);

    bool isOutcome() const;
    void setOutcome(bool newType);

    const QString& getShortDesc() const;
    void setShort_desc(const QString& newShort_desc);

};

#endif // TRANSACTION_H
