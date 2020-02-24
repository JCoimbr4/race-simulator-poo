#pragma once
#include "Pilot.h"
class Fast : public Pilot
{
public:
	Fast();
	Fast(string n);
	void makeMovement(int raceLength);
};

