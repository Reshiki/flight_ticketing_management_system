#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked(){
    qDebug() << "尝试登录";

}

void MainWindow::on_checkBox_toggled(bool checked)
{
    if(checked)
    {
        ui->lineEdit_username->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    }
}

void MainWindow::on_pushButton_register_clicked(){

}

void MainWindow::on_pushButton_exit_clicked(){
    QApplication::quit();
}
