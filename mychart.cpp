#include "mychart.h"


MyChart::MyChart(QObject *parent) : QObject(parent)
{
    currentFunction(0);
    arrayFunctions.push_back(new Fun_1());
    arrayFunctions.push_back(new Fun_2());
    arrayFunctions.push_back(new Fun_3());
    arrayFunctions.push_back(new Fun_4());
    arrayFunctions.push_back(new Fun_5());
}

MyChart::~MyChart()
{
    qDebug() << "Delete functions";
    for(int i=0; i<arrayFunctions.size(); ++i)
        delete arrayFunctions[i];
}

int MyChart::sizeFunctions()
{
    return arrayFunctions.size();
}

QString MyChart::getFunctionLabel(int n)
{
    return arrayFunctions[n]->label;
}

double MyChart::calculate(double x)
{
    return arrayFunctions[currentFunction()]->calculate(x);
}
