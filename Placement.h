#pragma once
#include "Pilot.h"
#include "Car.h"
struct Placement
{
	Car* car;
	Pilot* pilot;
	bool operator>(const Placement& val) const {
		return car->getCurrentRealPosition() > val.car->getCurrentRealPosition();
	}
};