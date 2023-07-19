#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QTimer>
#include <windows.h>
#include <unistd.h>
#include <random>
#include <thread>
#include <QtCore>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);
  mThread = new MyThread(this);

  connect(mThread,
          SIGNAL(NumberChanged(int)),
          this,
          SLOT(onNumberChanged(int)));
}


void MainWindow::tcpConnect(QString str){
  socket->connectToHost(str,1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
  }
  else{
    qDebug() << "Disconnected";
  }
}


void MainWindow::putData(){
  QString str;
  qint64 msecdate;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> distr(ui->lcdNumberMin->value(), ui->lcdNumberMax->value());

  if(socket->state()== QAbstractSocket::ConnectedState){

    msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();

    str = "set "+ QString::number(msecdate) + " " +
          QString::number(distr(gen))+"\r\n";

    ui->textBrowser->append(str);

    qDebug() << str;
    qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";

    if(socket->waitForBytesWritten(3000)){
      qDebug() << "wrote";
    }
  }
}


void MainWindow::connectIp()
{
  QString str;

  str = ui->lineEditIP->text();

  tcpConnect(str);
}


void MainWindow::disconnectIp()
{
  QString str;

  str = ui->lineEditIP->text();

  socket->disconnectFromHost();
}


void MainWindow::onNumberChanged(int Number)
{
  qDebug() << Number;
  mThread->tempo = ui->horizontalSliderTiming->value();
  putData();
}


MainWindow::~MainWindow(){
  delete socket;
  delete ui;
}


void MainWindow::tstart()
{
  mThread->Stop = false;
  mThread->tempo = ui->horizontalSliderTiming->value();

  mThread->start();
}


void MainWindow::tstop()
{
  QMutex mutex;

  mutex.lock();
  mThread->Stop = true;
  mutex.unlock();
}

