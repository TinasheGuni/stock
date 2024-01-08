#include "stockfactory.h"
#include "stocklist.h"
#include "stockwindow.h"

#include <QApplication>
#include <QStringList>
#include <QTextStream>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  StockWindow window;
  window.show();

  return a.exec();
}
