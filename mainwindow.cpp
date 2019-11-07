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
    VD->setU1(ui->Quellspannung->text().toDouble());
    ui->out_r1->setText(QString::number(VD->getR1()));
    ui->out_r2->setText(QString::number(VD->getR2()));
}

void MainWindow::on_Spannung_2_editingFinished()
{
    VD->setU2(ui->Spannung_2->text().toDouble());
    ui->out_r1->setText(QString::number(VD->getR1()));
    ui->out_r2->setText(QString::number(VD->getR2()));
}
