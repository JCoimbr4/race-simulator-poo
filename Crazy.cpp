#include "Crazy.h"
#include <iostream>
using namespace std;
Crazy::Crazy() {
    this->type = "crazy";
}

Crazy::Crazy(string n) {
    this->type = "crazy";
    this->name = n;
    randomStart = 0;
    randomStartPicked = false;
    cout << "\n -- SUCCESS (Crazy Pilot Created)";
}

void Crazy::makeMovement(int raceLength) {
    if (orderToStop) {
        pressBrake(1);
        return;
    }
    if (!randomStartPicked) {
        int randomNumber = rand() % (5 - 1 + 1) + 1;
        randomStart = randomNumber;
        randomStartPicked = true;
    }else if (!checkForEmptyEnergy()) {
        if (isLast) {
            pressBrake(1);
        }
        else if(currentPlacement != 1) {
            pressAccelerator(2);
        }
        int percentage = rand() % (100 - 0 + 1) + 0;
        if (percentage <= 5) {
            car->setIsDamaged(true);
            turnEmergencySignalOn(); 
        }
    }
    else {
        turnEmergencySignalOn();
    }
    //CHANGED
    //if (car->getCurrentSpeed() < 0)
    //    turnEmergencySignalOn();
    car->move(raceLength);
}