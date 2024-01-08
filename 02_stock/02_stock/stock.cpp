#include "stock.h"

Stock::Stock() : item(""), quantity(0) {}

Stock::Stock(const QString &item, int quantity)
    : item(item), quantity(quantity) {}

QString Stock::getItem() const { return item; }

void Stock::setItem(const QString &newItem) { item = newItem; }

int Stock::getQuantity() const { return quantity; }

void Stock::setQuantity(int newQuantity) { quantity = newQuantity; }
