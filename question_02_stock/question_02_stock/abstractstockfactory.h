#ifndef ABSTRACTSTOCKFACTORY_H
#define ABSTRACTSTOCKFACTORY_H

#include "stock.h"

class AbstractStockFactory {
public:
  AbstractStockFactory();
  virtual ~AbstractStockFactory();
  virtual Stock *createStock(QString type, QString i, int q, QString extra);
};

#endif // ABSTRACTSTOCKFACTORY_H
