#include <iostream>
#include "Passenger.h"

//Testing driver of passenger class
int main() {
    // Create passenger objects
    Passenger *bob= new Passenger("Bob Smith","N457657657346","Window");

    // testing getters
    std::cout<<"Bob's name is: "<<bob->getName()<<std::endl;
    std::cout<<"Bob's Passport Number is: "<<bob->getPassportNumber()<<std::endl;
    std::cout<<"Bob's Seat Preference is: "<<bob->getSeatPreferences()<<std::endl;

    // Testing getInfo method
    std::cout<<"All about Bob: "<< bob->getInfo()<<std::endl;

    delete bob;
}