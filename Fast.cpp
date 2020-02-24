#include "Fast.h"
#include <iostream>
using namespace std;
Fast::Fast() {
    this->type = "fast";
}

Fast::Fast(string n) {
    this->type = "rapido";
    this->name = n;
    cout << "\n -- SUCCESS (Fast Pilot Created)";
}

void Fast::makeMovement(int raceLength) {
    Energy energyCar;
    energyCar = car->getEnergy();
    if (orderToStop) {
        pressBrake(1);
        return;
    }
    int percentage = rand() % (100 - 0 + 1) + 0;
    
    if (percentage < 10) {
        car->turnEmergencySignalOn();
    }
    if (!checkForEmptyEnergy()) {
        if ((energyCar.maxEnergy / 2) < energyCar.currentEnergy) {
            pressAccelerator(1);
        }
        else if (currentRaceTime % 3 == 0) {
            pressAccelerator(1);
        }
    }
    else {
        pressBrake(1);
    }
    //CHANGED
    //if (car->getCurrentSpeed() < 0)
    //turnEmergencySignalOn();
    car->move(raceLength);
}