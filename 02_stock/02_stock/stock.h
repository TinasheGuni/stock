#ifndef STOCK_H
#define STOCK_H

#include <QObject>

class Stock : public QObject {
  Q_OBJECT
public:
  Stock();
  Stock(const QString &item, int quantity);

  QString getItem() const;
  void setItem(const QString &newItem);

  int getQuantity() const;
  void setQuantity(int newQuantity);

  virtual QString toString() const = 0;

protected:
  QString item;
  int quantity;
};

#endif // STOCK_H
