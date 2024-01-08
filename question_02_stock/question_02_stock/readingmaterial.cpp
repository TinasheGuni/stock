#include "readingmaterial.h"

ReadingMaterial::ReadingMaterial() {}

ReadingMaterial::~ReadingMaterial() {}

ReadingMaterial::ReadingMaterial(QString i, int q, QString f)
    : Stock(i, q), frequency(f) {}

QString ReadingMaterial::getFrequency() const { return frequency; }

void ReadingMaterial::setFrequency(QString f) { frequency = f; }

QString ReadingMaterial::toString() const {

  //         QString::number(Stock::quantity) + "Frequency: " + frequency;
  return "Item: " + item + ", Quantity: " + QString::number(quantity) +
         ", Frequency: " + frequency;
}
