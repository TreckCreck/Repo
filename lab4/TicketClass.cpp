#include "TicketClass.h"
#include <iostream>

ticket::ticket(int trn, string st1, string st2, string dd, string dt, int cch, int st, int prc)
{
    train = trn;
    station1 = st1;
    station2 = st2;
    dep_day = dd;
    dep_time = dt;
    coach = cch;
    seat = st;
    price = prc;
}

void ticket::read_from(ifstream& readfile)
{
    readfile >> train;
    getline(readfile, station1);
    getline(readfile, station2);
    getline(readfile, dep_day);
    getline(readfile, dep_time);
    readfile >> coach;
    readfile >> seat;
    readfile >> price;
    readfile.get();
}
void ticket::write_to(ofstream& readfile)
{
    readfile << train << endl;
    readfile << station1 << endl;
    readfile << station2 << endl;
    readfile << dep_day << endl;
    readfile << dep_time << endl;
    readfile << coach << endl;
    readfile << seat << endl;
    readfile << price << endl;
}
void ticket::display()
{
    cout << "\n %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << " Номер поезда: " << train << endl;
    cout << " Станция отправления: " << station1 << endl;
    cout << " Станция прибытия: " << station2 << endl;
    cout << " Дата отправления: " << dep_day << endl;
    cout << " Время отправления: " << dep_time << endl;
    cout << " Номер вагона: " << coach << endl;
    cout << " Номер места: " << seat << endl;
    cout << " Цена: " << price << endl;
}
int ticket::checkamount()
{
    ifstream readfile("tickets.txt");
    int N = 0;
    ticket t;
    string line;
    string empty;
    if (readfile.is_open())
    {
        while (true)
        {
            if (readfile >> t.train >> ws && getline(readfile, t.station1) &&
                getline(readfile, t.station2) && getline(readfile, t.dep_day) &&
                getline(readfile, t.dep_time) && readfile >> t.coach >> t.seat >> t.price)
            {
                N++;
            }
            else
            {
                break;
            }
        }
        readfile.close();
    }
    else {
        cout << "Ошибка открытия файла" << endl;
    }
    cout << " N = ";
    cout << N << endl;
    return N;
}
