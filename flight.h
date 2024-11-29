#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>

struct FlightInfo {
    std::string flightNumber;   // 航班号
    std::string departure;      // 出发地
    std::string destination;    // 目的地
    std::string departureTime;  // 出发时间
    std::string arrivalTime;    // 到达时间
    double price;               // 票价
};

class Flight {
private:
    std::vector<FlightInfo> flights;  // 航班列表

public:
    Flight(); // 默认构造函数
    void addFlight(const FlightInfo& flight);  // 添加航班
    void removeFlight(const std::string& flightNumber); // 删除航班
    std::vector<FlightInfo> searchFlights(const std::string& departure, const std::string& destination); // 查询航班
    void displayFlights();  // 显示所有航班
};

#endif // FLIGHT_H
