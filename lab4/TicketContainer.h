#ifndef TICKET_CONTAINER_H
#define TICKET_CONTAINER_H

#include "TicketClass.h"
#include "Trains.h"


class TicketContainer 
{
private:
    ticket* tickets;
    trains* train;
    int num_trains;
    int num_tickets;
public:
    TicketContainer();
    TicketContainer(int trainamount);
    ~TicketContainer();

    void buyTicket(ticket aticket);
    void addTrain(trains atrain);
    void loadFromFile(string filename);
    void saveToFile(string filename);
    void displayTickets();
    void displayTrains();
    void findMostExpensive();
    void availableSeatsInTrain();

};

#endif