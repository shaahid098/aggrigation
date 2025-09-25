#include <iostream>
#include "Passenger.h"
#include "Flight.h"

//Testing driver of passenger class


int main() {
    Passenger *jim= new Passenger("Jim Robinson","Y98776789","aisle");
    Passenger *janet= new Passenger("janet Jones","a3532443","Window");
    Passenger *fen= new Passenger("Fen Chen","gt5453443","Window");

    // Creating flight
    Flight *flight=new Flight("FHERS-09","New York");
    Flight *flight2=new Flight("HHHGHHJK-09","California");

    //adding passengers to the flight
    flight->addPassenger(jim);
    flight->addPassenger(janet);
    flight->addPassenger(fen);

    //removing passergers
    std::cout<<flight->removePassenger("Y98776789");
    std::cout<<flight->removePassenger("a3532443");

    //getting details of flight
    std::cout<<flight->getFlightInfo();

    flight2->addPassenger(jim);
    flight2->addPassenger(fen);

    //getting details of flight2
    std::cout<<flight2->getFlightInfo();

    //free up the memory
    delete flight;
    delete flight2;

    std::cout<<fen->getInfo();

    delete fen;
    delete jim;
    delete janet;
    return 0;
}
