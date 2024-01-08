#include "confectionery.h"

Confectionery::Confectionery() {}

Confectionery::~Confectionery() {}

Confectionery::Confectionery(QString i, int q, int w)
    : Stock(i, q), weight(w) {}

int Confectionery::getWeight() const { return weight; }

void Confectionery::setWeight(int w) { weight = w; }

QString Confectionery::toString() const {

  //    Returns the string representation of the Confectionary Object
  return "Item: " + item + ", Quantity: " + QString::number(quantity) +
         ", Weight: " + QString::number(weight);
}
