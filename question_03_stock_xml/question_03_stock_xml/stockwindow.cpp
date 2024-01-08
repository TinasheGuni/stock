#include "stockwindow.h"
#include "QStringList"
#include "filewriter.h"
#include "stockfactory.h"
#include "stocklist.h"

#include <QtWidgets>

StockWindow::StockWindow(QWidget *parent)
    : QMainWindow(parent), txtEdit(new QTextEdit),
      actAdd(new QAction("Add Stock item")),
      actList(new QAction("Show items in Stock")),
      actWrite(new QAction("Write to XML")), dialog(new QDialog(this)),
      btnProcess(new QPushButton("Process")), edtFrequency(new QLineEdit),
      edtItemName(new QLineEdit), edtItemNo(new QSpinBox),
      edtItemWeight(new QSpinBox),
      btnConfectionery(new QRadioButton("Confectionery")),
      btnReading(new QRadioButton("Reading")) {

  //    setup Menus
  setupMenus();

  // Initialize window
  setCentralWidget(txtEdit);
  setWindowTitle("Stock");
  //  setWindowState(Qt::WindowMaximized);

  //  Connecting Signals and Slots
  connect(actAdd, &QAction::triggered, this, &StockWindow::addStockItem);
  connect(actList, &QAction::triggered, this, &StockWindow::showStock);
  connect(actWrite, &QAction::triggered, this, &StockWindow::writeXML);
}

StockWindow::~StockWindow() {}

void StockWindow::addStockItem() {
  setupPopupDialog();

  //  Connecting Signals and slots
  connect(btnProcess, &QPushButton::clicked, this, &StockWindow::processData);
}

void StockWindow::processData() {
  StockFactory sf;
  if (btnConfectionery->isChecked()) {
    Stock *c = sf.createStock("Confectionery", edtItemName->text(),
                              edtItemNo->value(), edtItemWeight->cleanText());
    txtEdit->append(c->toString());

    //    Save to a Confectionery list
    StockList *listConfectionery = StockList::getInstance();
    listConfectionery->addStock(c);
    //    listConfectionery->deleteInstance();
  }
  if (btnReading->isChecked()) {
    Stock *rm = sf.createStock("ReadingMaterial", edtItemName->text(),
                               edtItemNo->value(), edtFrequency->text());
    txtEdit->append(rm->toString());

    //    Save to a ReadingMaterial list
    StockList *listRM = StockList::getInstance();
    listRM->addStock(rm);
  }
}

void StockWindow::writeXML() {
  //  geting an instance of StockList
  StockList *stockList = StockList::getInstance();

  QList<Stock *> listC = stockList->returnList("Confectionery");
  QList<Stock *> listRM = stockList->returnList("ReadingMaterial");

  QString fileName =
      QFileDialog::getSaveFileName(this, "Open", ".", "xml(*.xml)");
  FileWriter fr(fileName);

  fr.write(listC);
  QMessageBox msg;
  msg.setText("Confectionery List written to XML file");
  msg.exec();

  fr.write(listRM);
  QMessageBox msg2;
  msg2.setText("ReadingMaterial List written to XML file");
  msg2.exec();
}

void StockWindow::showStock() {
  //  Displaying Confectionery List
  StockList *stockList = StockList::getInstance();

  qDebug() << "\n***List of Confectioneries***";
  QList<Stock *> listC = stockList->returnList("Confectionery");
  for (int i = 0; i < listC.size(); i++) {
    qDebug() << i << ":" << listC.at(i)->toString();
  }

  //  Displaying Reading Material List
  qDebug() << "\n***List Of Reading Materials***";
  QList<Stock *> listRM = stockList->returnList("ReadingMaterial");
  for (int i = 0; i < listRM.size(); i++) {
    qDebug() << i << ":" << listRM.at(i)->toString();
  }
}

void StockWindow::setupMenus() {
  //  Stock Menu
  menuStock = menuBar()->addMenu("Stock");
  menuStock->addAction(actAdd);

  //  List Menu
  menuList = menuBar()->addMenu("List");
  menuList->addAction(actList);

  //  WriteXML
  menuXML = menuBar()->addMenu("XML");
  menuXML->addAction(actWrite);
}

void StockWindow::setupPopupDialog() {
  dialog->show();
  dialog->setWindowTitle("Complete the Required data");

  QFormLayout *formLayout(new QFormLayout(dialog));

  //  Form title
  QLabel *lblTitle(new QLabel("<b>Complete the required data</b>"));
  formLayout->addRow(lblTitle);

  // Radio Buttons
  QVBoxLayout *layoutRadioBtn(new QVBoxLayout);
  layoutRadioBtn->addWidget(btnConfectionery);
  layoutRadioBtn->addWidget(btnReading);

  // Stock type
  formLayout->addRow(tr("Stock Type"), layoutRadioBtn);

  QHBoxLayout *layoutStockType(new QHBoxLayout);
  QLabel *lblStock(new QLabel("Stock type"));
  layoutStockType->addWidget(lblStock);

  //  Name of Item
  edtItemName->setPlaceholderText("Enter the Name of the Item");
  formLayout->addRow(tr("Name of item: "), edtItemName);

  //  Number of Items
  formLayout->addRow(tr("Number of items:"), edtItemNo);

  //  Reading Material
  QLabel *lblReadingMaterial(new QLabel("Reading Material"));
  formLayout->addRow(tr("Confectionery"), lblReadingMaterial);

  //  Weight and Frequency
  QLabel *lblFrequency(new QLabel("Frequency:"));
  formLayout->addRow(tr("Item weight:"), lblFrequency);

  //  Confectionery item weight and
  //  Reading box item frequency
  formLayout->addRow(edtItemWeight, edtFrequency);

  //  Process and Clear
  formLayout->addRow(btnProcess);
  btnProcess->setDefault(true);
}
