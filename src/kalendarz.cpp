
#include "../include/kalendarz.h"

using namespace std;

Calendar::Calendar() {
    cout << "Konstruktor Calendar\n";
}

bool Calendar::isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool Calendar::isLeap(long year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int Calendar::dayMax(int month, int year) {
    return numberOfDays[isLeap(year)][month];
}

int Calendar::weekday_int(int day, int month, int year) {
    if (month > 2) {
        month -= 2;
    } else {
        month += 10;
        year--;
    }
    int century = year / 100;
    year %= 100;
    return (day + (13 * month - 1) / 5 + year + year / 4 + century / 4 + 5 * century) % 7;
}

void Calendar::monthToFile(int month, int year) {
    file.open("dane.txt", ios::app);
    if (file.good()) {
        file << setw((17 - monthVec[month].length()) / 2) << "" << monthVec[month] << setw(5)
             << year << "\n --------------------\n Nd Pn Wt Sr Cz Pt Sb\n";
        int weekday = weekday_int(1, month, year), max = dayMax(month, year);
        if (weekday > 0) {
            file << setw(3 * weekday) << "";
        }
        for (int day = 1; day <= max; day++) {
            file << setw(3) << day;
            if ((day + weekday) % 7 == 0) {
                file << endl;
            }
        }
        file << "\n\n";
        file.close();
    } else {
        cout << "Error: plik\n";
    }
}

void Calendar::display() {
    file.open("dane.txt", ios::in);
    int ch;
    while ((ch = file.get()) != EOF) {
        cout.put(char(ch));
    }
    file.close();
}

Calendar::~Calendar() {
    cout << "Destruktor Calendar\n";
}