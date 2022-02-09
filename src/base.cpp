
#include "base.h"

using namespace std;

Base::Base() {
    cout << "Konstruktor Base\n";
    monthVec.push_back("");
    monthVec.push_back("Styczen");
    monthVec.push_back("Luty");
    monthVec.push_back("Marzec");
    monthVec.push_back("Kwiecien");
    monthVec.push_back("Maj");
    monthVec.push_back("Czerwiec");
    monthVec.push_back("Lipiec");
    monthVec.push_back("Siepien");
    monthVec.push_back("Wrzesien");
    monthVec.push_back("Pazdziernik");
    monthVec.push_back("Listopad");
    monthVec.push_back("Grudzien");
}

Base::~Base() {
    cout << "Destruktor Base\n";
}