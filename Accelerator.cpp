#include "Accelerator.h"
#include <iostream>
using namespace std;
//default
Accelerator::Accelerator(){
	carSpeed = NULL;
}

//destructor
Accelerator::~Accelerator() {
}

void Accelerator::pressAccelerator(int value) {
	carSpeed->addSpeed(value);
}

void Accelerator::setCarSpeed(Speed* speed) {
	carSpeed = speed;
}