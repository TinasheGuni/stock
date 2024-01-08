#include "filewriter.h"
#include "confectionery.h"
#include "readingmaterial.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QXmlStreamWriter>

FileWriter::FileWriter(QString fName) : fileName(fName) {}

void FileWriter::write(QList<Stock *> stockList) {
  QFile outFile(fileName);

  if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
    qCritical() << outFile.errorString();
  }

  if (!outFile.exists()) {
    qCritical() << outFile.errorString();
  }

  XMLwriter.setDevice(&outFile);
  XMLwriter.setAutoFormatting(true);
  XMLwriter.writeStartDocument();
  XMLwriter.writeStartElement("StockList");

  for (int i = 0; i < stockList.size(); i++) {
    //    Using the meta object system to get the string representation of the
    //    class name that is to be written to an xml file
    Stock *item = stockList.at(i);
    const QMetaObject *meta = item->metaObject();
    QString nameOfClass = QString(meta->className());

    //    stockItem opening tag
    XMLwriter.writeStartElement("stockItem");
    QXmlStreamAttribute attribute("type", nameOfClass);
    XMLwriter.writeAttribute(attribute);

    //    item and quantity tags for both class
    XMLwriter.writeTextElement("item", item->getItem());
    XMLwriter.writeTextElement("quantity",
                               QString::number(item->getQuantity()));

    //    weight tag for the Confectionery class
    if (nameOfClass == "Confectionery") {
      Confectionery *c = qobject_cast<Confectionery *>(item);
      XMLwriter.writeTextElement("weight", QString::number(c->getWeight()));
    }

    //    frequency tag for the ReadingMaterial class
    if (nameOfClass == "ReadingMaterial") {
      ReadingMaterial *rm = qobject_cast<ReadingMaterial *>(item);
      XMLwriter.writeTextElement("frequency", rm->getFrequency());
    }
    //   tockItem closing tag
    XMLwriter.writeEndElement();
  }
  XMLwriter.writeEndElement();
  XMLwriter.writeEndDocument();

  outFile.close();
}
