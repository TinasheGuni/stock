#ifndef STOCK_H
#define STOCK_H

#include <QObject>
#include <QString>

class Stock : public QObject {
  Q_OBJECT
public:
  Stock();
  virtual ~Stock();
  Stock(QString i, int q);

  QString getItem() const;
  int getQuantity() const;

  void setItem(QString i);
  void setQuantity(int q);

  virtual QString toString() const = 0;

protected:
  QString item;
  int quantity;
};

#endif // STOCK_H
