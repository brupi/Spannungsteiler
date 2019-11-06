#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QValidator>
#include <QDoubleValidator>
#include <QMessageBox>
#include <QLineEdit>
#include "voltagedivider.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDoubleValidator *eingabe = new QDoubleValidator(0.0,1000.0,2);
    ui->Quellspannung->setValidator(eingabe);
    ui->Spannung_2->setValidator(eingabe);
    QPixmap pic(":/resources/image/spannungsteiler.png");
    ui->label->setPixmap(pic);
    VoltageDivider *v = new VoltageDivider();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Quellspannung_editingFinished()
{
    QString XMAX = ui->Quellspannung->text();
    double voltage_1=XMAX.toDouble();
    v->setU1(voltage_1);
}

void MainWindow::on_Spannung_2_editingFinished()
{

}
