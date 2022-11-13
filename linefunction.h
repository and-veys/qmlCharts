#ifndef LINEFUNCTION_H
#define LINEFUNCTION_H

#include <QObject>
#include <QPointF>

class LineFunction  : public QObject
{
    Q_OBJECT
public:
    LineFunction();
    ~LineFunction();
    Q_INVOKABLE QPointF getPointData(int n);
    Q_INVOKABLE QPointF getPointLine(int n);
    Q_INVOKABLE  int getSize();
private:
    QList<QPointF *> points;
    double coef_A;
    double coef_B;
    void setCoefficients();
};

#endif // LINEFUNCTION_H
