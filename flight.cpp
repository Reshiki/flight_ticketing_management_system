#include "flight.h"
#include "databaseManagement.h"

Flight Flight::findById(int id) {
    QSqlDatabase db = DatabaseManager::instance().getDatabase("FlightDB");
    QSqlQuery query(db);
    query.prepare("SELECT * FROM flights WHERE id = :id");
    query.bindValue(":id", id);
    Flight flight;
    if (query.exec() && query.next()) {
        flight.id = query.value("id").toInt();
        flight.flightNumber = query.value("flight_number").toString();
        flight.departure = query.value("departure").toString();
        flight.destination = query.value("destination").toString();
        flight.departureTime = query.value("departure_time").toString();
        flight.arrivalTime = query.value("arrival_time").toString();
    }
    return flight;
}
