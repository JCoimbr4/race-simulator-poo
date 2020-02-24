#pragma once
#include "Race.h"
#include "Garage.h"
#include "Track.h"
#include <string>
using namespace std;
class Autodrome
{
	const int maxCars, length;
	string name;
	Garage garage;
	vector <Track> tracks;
public:
	Autodrome(int mc, int l, string n);
	~Autodrome();

	Autodrome& operator=(const Autodrome& c);

	// ----------------- GETS -----------------------
	string getName()const;
	int getMaxCars()const;
	int getLength()const;
	// ----------------------------------------------
	void addCarToGarage(Car* car);
	void printCarsOnGarage();
	bool checkIfCarIsOnGarage(char carLetter);
	void setTrackPosition();
	void showTracks();
	Race* getRace(int trackNumber);
	void addRace(int trackNumber, Race* r);
};

