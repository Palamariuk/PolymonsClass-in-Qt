#ifndef POLYNOM_H
#define POLYNOM_H

#include <QString>
#include <cmath>

class Polynom
{
private:
    double a;
    double b;
    double c;
public:
    Polynom();
    Polynom(double a1, double b1, double c1);
    Polynom(QString text);

    Polynom sumPolynoms(Polynom poly); //get sum of the polynoms
    QString printPolynom(); //print polynom function

    double getValue(double x); //find value of expression for x
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

};



#endif // POLYNOM_H
