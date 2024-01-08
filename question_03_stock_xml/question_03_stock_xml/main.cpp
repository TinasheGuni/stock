#include "stockwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  StockWindow window;
  window.show();

  return a.exec();
}
