#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Polynom P1;
    P1 << ui->firstPolynom; //ввід полінома з форми
    double a = ui->secondPolynom_a->text().toDouble();
    double b = ui->secondPolynom_b->text().toDouble();
    double c = ui->secondPolynom_c->text().toDouble();
    Polynom P2(a, b, c);

    if(P1 == P2) {
        ui->comparison->setText("P1 == P2");
    } else {
        ui->comparison->setText("P1 <> P2");
    }

    Polynom P3 = P1 + P2; //додавання поліномів
    P3 >> ui->sumLabel; // вивід полінома на форму
    P3 = P1 - P2; //віднімання поліномів
    P3 >> ui->difLabel;
    P3 = P2;
    !P3; //обернені коефіцієнти
    P3 >> ui->negPoly;

    ui->coefficient->setText(QString::number(P1[ui->atNumber->text().toInt()])); // звернення через квадратні дужки

    P3 = P1 * ui->scal->text().toDouble(); //множення полінома не скаляр
    P3 >> ui->mult;

    ui->der->setText(QString::number(P1.getDerivation(ui->xDer->text().toDouble())));

    ui->IntResult->setText(QString::number(P2.getIntegralOnInterval(ui->firstIntVal->text().toDouble(),ui->secondIntVal->text().toDouble())));

    double x1, x2;
    P1.getRoots(x1, x2);
    ui->firstRoot->setText(QString::number(x1));
    ui->secondRoot->setText(QString::number(x2));

    double x = ui->xNum->text().toDouble();
    ui->P1val->setText(QString::number(P1(x))); //виведення значення виразу від Х
    ui->P2val->setText(QString::number(P2(x)));

    ui->numOfObj->setText(QString::number(Polynom::getNumOfObjects()) + " objects have been created");

}
