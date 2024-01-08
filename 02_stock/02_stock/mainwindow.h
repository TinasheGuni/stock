#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>
#include <QPlainTextEdit>

class StockList;

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  void addStock();
  void addStockData(QStringList);
  void listConfectionery();
  void listReadingMaterial();

private:
  QAction *stockAddAction;
  QAction *listConfectioneryAction;
  QAction *listReadingMaterialAction;
  QPlainTextEdit *displayfield;

  StockList *stockList;

  void setupGui();
  void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
