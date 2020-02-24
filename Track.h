#pragma once
#include "Race.h"
#include "Point.h"
#include "Car.h"
class Track
{
	Race *race;
	int width, length, xAxis, yAxis, trackNumber;
public:
	Track();
	~Track();
	void setTrackPosition(int w, int l, int x, int y, int tN);
	void setPilotToRace(Pilot* p);
	void show();
	Race* getRace();
	void addRace(Race* r);
};

