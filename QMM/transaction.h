#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDate>
#include <map>

enum Category {
    Lavoro,
    Casa,
    Intrattenimento,
    Salute,
    Risparmi,
    Tasse
};

const std::map<Category, std::string> enumToString {
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
    std::string name;
    double value;
    Category category;
    QDate date;
    bool type; // 0 income, 1 outcome
    std::string short_desc;

public:
    Transaction(std::string n, double v, QDate d, Category cat, bool t =1, std::string sd = "");

    ~Transaction() = default;

    const std::string &getName() const;
    void setName(const std::string &newName);

    double getValue() const;
    void setValue(double newValue);

    Category getCategory() const;
    void setCategory(Category newCategory);


    const QDate &getDate() const;
    void setDate(const QDate &newDate);

    bool getType() const;
    void setType(bool newType);

    const std::string &getShort_desc() const;
    void setShort_desc(const std::string &newShort_desc);

};

#endif // TRANSACTION_H
