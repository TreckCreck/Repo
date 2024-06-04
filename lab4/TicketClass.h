#ifndef TICKET_H
#define TICKET_H

#include <locale>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
class ticket
{
private:
    int train;
    string station1;
    string station2;
    string dep_day;
    string dep_time;
    int coach;
    int seat;
    int price;
public:
    ticket();
    int checkamount();
    void read_from(ifstream& file);
    void write_to(ofstream& file);
    void display();
};
#endif