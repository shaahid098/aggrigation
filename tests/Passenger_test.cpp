#include <catch2/catch_all.hpp>
#include "../Passenger.h"

TEST_CASE("Passenger class functionality", "[Passenger]") {
    SECTION("Creating a Passenger and verifying attributes") {
        Passenger passenger("Alice Johnson", "A123456", "Window");

        CHECK(passenger.getName() == "Alice Johnson");
        CHECK(passenger.getPassportNumber() == "A123456");
        CHECK(passenger.getSeatPreference() == "Window");
    }

    SECTION("Passenger info should be formatted correctly") {
        Passenger passenger("Bob Smith", "B654321", "Aisle");

        std::string expectedInfo = "Passenger Name: Bob Smith, Passport Number: B654321, Seat Preference: Aisle";
        CHECK(passenger.getInfo() == expectedInfo);
    }

    SECTION("Different passengers should have unique attributes") {
        Passenger passenger1("Charlie Brown", "C987654", "Middle");
        Passenger passenger2("Daisy DukE", "D112233", "Window");

        CHECK(passenger1.getName() == "Charlie Brown");
        CHECK(passenger1.getPassportNumber() == "C987654");
        CHECK(passenger1.getSeatPreference() == "Middle");

        CHECK(passenger2.getName() == "Daisy Duke");
        CHECK(passenger2.getPassportNumber() == "D112233");
        CHECK(passenger2.getSeatPreference() == "Window");

        CHECK(passenger1.getInfo() != passenger2.getInfo());
    }
}
