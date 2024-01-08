#include "stock.h"

Stock::Stock() {}

Stock::~Stock() {}

Stock::Stock(QString i, int q) : item(i), quantity(q) {}

QString Stock::getItem() const { return item; }

int Stock::getQuantity() const { return quantity; }

void Stock::setItem(QString i) { item = i; }

void Stock::setQuantity(int q) { quantity = q; }
