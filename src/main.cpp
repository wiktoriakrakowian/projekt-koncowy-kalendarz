
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
    int isShut = 0;
    while (!isShut) {
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
                                if (cin.fail()) {
                                    throw "cin";
                                }
                                if (year > 0) {
                                    for (int i = 1; i <= 12; ++i) {
                                        cal->monthToFile(i, year);
                                    }
                                    cal->display();
                                } else
                                    cout << "Rok nie może być ujemny!\n";

                            }
                                break;
                            case 2: {
                                int month, year;
                                cout << "Podaj rok: ";
                                cin >> year;
                                if (cin.fail()) {
                                    throw "cin";
                                }
                                cout << "Podaj miesiac: ";
                                cin >> month;
                                if (cin.fail()) {
                                    throw "cin";
                                }
                                if (year > 0 && (month > 0 && month < 13)) {
                                    cal->monthToFile(month, year);
                                    cal->display();
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
                    catch(char *e) {
                        cerr << "Error: " << e << "\n";
                    }
                }
                break;
                case 2:{
                    Menu vecMenu;
                    try {
                        int day1, day2;
                        cout << "Podaj dzien roku: ";
                        cin >> day1;
                        if (cin.fail()) {
                            throw "cin";
                        }
                        cout << "Podaj wczesniejszy dzien roku: ";
                        cin >> day2;
                        if (cin.fail()) {
                            throw "cin";
                        }
                        if (day1 > 0 && day2 > 0 && day1 < 365 && day2 < 365) {
                            cout << "Roznica wynosi: " << fabs(difference<int>(day1, day2)) << "\n";
                        }
                        else {
                            cout << "Error. Zly dzien.\n";
                        }
                    }
                    catch(exception &e) {
                        cout << "Error: " << e.what() << "\n";
                        exit(EXIT_FAILURE);
                    }
                }
                break;
                case 3:
                    break;
                default:
                    cout << "Error. Zla opcja.\n";
            }
        }
        cout << "Czy chcesz zamknac program? (0 - nie) ";
        cin >> isShut;
        if (cin.fail()) {
            cout << "Dam Ci kopa w pupe!\n";
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}
