#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QValidator>
#include <QDoubleValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDoubleValidator *eingabe = new QDoubleValidator(0.0,1000.0,2);
    ui->Quellspannung->setValidator(eingabe);
    ui->Spannung_2->setValidator(eingabe);
   // int integer_value = ui->Quellspannung->text().toInt();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Quellspannung_editingFinished()
{
    //QString nennspanung = text();
    //int nennspannung = QLineEdit::Quellsapnnung();
    QMessageBox::information(this, tr("GEIL"), tr("ES GAHT"));
}

void MainWindow::on_Spannung_2_editingFinished()
{

}
