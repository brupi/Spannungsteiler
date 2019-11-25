#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include "voltagedivider.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Quellspannung_editingFinished();
    void on_Spannung_2_editingFinished();

private:
    Ui::MainWindow *ui;
    VoltageDivider VD;
};
#endif // MAINWINDOW_H
