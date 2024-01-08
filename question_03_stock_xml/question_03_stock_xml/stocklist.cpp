#include "stocklist.h"

StockList *StockList::getInstance() {
  if (onlyInstance == NULL) {
    onlyInstance = new StockList();
  }

  return onlyInstance;
}

void StockList::deleteInstance() { delete onlyInstance; }

void StockList::addStock(Stock *s) {
  const QMetaObject *meta = s->metaObject();
  if (QString(meta->className()) == "Confectionery")
    listC.append(s);
  else if (QString(meta->className()) == "ReadingMaterial")
    listRM.append(s);
}

QList<Stock *> StockList::returnList(QString type) const {
  if (type == "Confectionery") {
    return listC;
  }
  if (type == "ReadingMaterial") {
    return listRM;
  }
  return QList<Stock *>();
}

StockList::StockList() {}

StockList::~StockList() {
  qDeleteAll(listC.begin(), listC.end());
  listC.clear();
  qDeleteAll(listRM.begin(), listRM.end());
  listRM.clear();
}

StockList *StockList::onlyInstance = NULL;
