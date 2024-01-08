#ifndef STOCKFACTORY_H
#define STOCKFACTORY_H

#include "abstractstockfactory.h"
#include "confectionery.h"
#include "readingmaterial.h"

class StockFactory : public AbstractStockFactory {
public:
  StockFactory();
  ~StockFactory();
  Stock *createStock(QString type, QString i, int q, QString extra);
};

#endif // STOCKFACTORY_H
