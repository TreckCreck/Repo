#include "TicketClass.h"
#include <iostream> 123

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
    cout << " Íîìåð ïîåçäà: " << train << endl;
    cout << " Ñòàíöèÿ îòïðàâëåíèÿ: " << station1 << endl;
    cout << " Ñòàíöèÿ ïðèáûòèÿ: " << station2 << endl;
    cout << " Äàòà îòïðàâëåíèÿ: " << dep_day << endl;
    cout << " Âðåìÿ îòïðàâëåíèÿ: " << dep_time << endl;
    cout << " Íîìåð âàãîíà: " << coach << endl;
    cout << " Íîìåð ìåñòà: " << seat << endl;
    cout << " Öåíà: " << price << endl;
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
        cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
    }
    cout << " N = ";
    cout << N << endl;
    return N;
}
