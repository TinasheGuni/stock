#include "confectionery.h"

Confectionery::Confectionery() : Stock("unknown", 0), weight(0) {}

Confectionery::Confectionery(QString i, int q, int w)
    : Stock(i, q), weight(w) {}

int Confectionery::getWeight() const { return weight; }

void Confectionery::setWeight(int newWeight) { weight = newWeight; }

QString Confectionery::toString() const {
  return "Confectionery: " + item + ", Quantity: " + QString::number(quantity) +
         ", Weight: " + QString::number(weight);
}
