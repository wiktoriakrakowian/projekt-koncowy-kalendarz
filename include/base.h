
#ifndef CALENDAR_BASE_H
#define CALENDAR_BASE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base {
protected:
    int numberOfDays[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    vector <string> monthVec;
public:
    Base();
    virtual bool isLeap(int year) = 0;
    virtual int dayMax(int month, int year) = 0;
    virtual int weekday_int(int day, int month, int year) = 0;
    virtual void monthToFile(int month, int year) = 0;
    virtual void display() = 0;
    ~Base();
};


#endif //CALENDAR_BASE_H
