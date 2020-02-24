#pragma once
#include <vector>
#include "Car.h"
#include "Pilot.h"
#include "Championship.h"
using namespace std;
class DGV
{
	vector <Pilot*> pilots;
	vector <Car*> cars;
	Championship* championship;
	string name;
public:
	DGV();
	~DGV();
	DGV(const DGV& other) { *this = other;}
	void printAll();

	// ----------------- CARS -----------------------
	void addCar(int carMaxSpeed, double carInicialCapacity, double carMaxCapacity, string carBrand, string carModel);
	bool checkIfCarExistsByLetter(char carLetter);
	bool removeCar(string c);
	void printCars();
	Car* getCar(char carLetter);
	int getTotalCars();
	void setPilotCarInitialPosition(int trackWidth, int raceNumber);
	// ----------------------------------------------
	
	// ----------------- PILOTS ---------------------
	bool checkIfPilotAsCar(char carLetter);
	void addPilot(string type, string name);
	int getTotalPilots();
	bool removePilot(string p);
	bool checkForPilotNameRepeat(string name);
	int checkNumberOfPilotAsCar();
	bool pilotEnterCar(char carLetter, string pilotName);
	bool pilotLeaveCar(char carLetter);
	bool checkIfAnyPilotAsCar();
	// ----------------------------------------------
	void giveDamageToCar(string c);

	void setChampionship(Championship* c);
	void rechargeAllBatteries();
	void rechargeCarBattery(char carLetter, double value);

	void setDGVName(string nameDGV);
	string getDGVName()const;
};

