#include "stockfactory.h"

StockFactory::StockFactory() {}

StockFactory::~StockFactory() {}

Stock *StockFactory::createStock(QString type, QString i, int q,
                                 QString extra) {
  if (type == "Confectionery")
    return new Confectionery(i, q, extra.toInt());
  else if (type == "ReadingMaterial")
    return new ReadingMaterial(i, q, extra);
  return NULL;
}
