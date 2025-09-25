#include "Flight.h"
#include <sstream>
#include <iomanip>

//@param Implementation of the Flight class.
Flight::Flight(std::string flightNumber, std::string destination)
        :flightNumber(flightNumber),destination(destination) {

}

void Flight::addPassenger(Passenger* passenger) {
        passengers.push_back(passenger);
}

bool Flight::removePassenger(const std::string &passportNumber) {
        for (std::vector<Passenger*>::iterator it=passengers.begin();
        it  !=  passengers.end(); ++it) {
                if ((*it)->getPassportNumber() == passportNumber) {
                        passengers.erase(it);
                        return true;
                }
        }
        return false;
}

std::string Flight::getFlightInfo() const {
        std::stringstream ss;
        ss <<"Flight Number: "<<flightNumber
        <<", Destination: "<<destination<<std::endl;

        for (const Passenger* passenger : passengers) {
                ss <<"\t"<<passenger->getInfo()<<std::endl;
        }
        ss<<std::endl;
        return ss.str();

}
