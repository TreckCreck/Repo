#ifndef TRAINS_H
#define TRAINS_H

#include <locale>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

class trains
{
private:
    int train;
    string station1;
    string station2;
    string dep_day;
    string dep_time;
    int num_coaches;
    int seatamount;
public:
    trains();
    void read_trains_from(ifstream& file);
    void write_trains_to(ofstream& file);
    int getTrainNumber();
    int getSeatAmount();
    int getNumCoaches();
    string getStation1();
    string getStation2();
    string getDepDay();
    string getDepTime();
    void showTrains();
    int checkamount();
};


#endif