#include "polynom.h"
#include <QDebug>

Polynom::Polynom(){}

Polynom::Polynom(double a1, double b1, double c1)
{
    a = a1;
    b = b1;
    c = c1;
}

Polynom::Polynom(QString text)
{
    QString strA = text.left(text.indexOf("x2"));
    QString strB = text.mid(strA.length()+2, text.lastIndexOf("x") - strA.length()-2);
    QString strC = text.right(text.length() - text.lastIndexOf("x")-1);
    double A = strA.toDouble();
    double B = strB.toDouble();
    double C = strC.toDouble();

    a = A;
    b = B;
    c = C;
}

double Polynom::getValue(double x)
{
    return a*x*x + b*x + c;
}

double Polynom::getDerivation(double x)
{
    return 2*a*x + b;
}

double Polynom::getIntegralOnInterval(double start, double stop)
{
    double firstValue = (a * stop * stop * stop / 3.0) + (b * stop * stop / 2.0) + (c * stop);
    double secondValue = (a * start * start * start / 3.0) + (b * start * start / 2.0) + (c * start);
    return firstValue - secondValue;
}

void Polynom::getRoots(double &x1, double &x2)
{
    double D = b*b - 4 * a * c;
    x1 = ((-1) * b + sqrt(D)) / (2 * a);
    x2 = ((-1) * b - sqrt(D)) / (2 * a);
}

Polynom Polynom::sumPolynoms(Polynom poly)
{
    Polynom newPoly;
    newPoly.a = this->a + poly.a;
    newPoly.b = this->b + poly.b;
    newPoly.c = this->c + poly.c;
    return newPoly;
}

void Polynom::multByNumber(double num)
{
    this->a *= num;
    this->b *= num;
    this->c *= num;
}

void Polynom::setA(double a1)
{
    a = a1;
}

void Polynom::setB(double b1)
{
    b = b1;
}

void Polynom::setC(double c1)
{
    c = c1;
}

double Polynom::getA()
{
    return this->a;
}

double Polynom::getB()
{
    return this->b;
}

double Polynom::getC()
{
    return this->c;
}



QString Polynom::printPolynom()
{
    QString poly;
    poly += QString::number(this->a) + "x2";
    if(this->b >= 0) poly += "+";
    poly += QString::number(this->b) + "x";
    if(this->c >= 0) poly += "+";
    poly += QString::number(this->c);
    return poly;

}

