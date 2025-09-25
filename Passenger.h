
#ifndef PASSENGER_H
#define PASSENGER_H
#include<string>
class Passenger {
private:
    std::string name;   // name of the passenger
    std::string passportNumber; // Unique passport number
    std::string seatPreference;  // Preferred seat (e.g., window)

public:
    Passenger(std::string name,std::string passportNumber,std::string seatPreference);

    //getters
    std::string getName() const;    // Returns passenger's name
    std::string getPassportNumber() const;  // Returns passport number
    std::string getSeatPreferences() const; // Returns seat preference
    std::string getInfo() const;    //Returns the details of all the passengers infomation
};
#endif // PASSENGER_H
