//
// Created by krako on 08.02.2022.
//

#include "menu.h"
#include <iostream>

using namespace std;

int Menu::mainMenu() {
    int option;
    cout << "Opcja 1: kalendarz\n";
    cout << "Opcja 2: pozostale\n";
    cout << "Opcja 3: zapisz do pliku\n";
    cout << "Podaj opcje: ";
    try {
        cin >> option;
        return option;
    }
    catch(exception &e) {
        cout << "Error: " << e.what() << "\n";
    }

}