#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked(); // 登录按钮
    void on_pushButton_exit_clicked(); // 退出按钮
    void on_checkBox_toggled(bool checked); // 是否显示密码
    void on_pushButton_register_clicked(); // 注册按钮

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
