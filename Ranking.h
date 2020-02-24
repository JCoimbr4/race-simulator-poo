#pragma once
#include "Pilot.h"
#include "Car.h"
#include "Autodrome.h"
struct Ranking
{
	Pilot* pilot;
	int points;
	bool operator>(const Ranking& val) const {
		return points > val.points;
	}
};