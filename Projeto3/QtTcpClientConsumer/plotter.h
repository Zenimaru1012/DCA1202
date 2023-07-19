#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <vector>

class Plotter : public QWidget
{
    Q_OBJECT
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void loadData(std::vector <double>,std::vector <double>);

private:
    std::vector<double> tempos;
    std::vector<double> dados;
    float time;

signals:

public slots:
};

#endif // PLOTTER_H
