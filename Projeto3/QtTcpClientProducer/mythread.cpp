#include "mythread.h"
#include <QtCore>

MyThread::MyThread(QObject *parent) :
    QThread{parent}
{

}

void MyThread::run()
{
    int i=0;
    bool end = false;

    while(true)
    {
        QMutex mutex;
        mutex.lock();

        if(this->Stop == true)
        {
            end = true;
        }

        mutex.unlock();

        if(end == true)
        {
            break;
        }

        emit NumberChanged(i);

        i++;

        this->sleep(tempo);
    }
}
