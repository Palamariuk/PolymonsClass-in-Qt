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
    Polynom P1(ui->lineEdit->text());

    double a = ui->lineEdit_4->text().toDouble();
    double b = ui->lineEdit_3->text().toDouble();
    double c = ui->lineEdit_2->text().toDouble();
    Polynom P2(a, b, c);
    Polynom P3;

    P3 = P1.sumPolynoms(P2);
    ui->lineEdit_5->setText(P3.printPolynom());

    P3 = P1;
    P3.multByNumber(ui->lineEdit_6->text().toDouble());
    ui->lineEdit_7->setText(P3.printPolynom());

    ui->lineEdit_9->setText(QString::number(P1.getDerivation(ui->lineEdit_8->text().toDouble())));

    ui->lineEdit_11->setText(QString::number(P2.getIntegralOnInterval(ui->lineEdit_10->text().toDouble(),ui->lineEdit_12->text().toDouble())));

    double x1, x2;
    P1.getRoots(x1, x2);
    ui->lineEdit_13->setText(QString::number(x1));
    ui->lineEdit_14->setText(QString::number(x2));

    double x = ui->lineEdit_15->text().toDouble();
    ui->lineEdit_16->setText(QString::number(P1.getValue(x)));
    ui->lineEdit_17->setText(QString::number(P2.getValue(x)));

}

void MainWindow::on_pushButton_2_clicked()
{
    Polynom P1(ui->lineEdit_18->text());
    ui->lineEdit_22->setText(QString::number(P1.getA()));
    ui->lineEdit_23->setText(QString::number(P1.getB()));
    ui->lineEdit_24->setText(QString::number(P1.getC()));
    P1.setA(ui->lineEdit_19->text().toDouble());
    P1.setB(ui->lineEdit_20->text().toDouble());
    P1.setC(ui->lineEdit_21->text().toDouble());
    ui->lineEdit_25->setText(P1.printPolynom());
}
