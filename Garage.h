#pragma once
#include <vector>
#include "Car.h"
class Garage
{
	vector <Car*> cars;
public:
	Garage();
	~Garage();
	void addCar(Car *car);
	void printAllCarsOnGarage();
	bool checkIfCarIsOnGarage(char carLetter);
};

