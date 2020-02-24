#include "Surprise.h"
#include <iostream>
using namespace std;
Surprise::Surprise() {
    this->type = "surpresa";
}

Surprise::Surprise(string n) {
    this->type = "surpresa";
    this->name = n;
    cout << "\n -- SUCCESS (Surprise Pilot Created)";
}

void Surprise::makeMovement(int raceLength) {
    if (orderToStop) {
        pressBrake(1);
        return;
    }
    int percentage = rand() % (100 - 0 + 1) + 0;
    if (percentage < 50) {
        pressAccelerator(1);
    }
    else {
        pressBrake(1);
    }
    int nitro = rand() % (100 - 0 + 1) + 0;

    if (nitro < 30) {
        pressAccelerator(1);
    }
    //CHANGED
    //if (car->getCurrentSpeed() == 0)
     //   turnEmergencySignalOn();
    car->move(raceLength);
}