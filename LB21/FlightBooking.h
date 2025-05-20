
#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H

class FlightBooking
{
public:
    FlightBooking()
    {
    id = 0;
    capacity = 0;
    reserved = 0;
    }
    FlightBooking(int id, int capacity, int reserved);
    void printStatus() const;
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);
    int getId() const { return id; }

private:
    int id;
    int capacity;
    int reserved;
};


#endif //FLIGHTBOOKING_H
