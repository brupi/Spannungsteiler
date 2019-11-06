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
    VoltageDivider *v = new VoltageDivider();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Quellspannung_editingFinished();

    void on_Spannung_2_editingFinished();

    void on_textBrowser_anchorClicked(const QUrl &arg1);

    void on_out_r1_textChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
