
#ifndef CALENDAR_KALENDARZ_H
#define CALENDAR_KALENDARZ_H

#include <iostream>
#include <iomanip>
#include "base.h"

using namespace std;

class Calendar : public Base {
public:
    Calendar();
    bool isLeap(int year);
    int dayMax(int month, int year);
    int weekday_int(int day, int month, int year);
    void displayMonth(int month, int year);
    ~Calendar();
};

#endif //UNTITLED1_KALENDARZ_H
