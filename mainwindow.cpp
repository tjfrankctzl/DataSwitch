#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/pic/icon/main.png"));

    ui->lineEdit_enpot->setText("20101");
    ui->lineEdit_depotport->setText("20102");

    QAction *pAction = new QAction(this);
    pAction->setIcon(QIcon(":/pic/icon/en.png"));
    ui->lineEdit_enpot->addAction(pAction, QLineEdit::TrailingPosition);//QLineEdit::TrailingPosition

   pAction = new QAction(this);
   pAction->setIcon(QIcon(":/pic/icon/depot.png"));
   ui->lineEdit_depotport->addAction(pAction, QLineEdit::TrailingPosition);//QLineEdit::TrailingPosition
}

MainWindow::~MainWindow()
{
    delete ui;
}

