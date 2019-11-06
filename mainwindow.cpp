#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QValidator>
#include <QDoubleValidator>
#include <QTextEdit>
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
    ui->out_r1->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Quellspannung_editingFinished()
{
    QString input_voltage = ui->Quellspannung->text();
    double voltage_1 = input_voltage.toDouble();
    v->setU1(voltage_1);
}

void MainWindow::on_Spannung_2_editingFinished()
{
    QString input_voltage = ui->Quellspannung->text();
    double voltage_2 = input_voltage.toDouble();
    v->setU2(voltage_2);
}
