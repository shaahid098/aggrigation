#include <catch2/catch_all.hpp>
#include "../Flight.h"
#include "../Passenger.h"

TEST_CASE("Flight class functionality", "[Flight]") {
    Passenger* alice = new Passenger("Alice Johnson", "A123456", "Window");
    Passenger* bob = new Passenger("Bob Smith", "B654321", "Aisle");
    Passenger* charlie = new Passenger("Charlie Brown", "C987654", "Middle");

    SECTION("Adding passengers to a flight") {
        Flight flight("AA123", "New York");

        flight.addPassenger(alice);
        flight.addPassenger(bob);

        std::string flightInfo = flight.getFlightInfo();

        REQUIRE(flightInfo.find("Alice Johnson") != std::string::npos);
        REQUIRE(flightInfo.find("Bob Smith") != std::string::npos);
        REQUIRE(flightInfo.find("New York") != std::string::npos);
        REQUIRE(flightInfo.find("Charlie Brown") == std::string::npos);
    }

    SECTION("Removing a passenger from a flight") {
        Flight flight("AA123", "New York");

        flight.addPassenger(alice);
        flight.addPassenger(bob);
        flight.addPassenger(charlie);

        REQUIRE(flight.removePassenger("B654321")); // Remove Bob
        REQUIRE_FALSE(flight.removePassenger("B654321")); // Try to remove Bob again

        std::string flightInfo = flight.getFlightInfo();
        REQUIRE(flightInfo.find("Bob Smith") == std::string::npos); // Bob should no longer be in the info
        REQUIRE(flightInfo.find("Alice Johnson") != std::string::npos);
        REQUIRE(flightInfo.find("Charlie Brown") != std::string::npos);
    }

    SECTION("Removing a non-existent passenger from a flight") {
        Flight flight("AA123", "New York");

        flight.addPassenger(alice);

        REQUIRE_FALSE(flight.removePassenger("InvalidPassport")); // Attempt to remove a non-existent passenger

        std::string flightInfo = flight.getFlightInfo();
        REQUIRE(flightInfo.find("Alice Johnson") != std::string::npos); // Alice should still be in the info
    }

    SECTION("Flight info with no passengers") {
        Flight flight("AA123", "New York");

        std::string flightInfo = flight.getFlightInfo();
        REQUIRE(flightInfo.find("Passengers on this flight:") != std::string::npos);
        REQUIRE(flightInfo.find("Alice Johnson") == std::string::npos);
    }

    // Clean up dynamically allocated memory
    delete alice;
    delete bob;
    delete charlie;
}
