#pragma once
#include "Pilot.h"
#include "Car.h"
using namespace std;
class Race
{
	Pilot* pilot;
	int raceLength;
	int currentPlacement;
public:
	Race();
	~Race();
	Pilot* getPilot();
	void setPilot(Pilot* p);
	void makeMovement();
	Race& operator=(const Race& p);
	void giveRaceTimeToPilot(int time);
	void setRaceLength(int value);
	int getRaceLength()const;
};

