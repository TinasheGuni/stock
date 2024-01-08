#ifndef STOCKFACTORY_H
#define STOCKFACTORY_H

#include "stock.h"

class StockFactory {
public:
  StockFactory();
  Stock *createStock(QString stockType, QString i, int q, QString other);
};

#endif // STOCKFACTORY_H
