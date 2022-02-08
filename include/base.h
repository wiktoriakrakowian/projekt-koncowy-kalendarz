#ifndef CALENDAR_BASE_H
#define CALENDAR_BASE_H

#include <iostream>
#include <string>
using namespace std;

class Base {
protected:
    int numberOfDays[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    string Month[13] = {"", "Styczen", "Luty", "Marzec", "Kwiecien", "Maj", "Czerwiec", "Lipiec", "Sierpien", "Wrzesien", "Pazdziernik", "Listopad", "Grudzien"};
    int month;
    int year;
public:
    Base();
    virtual bool isLeap(int year) = 0;
    virtual int dayMax(int month, int year) = 0;
    virtual int weekday_int(int day, int month, int year) = 0;
    virtual void displayMonth(int month, int year) = 0;
    ~Base();
};


#endif //CALENDAR_BASE_H
