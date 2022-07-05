#include "transaction.h"

const QString &Transaction::getName() const { return name; }

void Transaction::setName(const QString &newName) { name = newName; }

double Transaction::getValue() const {
    auto sign_value = (type) ? -value : value;
    return sign_value;
}

void Transaction::setValue(const double newValue) {
    type = (value<0) ? true : false;
    value = newValue;
}

Category Transaction::getCategory() const { return category; }

void Transaction::setCategory(Category newCategory) { category = newCategory; }

const QDate &Transaction::getDate() const { return date; }

void Transaction::setDate(const QDate &newDate) { date = newDate; }

bool Transaction::isOutcome() const { return type; }

void Transaction::setOutcome(bool newType) { type = newType; }

const QString &Transaction::getShortDesc() const { return short_desc; }

void Transaction::setShort_desc(const QString &newShort_desc) { short_desc = newShort_desc; }



Transaction::Transaction(const QString& n, const double v, const QDate& d, const Category cat, const bool t, const QString& sd)
    :  name(n), value(v), category(cat), date(d), type(t), short_desc(sd) {}
