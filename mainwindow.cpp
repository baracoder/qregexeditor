#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  store("bara","QRegexEditor")
{
  ui->setupUi(this);
  ui->textRegex->setText(store.value("regex",QString("")).toString());
  ui->textSample->setText(store.value("sample",QString("")).toString());
}

MainWindow::~MainWindow()
{
  store.setValue("regex",ui->textRegex->toPlainText());
  store.setValue("sample",ui->textSample->toPlainText());
  delete ui;
}

void MainWindow::on_textRegex_textChanged()
{
  updateUi();
}

void MainWindow::on_actionQuit_triggered()
{
  qApp->quit();
}

void MainWindow::updateUi()
{
    QString textRegex = ui->textRegex->toPlainText();
    QRegExp r(textRegex);

    if (r.isValid()) {
      ui->textRegex->setStyleSheet("background-color: #AFA;");
    } else {
      ui->textRegex->setStyleSheet("background-color: #FAA;");
      return;
    }

    QString textSample = ui->textSample->toPlainText();


    QStringList matches;

    int nr = 0;
    int lastIndex = 0;
    while (-1 != (lastIndex = r.indexIn(textSample, lastIndex))) {
      lastIndex += r.cap().length();
      QStringList matchStrings;

      matchStrings.append(QString("%1").arg(nr++));
      int i = 0;
      for (QString& s:r.capturedTexts()) {
        matchStrings.append(QString("%1: %2").arg(i).arg(s));
        i++;
      }
      matches.append(matchStrings.join("\n"));
    }
    ui->textMatches->setText(matches.join("\n\n"));
}

void MainWindow::on_textSample_textChanged()
{
   updateUi();
}
