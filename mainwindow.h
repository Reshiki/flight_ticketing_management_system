#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "flight.h"
#include "booking.h"
#include "user.h"
#include "admin.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // 初始化窗口

    // 连接数据库
    //.....

    // 创建一个默认的航班列表，读取数据库中的航班列表
    Flight flightList;
    // 设置窗口的属性，大小

    // 设置按钮输入框等，用槽函数连接各个按钮与对应的函数，

    // 1 用户登录界面，注册和登录，每次注册写入数据库
    User user1;
    Admin adminstrator1;
    Booking bookong;
    // 2 登录后界面，包括user.h/admin.h中该有的各个功能，连接按钮和函数,以及退出系统等功能

    // 2.1 user界面
    // 2.1.1 ......
    // 2.2 admin界面
    // 2.2.2 ......

private slots:
    void on_pushButton_login_clicked(); // 登录按钮
    void on_pushButton_exit_clicked(); // 退出按钮
    void on_checkBox_toggled(bool checked); // 是否显示密码
    void on_pushButton_register_clicked(); // 注册按钮

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
