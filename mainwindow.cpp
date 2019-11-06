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
    QPixmap pic("D:/Schule/PMSwEng/910-Projekt/Spannungsteiler/git/250px-einfacher-unbelasteter-spannungsteiler-svg_45030.png");
    ui->label->setPixmap(pic);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Quellspannung_editingFinished()
{
    QMessageBox::information(this, tr("GEIL"), tr("ES GAHT"));
}

void MainWindow::on_Spannung_2_editingFinished()
{

}
