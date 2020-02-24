#pragma once
#include "Pilot.h"
class Surprise : public Pilot
{
public:
	Surprise();
	Surprise(string n);
	void makeMovement(int raceLength);
};


