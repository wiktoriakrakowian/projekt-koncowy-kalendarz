#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "kalendarz.h"
#include "base.h"
#include "menu.h"

using namespace std;

template <class T>
T difference(T object1, T object2)
{
    return object1 - object2;
}

int main(int argc, char* argv[]) {
    Menu options;
    int option = options.mainMenu();
    switch (option) {
        case 1: {
            if (argc == 2) {
                try {
                    int choice = stoi(argv[1]);
                    Base *cal = new Calendar(); // polimorfizm
                    switch (choice) {
                        case 1: {
                            int year;
                            cout << "Podaj rok: ";
                            cin >> year;
                            if (year > 0) {
                                for (int i = 1; i <= 12; ++i) {
                                    cal->displayMonth(i, year);
                                    cout << "\n\n";
                                }
                            } else
                                cout << "Rok nie może być ujemny!\n";

                        }
                            break;
                        case 2: {
                            int month, year;
                            cout << "Podaj rok: ";
                            cin >> year;
                            cout << "Podaj miesiac: ";
                            cin >> month;
                            if (year > 0 && (month > 0 && month < 13)) {
                                cal->displayMonth(month, year);
                                cout << "\n\n";
                            } else
                                cout << "Rok nie może być ujemny!\n";

                        }
                            break;
                        default:
                            cout << "Zly argument. Podaj 1 lub 2.\n";
                    }
                }
                catch (exception &e) {
                    cerr << "Error: " << e.what() << "\n";
                    exit(EXIT_FAILURE);
                }
            }
            break;
            case 2:{
                Menu vecMenu;
                int day1, day2;
                cout << "Podaj dzien roku: ";
                cin >> day1;
                //vecMenu.daysVec.push_back(day1);
                cout << "Podaj wczesniejszy dzien roku: ";
                cin >> day2;
                //vecMenu.daysVec.push_back(day2);
                if (day1 > 0 && day2 > 0 && day1 < 365 && day2 < 365) {
                    //int tmp = difference<int>(vecMenu.daysVec.pop_back(), vecMenu.daysVec.pop_back());
                    cout << "Roznica wynosi: " << fabs(difference<int>(day1, day2));
                }
                else {
                    cout << "Error. Zly dzien.\n";
                }
            }
                break;
            case 3:
                break;
            default:
                cout << "Error. Zla opcja.\n";
        }


            return 0;
    }
}
