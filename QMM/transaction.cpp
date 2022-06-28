#include "transaction.h"

const QString &Transaction::getName() const { return name; }

void Transaction::setName(const QString &newName) { name = newName; }

double Transaction::getValue() const { return value; }

void Transaction::setValue(double newValue) { value = newValue; }

Category Transaction::getCategory() const { return category; }

void Transaction::setCategory(Category newCategory) { category = newCategory; }

const QDate &Transaction::getDate() const { return date; }

void Transaction::setDate(const QDate &newDate) { date = newDate; }

bool Transaction::getType() const { return type; }

void Transaction::setType(bool newType) { type = newType; }

const QString &Transaction::getShort_desc() const { return short_desc; }

void Transaction::setShort_desc(const QString &newShort_desc) { short_desc = newShort_desc; }

Transaction::Transaction(QString n, double v, QDate d,  Category cat, bool t, QString sd)
    :  name(n), value(v), category(cat), date(d), type(t), short_desc(sd) {}
