#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digits_numbers();
    void on_ButtonAC_clicked();
    void on_ButtonPlus_clicked();
    void on_ButtonMinus_clicked();
    void on_ButtonMulti_clicked();
    void on_ButtonDivide_clicked();
    void on_ButtonEqual_clicked();
};
#endif // MAINWINDOW_H
