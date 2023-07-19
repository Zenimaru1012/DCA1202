#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    void run();
    bool Stop;
    int tempo;

signals:
    void NumberChanged(int);

public slots:

};

#endif // MYTHREAD_H
