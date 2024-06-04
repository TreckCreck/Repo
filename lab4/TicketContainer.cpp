#include "TicketContainer.h"

TicketContainer::TicketContainer(int num_trains) 
{
    train = new trains[num_trains];
    num_tickets = 0;
    for (int i = 0; i < num_trains; i++)
        num_tickets += train[i].getNumCoaches()*train[i].getSeatAmount();
    tickets = new ticket[num_tickets];
    cout << "\n������ ����������� ������ TicketContainer:";
    cout << "\n �������� �������� - " << num_tickets;
}

TicketContainer::~TicketContainer() 
{
    delete[] train;
    delete[] tickets;
    num_tickets = 0; 
    num_trains = 0;
    cout << "\n������ ���������� ������ TicketContainer:";
    cout << "\n ���������� ������ �����������";
}

void buyTicket(ticket aticket)
{


}
void addTrain(trains atrain)
{

}
void TicketContainer::loadFromFile(string filename) 
{
    ifstream readfile;
    readfile.open(filename);
    if (!readfile.is_open())
    {
        cout << "\n\n���� ������ �� ������!" << endl;
        system("pause");
        exit(1);
    }
    trains d;
    int N = d.checkamount();
    readfile >> N;
    readfile.get();
    for (int i = 0; i < N; i++)
    {
        trains new_train;
        new_train.read_trains_from(readfile);
        addTrain(new_train);
    }
    readfile.close();
    cout << "\n��������� ������ �� ����� " << filename << ":";
    readfile.open("tickets.txt");
    if (!readfile.is_open())
    {
        cout << "\n\n���� ������ �� ������!" << endl;
        system("pause");
        exit(1);
    }
    ticket t;
    N = t.checkamount();
    for (int i = 0; i < N; i++)
    {
        ticket new_ticket;
        new_ticket.read_from("tickets.txt");
    }
}

void TicketContainer::saveToFile(string filename)
{
    // ���������� ������ � ����
}

void TicketContainer::displayTickets()
{
    cout << " ��� ������: " << endl;
    for (int i = 0; i < num_tickets; i++)
        tickets[i].display();
}

void TicketContainer::displayTrains()
{
    cout << " ��� ������: " << endl;
    for (int i = 0; i < num_trains; i++)
        train[i].showTrains();
}

void TicketContainer::findMostExpensive()
{

}
void TicketContainer::availableSeatsInTrain()
{

}
