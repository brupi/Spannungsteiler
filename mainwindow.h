#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include "voltagedivider.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE
/// \brief class for MainWindow
class MainWindow : public QMainWindow
{
  Q_OBJECT

 public:
  /// \brief creates MainWindow
  /// \param parent pointer
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private slots:
  void on_Quellspannung_editingFinished();
  void on_Spannung_2_editingFinished();

 private:
  Ui::MainWindow* ui;
  VoltageDivider VD;
};
#endif  // MAINWINDOW_H
