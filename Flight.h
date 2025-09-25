#ifndef FLIGHT_H
#define FLIGHT_H
#include "Passenger.h"
#include <vector>
#include <string>

/*
 *@param header file for the flight class
 *@class manages the passengers details into flight class
 */

class Flight {
private:
std::string flightNumber;    // Unique flight number
std::string destination;    // Flight destination
std::vector<Passenger*> passengers; // pointers to passengers


public:
    Flight(std::string flightNumber, std::string destination);  // Constructor
    void addPassenger(Passenger* passenger);    // Add a passenger to the flight
    bool removePassenger(const std::string &passportNumber);    // Remove a passenger by passport number
    std::string getFlightInfo() const;  // Display info of all passengers on the flight

};


#endif // FLIGHT_H
