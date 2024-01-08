#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "stock.h"

#include <QList>
#include <QString>
#include <QXmlStreamWriter>

class FileWriter {
public:
  FileWriter(QString fName);
  void write(QList<Stock *> stockList);

private:
  QXmlStreamWriter XMLwriter;
  QString fileName;
};

#endif // FILEWRITER_H
