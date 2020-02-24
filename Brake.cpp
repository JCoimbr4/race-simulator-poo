#include "Brake.h"
#include <iostream>

using namespace std;
//default
Brake::Brake() {
	carSpeed = NULL;
}

//destructor
Brake::~Brake() {
}

void Brake::pressBrake(int value) {
	carSpeed->subSpeed(value);
}

void Brake::setCarSpeed(Speed* speed) {
	carSpeed = speed;
}