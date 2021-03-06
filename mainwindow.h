#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  private slots:
    void on_textRegex_textChanged();

    void on_actionQuit_triggered();

    void on_textSample_textChanged();

  private:
    Ui::MainWindow *ui;
    QSettings store;

    void updateUi();
};

#endif // MAINWINDOW_H
