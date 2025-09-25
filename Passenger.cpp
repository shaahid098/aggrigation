
#include "Passenger.h"
#include <sstream>

//@param implementation of passenger class methods
Passenger::Passenger(std::string name,std::string passportNumber,std::string seatPreference) {
    this->name = name;
    this->passportNumber = passportNumber;
    this->seatPreference = seatPreference;

}

std::string Passenger::getName() const {
    return name;
}
std::string Passenger::getPassportNumber() const {
    return passportNumber;
}

std::string Passenger::getSeatPreferences() const {
    return seatPreference;
}
std::string Passenger::getInfo() const {        //Combines all the passengers details into list of strings
    std::stringstream ss;
    ss <<getInfo() << " (" << getPassportNumber() << ") Seat Pref: "
        << getSeatPreferences();

    return ss.str();
}