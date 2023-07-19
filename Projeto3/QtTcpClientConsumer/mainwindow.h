#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
  void tcpConnect(QString str);

public slots:
  void getData();
  void connectIp();
  void disconnectIp();
  void stopData();
  void updateIp();
  void timerEvent(QTimerEvent *e);

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  //int timer;
};

#endif // MAINWINDOW_H
