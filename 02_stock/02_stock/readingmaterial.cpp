#include "readingmaterial.h"

ReadingMaterial::ReadingMaterial()
    : Stock("Unknown", 0), frequency("unknown") {}

ReadingMaterial::ReadingMaterial(QString i, int q, QString &f)
    : Stock(i, q), frequency(i) {}

QString ReadingMaterial::getFrequency() const { return frequency; }

void ReadingMaterial::setFrequency(const QString &newFrequency) {
  frequency = newFrequency;
}

QString ReadingMaterial::toString() const {
  return "Reading material: " + item +
         ", Quantity: " + QString::number(quantity) +
         ", Frequency: " + frequency;
}
