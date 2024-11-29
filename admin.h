#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "flight.h"

class Admin {
private:
    std::string adminUsername; // 用户名
    std::string adminPassword; // 管理员用户名

public:
    Admin(std::string username, std::string password);
    bool login(std::string username, std::string password); // 管理员登录
    void cancleFlight(Flight& flightList); // 取消主航班的一个班次
    void addFlight(Flight& flightList); // 增加一个航班
    void changeFlight(Flight& flightList); // 修改某个航班的信息
};

#endif // ADMIN_H
