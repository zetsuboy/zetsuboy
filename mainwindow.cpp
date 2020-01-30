#include "mainwindow.h"
#include "ui_mainwindow.h"
static int counter = 0;
static bool plus = 0, minus = 0, divide = 0, multi = 0;
static  double first_number, second_number;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Button0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->Button1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->Button2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->Button3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->Button4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->Button5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->Button6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->Button7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->Button8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->Button9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->ButtonAC, SIGNAL(clicked()), this, SLOT(on_ButtonAC_clicked()));
    connect(ui->ButtonPlus, SIGNAL(clicked()), this, SLOT(on_ButtonPlus_clicked()));
    connect(ui->ButtonMinus, SIGNAL(clicked()), this, SLOT(on_ButtonMinus_clicked()));
    connect(ui->ButtonDivide, SIGNAL(clicked()), this, SLOT(on_ButtonDivide_clicked()));
    connect(ui->ButtonMulti, SIGNAL(clicked()), this, SLOT(on_ButtonMulti_clicked()));
    connect(ui->ButtonEqual, SIGNAL(clicked()), this, SLOT(on_ButtonEqual_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    counter++;
    if (counter >= 17)
    {

    }
    else
    {
        double all_numbers = (ui->result_show->text() + button->text()).toDouble();
    QString new_label = QString::number(all_numbers, 'g', 18);

    ui->result_show->setText(new_label);
    }
}

void MainWindow::on_ButtonAC_clicked()
{
    QString new_label = QString::number(0, 10);
    ui->result_show->setText(new_label);
    counter = 0;
}

void MainWindow::on_ButtonPlus_clicked()
{
    if (plus != 1 && minus != 1 && divide != 1 && multi != 1 && counter != 0)
    {
    plus = 1;
    first_number = (ui->result_show->text().toDouble());
    on_ButtonAC_clicked();
    ui->sign->setText("+");
    }
}

void MainWindow::on_ButtonMinus_clicked()
{
    if (plus != 1 && minus != 1 && divide != 1 && multi != 1 && counter != 0)
    {
    minus = 1;
    first_number = (ui->result_show->text().toDouble());
    on_ButtonAC_clicked();
    ui->sign->setText("-");
    }
}

void MainWindow::on_ButtonMulti_clicked()
{
    if (plus != 1 && minus != 1 && divide != 1 && multi != 1 && counter != 0)
    {
    multi = 1;
    first_number = (ui->result_show->text().toDouble());
    on_ButtonAC_clicked();
    ui->sign->setText("*");
    }
}

void MainWindow::on_ButtonDivide_clicked()
{
    if (plus != 1 && minus != 1 && divide != 1 && multi != 1 && counter != 0)
    {
    divide = 1;
    first_number = (ui->result_show->text().toDouble());
    on_ButtonAC_clicked();
    ui->sign->setText("/");
    }
}

void MainWindow::on_ButtonEqual_clicked()
{
    if ((plus == 1 || minus == 1 || multi == 1 || divide == 1)&& counter != 0)
    {
        second_number = ui->result_show->text().toDouble();
        if (plus == 1)
        {
            first_number = first_number + second_number;
            QString new_label = QString::number(first_number, 'g', 18);
            ui->result_show->setText(new_label);
            plus = 0;
            ui->sign->setText("");
        }
        else if (minus == 1)
        {
            first_number = first_number - second_number;
            QString new_label = QString::number(first_number, 'g', 18);
            ui->result_show->setText(new_label);
            minus = 0;
            ui->sign->setText("");
        }
        else if (multi == 1)
        {
            first_number = first_number * second_number;
            QString new_label = QString::number(first_number, 'g', 18);
            ui->result_show->setText(new_label);
            multi = 0;
            ui->sign->setText("");
        }
        else if (divide == 1)
        {
            first_number = first_number / second_number;
            QString new_label = QString::number(first_number, 'g', 18);
            ui->result_show->setText(new_label);
            divide = 0;
            ui->sign->setText("");
        }
    }
}
