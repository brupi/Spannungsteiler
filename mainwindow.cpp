#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QValidator>
#include <QDoubleValidator>
#include <QTextEdit>
#include <QLineEdit>
#include <QString>
#include "voltagedivider.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , VD(new VoltageDivider())
{
    ui->setupUi(this);
    QDoubleValidator *input_validator = new QDoubleValidator(0.0,1000.0,2);
    ui->Quellspannung->setValidator(input_validator);
    ui->Spannung_2->setValidator(input_validator);
    QPixmap pic(":/resources/image/spannungsteiler.png");
    ui->label->setPixmap(pic);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Quellspannung_editingFinished()
{
    double value = ui->Quellspannung->text().toDouble();
    // u1 must be higher or the same as u2
    if(value >= VD->getU2())
    {
        VD->setU1(value);
        ui->out_r1->setText(QString::number(VD->getR1()));
        ui->out_r2->setText(QString::number(VD->getR2()));
    }else{
        ui->Quellspannung->setText(QString::number(VD->getU1()));
    }
}

void MainWindow::on_Spannung_2_editingFinished()
{
    double value = ui->Spannung_2->text().toDouble();
    // u1 must be higher or the same as u2
    if(value <= VD->getU1())
    {
        VD->setU2(value);
        ui->out_r1->setText(QString::number(VD->getR1()));
        ui->out_r2->setText(QString::number(VD->getR2()));
    }else{
        ui->Spannung_2->setText(QString::number(VD->getU2()));
    }
}
