#ifndef STOCKGUI_H
#define STOCKGUI_H

#include <QMainWindow>

class QAction;
class QMenu;
class QMenuBar;
class QTextEdit;
class QToolBar;
class QDialog;
class QPushButton;
class QLineEdit;
class QSpinBox;
class QRadioButton;

class StockWindow : public QMainWindow {
  Q_OBJECT
public:
  explicit StockWindow(QWidget *parent = nullptr);
  ~StockWindow();

private slots:
  void addStockItem();
  void showStock();
  void processData();
  void writeXML();

private:
  void setupMenus();

  // Pop up Dialog
  void setupPopupDialog();

  QTextEdit *txtEdit;

  //  Actions
  QAction *actAdd;
  QAction *actList;
  QAction *actWrite;

  // Menus
  QMenu *menuStock;
  QMenu *menuList;
  QMenu *menuXML;

  //  Pop up dialog
  QDialog *dialog;
  QPushButton *btnProcess;
  QLineEdit *edtFrequency;
  QLineEdit *edtItemName; // Name of Items
  QSpinBox *edtItemNo;    // Number of Items
  QSpinBox *edtItemWeight;

  QRadioButton *btnConfectionery;
  QRadioButton *btnReading;
};

#endif // STOCKGUI_H
