#include "mainwindow.h"
#include <QDoubleValidator>
#include <QLineEdit>
#include <QString>
#include <QTextEdit>
#include <QValidator>
#include "ui_mainwindow.h"
#include "voltagedivider.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  QDoubleValidator* input_validator = new QDoubleValidator(0.0, 1000.0, 2);
  ui->Quellspannung->setValidator(input_validator);
  ui->Spannung_2->setValidator(input_validator);
  QPixmap pic(":/resources/image/spannungsteiler.png");
  ui->label->setPixmap(pic);

  // setup values
  ui->Quellspannung->setText(QString::number(10));
  ui->Spannung_2->setText(QString::number(1));
  VD = VoltageDivider(10, 1);
  on_Quellspannung_editingFinished();
  on_Spannung_2_editingFinished();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_Quellspannung_editingFinished()
{
  double value = ui->Quellspannung->text().toDouble();
  // u1 must be higher or the same as u2
  if (value >= VD.getU2())
  {
    VD.setU1(value);
    ui->out_r1->setText(QString::number(VD.getR1()));
    ui->out_r2->setText(QString::number(VD.getR2()));
    ui->label_6->hide();
  }
  else
  {
    ui->Quellspannung->setText(QString::number(VD.getU1()));
    ui->label_6->setText("<font color='red'>U must be higher than U2</font>");
    ui->label_6->show();
  }
}

void MainWindow::on_Spannung_2_editingFinished()
{
  double value = ui->Spannung_2->text().toDouble();
  // u1 must be higher or the same as u2
  if (value <= VD.getU1())
  {
    VD.setU2(value);
    ui->out_r1->setText(QString::number(VD.getR1()));
    ui->out_r2->setText(QString::number(VD.getR2()));
    ui->label_6->hide();
  }
  else
  {
    ui->Spannung_2->setText(QString::number(VD.getU2()));
    ui->label_6->setText("<font color='red'>U must be higher than U2</font>");
    ui->label_6->show();
  }
}
