#pragma once
#include "Pilot.h"
class Crazy : public Pilot
{
	bool randomStartPicked;
	int randomStart;
public:
	Crazy();
	Crazy(string n);
	void makeMovement(int raceLength);
};

