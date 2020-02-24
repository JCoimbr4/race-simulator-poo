#include "Speed.h"
#include <iostream>

Speed::Speed() {
	currentSpeed = 0;
	maxSpeed = 0;
}

Speed::~Speed() {

}

void Speed::setCurrentSpeed(int value) {
	currentSpeed = value;
}
void Speed::setMaxSpeed(int value) {
	maxSpeed = value;
}
void Speed::addSpeed(int value) {
	if (currentSpeed < maxSpeed) //CHANGED
		currentSpeed = currentSpeed + value;
}
void Speed::subSpeed(int value) {
	if(currentSpeed > 0) //CHANGED
		currentSpeed = currentSpeed - value;
}

int Speed::getCurrentSpeed()const {
	return currentSpeed;
}
int Speed::getMaxSpeed()const {
	return maxSpeed;
}