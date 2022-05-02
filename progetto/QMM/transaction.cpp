#include "transaction.h"

const std::string &Transaction::getName() const { return name; }

void Transaction::setName(const std::string &newName) { name = newName; }

double Transaction::getValue() const { return value; }

void Transaction::setValue(double newValue) { value = newValue; }

Category Transaction::getCategory() const { return category; }

void Transaction::setCategory(Category newCategory) { category = newCategory; }

const QDate &Transaction::getDate() const { return date; }

void Transaction::setDate(const QDate &newDate) { date = newDate; }

bool Transaction::getType() const { return type; }

void Transaction::setType(bool newType) { type = newType; }

const std::string &Transaction::getShort_desc() const { return short_desc; }

void Transaction::setShort_desc(const std::string &newShort_desc) { short_desc = newShort_desc; }

Transaction::Transaction(std::string n, double v, QDate d,  Category cat, bool t, std::string sd)
    :  name(n), value(v), category(cat), date(d), type(t), short_desc(sd) {}

