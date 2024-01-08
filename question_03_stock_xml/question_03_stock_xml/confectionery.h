#ifndef CONFECTIONERY_H
#define CONFECTIONERY_H

#include "stock.h"
#include <QString>

class Confectionery : public Stock {
  Q_OBJECT
public:
  Confectionery();
  ~Confectionery();
  Confectionery(QString i, int q, int w);

  int getWeight() const;
  void setWeight(int w);

  QString toString() const override;

private:
  int weight;
};

#endif // CONFECTIONERY_H
