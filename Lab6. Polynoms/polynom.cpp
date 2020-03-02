#include "polynom.h"
#include <QDebug>


int Polynom::numOfObjects;
int Polynom::getNumOfObjects()
{
    return numOfObjects;
}

void Polynom::setNumOfObjects(int value)
{
    numOfObjects = value;
}

void Polynom::incCount()
{
    numOfObjects++;
}

Polynom::Polynom(){
    incCount();
}

Polynom::Polynom(double a1, double b1, double c1)
{
    a = a1;
    b = b1;
    c = c1;
    incCount();

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
    incCount();

}


Polynom Polynom::operator+(Polynom& _other)
{
    return Polynom(this->a + _other.a, this->b + _other.b, this->c + _other.c);
}

Polynom Polynom::operator-(Polynom _other)
{
    return Polynom(this->a - _other.a, this->b - _other.b, this->c - _other.c);
}

Polynom Polynom::operator*(double scal)
{
    return Polynom(this->a * scal, this->b * scal, this->c * scal);
}

double Polynom::getValue(double x)
{
    return a*x*x + b*x + c;
}

double Polynom::operator()(double x)
{
    return getValue(x);
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

void Polynom::operator!()
{
    this->a *= -1;
    this->b *= -1;
    this->c *= -1;
}

double& Polynom::operator[](int n)
{
    if(n == 0) return this->a;
    else if (n == 1) return this->b;
    else return this->c;
}

bool Polynom::operator==(Polynom _other)
{
    return (*this)[0] == _other[0];
}

void Polynom::operator>>(QLineEdit *text)
{
    text->setText(this->printPolynom());
}

void Polynom::operator<<(QLineEdit* textEdit)
{
    Polynom newPoly(textEdit->text());
    *this = newPoly;
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

