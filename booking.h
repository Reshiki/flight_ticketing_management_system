#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include <vector>
#include "flight.h"

struct BookingInfo {
    std::string username;       // 用户名
    std::string flightNumber;   // 航班号
    std::string bookingID;      // 订单ID
    bool paymentStatus;         // 支付状态
};

class Booking {
private:
    std::vector<BookingInfo> bookings;  // 订单列表

public:
    std::string bookFlight(const std::string& username, const std::string& flightNumber); // 预订航班
    bool cancelBooking(const std::string& bookingID); // 取消订单
    void viewBookings(const std::string& username);   // 查看订单
    void addFlight(Flight& flights); // 将已经支付的订单加入到航班列表

};

#endif // BOOKING_H
