#ifndef USER_H
#define USER_H

#include <string>
#include "flight.h"
#include "booking.h"

class User {
private:
    std::string user_name;  // 用户名
    std::string password;  // 密码
    std::string phonenumber; // 电话
    Booking users_bookinglist; // 用户的订单列表
    Flight users_flightlist; // 用户即将乘坐的航班的列表
public:
    User(); // 默认构造函数
    User(const std::string& username, const std::string& password, const std::string& phonenumber); // 构造函数

    bool registerUser(const std::string& contactInfo);  // 注册用户
    bool login(const std::string& username, const std::string& password); // 用户登录
    void viewProfile();  // 查看用户信息
    void viewFlight(); // 查看班次users_flightlist
    void viewBooking(); //查看订单users_flightlist
    void updateProfile(const std::string& newPhonenumber); // 更新联系信息
    void bookingFlight(); // 创建一个订单,加入用户的订单列表users_bookinglist
    void cancleFlight(); // 取消一个订单，更新订单列表users_bookinglist
    void checkBooking(); // 支付一个订单，支付后将支付的订单更新到航班列表users_flight

};

#endif // USER_H
