#include "linefunction.h"
#include <QDebug>

LineFunction::LineFunction()
{
    points.push_back(new QPointF(7, 13));
    points.push_back(new QPointF(31, 10));
    points.push_back(new QPointF(61, 9));
    points.push_back(new QPointF(99, 10));
    points.push_back(new QPointF(129, 12));
    points.push_back(new QPointF(178, 20));
    points.push_back(new QPointF(209, 26));
    setCoefficients();
}

LineFunction::~LineFunction()
{
    qDebug() << "Delete points";
    for(int i=0; i<points.size(); ++i)
        delete points[i];

}

QPointF LineFunction::getPointData(int n)
{
    return QPointF(*points[n]);
}

QPointF LineFunction::getPointLine(int n)
{
    double x = points[n]->x();
    double y = coef_A*x + coef_B;
    return QPointF(x, y);
}

int LineFunction::getSize()
{
    return points.size();
}

void LineFunction::setCoefficients()
{
    double kX=0;
    double kY=0;
    double kXY=0;
    double kX2=0;
    int n = getSize();
    for(int i=0; i<n; ++i) {
        kX += points[i]->x();
        kY += points[i]->y();
        kXY += (points[i]->x()*points[i]->y());
        kX2 += (points[i]->x()*points[i]->x());
    }
    coef_A = (n*kXY - kX*kY)/(n*kX2 - kX*kX);
    coef_B = (kY - coef_A*kX)/n;
}
