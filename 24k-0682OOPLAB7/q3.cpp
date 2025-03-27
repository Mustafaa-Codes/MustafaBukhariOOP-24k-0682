#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
    string ticketID, passengerName, date, destination;
    double price;
public:
    Ticket(string id, string name, double p, string d, string dest) 
        : ticketID(id), passengerName(name), price(p), date(d), destination(dest) {}
    virtual void reserve() { cout << "Ticket reserved for " << passengerName << " on " << date << endl; }
    virtual void cancel() { cout << "Ticket " << ticketID << " canceled." << endl; }
    virtual void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << "\nPassenger: " << passengerName 
             << "\nPrice: $" << price << "\nDate: " << date << "\nDestination: " << destination << endl;
    }
};

class FlightTicket : public Ticket {
    string airlineName, flightNumber, seatClass;
public:
    FlightTicket(string id, string name, double p, string d, string dest, string airline, string flight, string seat) 
        : Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(flight), seatClass(seat) {}
    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << "\nFlight No: " << flightNumber << "\nClass: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
    string trainNumber, coachType, departureTime;
public:
    TrainTicket(string id, string name, double p, string d, string dest, string train, string coach, string time) 
        : Ticket(id, name, p, d, dest), trainNumber(train), coachType(coach), departureTime(time) {}
    void reserve() override {
        cout << "Train ticket reserved. Auto-assigning seat for " << passengerName << endl;
    }
};

class BusTicket : public Ticket {
    string busCompany;
    int seatNumber;
public:
    BusTicket(string id, string name, double p, string d, string dest, string company, int seat) 
        : Ticket(id, name, p, d, dest), busCompany(company), seatNumber(seat) {}
    void cancel() override {
        cout << "Bus ticket canceled. Last-minute refund processed." << endl;
    }
};

class ConcertTicket : public Ticket {
    string artistName, venue, seatType;
public:
    ConcertTicket(string id, string name, double p, string d, string venueName, string artist, string seat) 
        : Ticket(id, name, p, d, venueName), artistName(artist), venue(venueName), seatType(seat) {}
    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << "\nVenue: " << venue << "\nSeat Type: " << seatType << endl;
    }
};

int main() {
    FlightTicket flight("F123", "Alice", 350.0, "2025-07-10", "New York", "AirwaysX", "AX123", "Business");
    TrainTicket train("T456", "Bob", 120.0, "2025-07-12", "Los Angeles", "TrainY", "First Class", "08:30 AM");
    BusTicket bus("B789", "Charlie", 45.0, "2025-07-15", "San Francisco", "BusCo", 12);
    ConcertTicket concert("C101", "David", 75.0, "2025-07-20", "Madison Square Garden", "Rock Band", "VIP");
    
    flight.reserve();
    train.reserve();
    bus.reserve();
    concert.reserve();
    
    flight.displayTicketInfo();
    train.displayTicketInfo();
    bus.displayTicketInfo();
    concert.displayTicketInfo();
    
    bus.cancel();
    
    return 0;
}
