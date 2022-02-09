
#ifndef CALENDAR_KALENDARZ_H
#define CALENDAR_KALENDARZ_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "base.h"

using namespace std;

class Calendar : public Base {
    fstream file;
public:
    Calendar();

    bool isLeap(int year);

    bool isLeap(long year);

    int dayMax(int month, int year);

    int weekday_int(int day, int month, int year);

    void monthToFile(int month, int year);

    void display();

    ~Calendar();
};

#endif //UNTITLED1_KALENDARZ_H
