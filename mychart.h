#ifndef MYCHART_H
#define MYCHART_H

#include <QObject>
#include <QtMath>
#include <QDebug>
#include "my_property.h"

class IFun {
public:
    virtual ~IFun() { qDebug() << label; };
    virtual double calculate(double x) = 0;
    QString label;
};

class Fun_1 : public IFun {
public:
    Fun_1(){ label = "y = sin(x)"; }
    double calculate(double x) override { return qSin(x); }
};
class Fun_2 : public IFun {
public:
    Fun_2(){ label = "y = x"; }
    double calculate(double x) override { return x; }
};
class Fun_3 : public IFun {
public:
    Fun_3(){ label = "y = |x - 2.5|"; }
    double calculate(double x) override { return qFabs(x-2.5); }
};
class Fun_4 : public IFun {
public:
    Fun_4(){ label = "y = x * x"; }
    double calculate(double x) override { return x*x; }
};
class Fun_5 : public IFun {
public:
    Fun_5(){ label = "y = log2(x)"; }
    double calculate(double x) override { return qLn(x)/qLn(2.0); }
};

class MyChart : public QObject
{
    Q_OBJECT
    MY_PROPERTY(int, currentFunction)
public:
    explicit MyChart(QObject *parent = nullptr);
    ~MyChart();
private:
    QList <IFun *> arrayFunctions;
public:
    Q_INVOKABLE int sizeFunctions();
    Q_INVOKABLE QString getFunctionLabel(int n);
    Q_INVOKABLE double calculate(double x);
};



#endif // MYCHART_H
