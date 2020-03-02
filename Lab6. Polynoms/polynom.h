#ifndef POLYNOM_H
#define POLYNOM_H

#include <QString>
#include <QLineEdit>
#include <cmath>

class Polynom
{
private:
    double a;
    double b;
    double c;

    static int numOfObjects;
public:
    Polynom();
    Polynom(double a1, double b1, double c1);
    Polynom(QString text);

    Polynom operator+(Polynom& _other);
    Polynom operator-(Polynom _other);
    Polynom operator*(double scal);
    void operator!();
    double& operator[](int n);
    bool operator==(Polynom _other);

    void operator>>(QLineEdit* textEdit);
    void operator<<(QLineEdit* textEdit);

    QString printPolynom(); //print polynom function

    double getValue(double x); //find value of expression for x
    double operator()(double x);
    double getDerivation(double x); //find value of first derivation of expression for
    double getIntegralOnInterval(double start, double stop); //find integral on the defined interval

    void getRoots(double &x1, double &x2); //find roots of the equation
    void multByNumber(double num); //multiply current polynom by the number

    void setA(double a); //setter for a
    void setB(double b); //setter for b
    void setC(double c); //setter for c

    double getA(); //getter for a
    double getB(); //getter for b
    double getC(); //getter for c

    static int getNumOfObjects();
    static void setNumOfObjects(int value);
    static void incCount();
};




#endif // POLYNOM_H
