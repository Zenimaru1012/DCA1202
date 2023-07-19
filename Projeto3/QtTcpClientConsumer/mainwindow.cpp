#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plotter.h"
#include <QDateTime>
#include <vector>

int timer = 0;

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);
  //timer = 0;
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

void MainWindow::getData()
{
  if(timer)
  {
      killTimer(timer);
  }
  timer = ui->horizontalSlider->value();

  timer = startTimer((timer) * 1000);
}


void MainWindow::timerEvent(QTimerEvent *e){
  QString str;
  QStringList list;
  qint64 thetime, num;
  double max_x, min_x, max_y, min_y;
  std::vector<double> time;
  std::vector<double> data;
  std::vector<double> temposnorm;
  std::vector<double> dadosnorm;



  qDebug() << "to get data...";
  if(socket->state() == QAbstractSocket::ConnectedState){
    if(socket->isOpen()){
      qDebug() << "reading...";
        str = "get " + ui->lineEditIP->text() + " 30\r\n";
      socket->write(str.toStdString().c_str());
      socket->waitForBytesWritten();
      socket->waitForReadyRead();
      qDebug() << socket->bytesAvailable();
      time.clear();
      data.clear();
      while(socket->bytesAvailable()){
        str = socket->readLine().replace("\n","").replace("\r","");
        list = str.split(" ");

        if(list.size() == 2){
          bool ok;
          str = list.at(0);
          thetime = str.toLongLong(&ok);
          time.push_back(thetime);

          str = list.at(1);
          num = str.toLongLong(&ok);
          data.push_back(num);

          qDebug() << thetime << ": " << str;
        }
      }
    }
  }

  qDebug() << data.size() << time.size();
  max_x = time[0], min_x = time[0];
  max_y = data[0], min_y = time[0];

  for(int i=1; i<30; i++)
  {
    if(time[i] < min_x) min_x = time[i];
    else if(time[i] > max_x) max_x = time[i];

    if(data[i] < min_y) min_y = data[i];
    else if(data[i] > max_y) max_y = data[i];
  }

  qDebug() << max_x-min_x;
  qDebug() << max_y-min_y;

  //Normalizacao
  temposnorm.clear();
  dadosnorm.clear();

  for(int i=0; i<30;i++)
  {
    temposnorm.push_back((time[i] - min_x) / (max_x - min_x));
    dadosnorm.push_back((data[i] - min_y) / (max_y - min_y));
  }

  ui->widgetPlotter->loadData(temposnorm, dadosnorm);
}

void MainWindow::stopData()
{
  if(timer)
  {
    killTimer(timer);
  }
}

void MainWindow::updateIp()
{
  QString str;

  ui->listWidget->clear();

  if(socket->state() == QAbstractSocket::ConnectedState)
  {
    socket->write("list\r\n");
    socket->waitForBytesWritten();
    socket->waitForReadyRead();
    while(socket->bytesAvailable())
    {
      str = socket->readLine().replace("\n","").replace("\r","");
      ui->listWidget->addItem(str);
    }
  }
  else
  {
    ui->listWidget->addItem("Nada");
  }
}


MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}
