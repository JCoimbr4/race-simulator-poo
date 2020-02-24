#pragma once
#include "Pilot.h"
#include "Car.h"
#include "Autodrome.h"
#include "Championship.h"
#include "DGV.h"
#include <vector>
#include <string>
using namespace std;
class Simulation
{
	DGV dgv;
	Championship championship;
	vector <Autodrome> autodromes;
	vector <DGV> savedDGV;
public:
	Simulation();
	~Simulation();
	void printAll();
	bool setupRace(int raceNumber);
	// ------------------- CARS ---------------------
	void addCar(string carInicialCapacity, string carMaxCapacity, string carBrand, string carModel, string carMaxSpeed);
	bool carEnterGarage(string carLetter, string autodromeName);
	void printCars();
	bool checkIfCarExists(string name);
	bool removeCar(string& carId);
	// ----------------------------------------------

	// ------------------- PILOTS -------------------
	int getTotalPilots();
	bool checkForPilotNameRepeat(string name);
	bool pilotEnterCar(string carLetter, string pilotName);
	bool pilotLeaveCar(string carLetter);
	void addPilot(string type, string name);
	void makeMovement(int numberOfSeconds);
	void removePilot(string& nome);
	// ----------------------------------------------

	// ------------------- AUTODROME ----------------
	void addAutodrome(string autodromeMaxCars, string autodromeLength, string autodromeName);
	bool makeAutodromePartOfChampionship(string autodromeName);
	bool checkforAutodromeNameRepeat(string name);
	bool removeAutodrome(string& name);
	// ----------------------------------------------
	bool makeAcident(string& letra);
	void printPlacements();
	
	void rechargeAllBatteries();
	void rechargeCarBattery(string& letra, double value);

	void orderToStop(string pilotName);
	void printRankings();
	void saveDGV(string name);
	void loadDGV(string name);
	void delDGV(string name);
};

