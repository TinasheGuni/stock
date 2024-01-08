#ifndef STOCKLIST_H
#define STOCKLIST_H

#include <QList>

#include "confectionery.h"
#include "readingmaterial.h"

class StockList {
public:
  static StockList *getInstance();
  static void deleteInstance();

  void addStock(Stock *s);

  QList<Stock *> returnList(QString type) const;

private:
  StockList();
  ~StockList();

  static StockList *onlyInstance;

  QList<Stock *> listC;
  QList<Stock *> listRM;
};

#endif // STOCKLIST_H
