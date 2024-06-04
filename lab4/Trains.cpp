#include "Trains.h"
#include <iostream>

trains::trains(int trn, string st1, string st2, string dd, string dt, int ncch, int stam)
{
    train = trn;
    station1 = st1;
    station2 = st2;
    dep_day = dd;
    dep_time = dt;
    num_coaches = ncch;
    seatamount = stam;
}
void trains::read_trains_from(ifstream& readfile)
{
    readfile >> train;
    getline(readfile, station1);
    getline(readfile, station2);
    getline(readfile, dep_day);
    getline(readfile, dep_time);
    readfile >> num_coaches;
    readfile >> seatamount;
    readfile.get();
}
void trains::write_trains_to(ofstream& readfile)
{
    readfile << train << endl;
    readfile << station1 << endl;
    readfile << station2 << endl;
    readfile << dep_day << endl;
    readfile << dep_time << endl;
    readfile << num_coaches << endl;
    readfile << seatamount << endl;
}
void trains::showTrains()
{
    cout << "\n %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << " Номер поезда: " << train << endl;
    cout << " Станция отправления: " << station1 << endl;
    cout << " Станция прибытия: " << station2 << endl;
    cout << " Дата отправления: " << dep_day << endl;
    cout << " Время отправления: " << dep_time << endl;
    cout << " Количество вагонов: " << num_coaches << endl;
    cout << " Количество мест в вагоне: " << seatamount << endl;
}
int trains::checkamount()
{
    ifstream readfile("trains.txt");
    int N = 0;
    trains t;
    string line;
    string empty;
    if (readfile.is_open())
    {
        while (true)
        {
            if (readfile >> t.train >> ws && getline(readfile, t.station1) &&
                getline(readfile, t.station2) && getline(readfile, t.dep_day) &&
                getline(readfile, t.dep_time) && readfile >> t.num_coaches >> t.seatamount)
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
int trains::getTrainNumber()
{
    return train;
}
int trains::getSeatAmount()
{
    return seatamount;
}
int trains::getNumCoaches()
{
    return num_coaches;
}
string trains::getStation1()
{
    return station1;
}
string trains::getStation2()
{
    return station2;
}
string trains::getDepDay()
{
    return dep_day;
}
string trains::getDepTime()
{
    return dep_time;
}