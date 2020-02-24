#pragma once
#include <string>
#include "Accelerator.h"
#include "Brake.h"
#include "Energy.h"
#include "Speed.h"
#include "Point.h"
using namespace std;

class Car
{
	Point position;
	string brand, model;
	Energy energy;
	Speed* speed;
	bool isMoving;
	Accelerator accelerator;
	Brake brake;
	bool isDamaged;
	char id;
	bool emergencySignalOn;
	static int idAscii;
	const int idAux;
	int currentPositionOnSquare, currentTile;
public:
	Car();
	Car(int ms, double ic, double mc, string b, string m);
	~Car();
	Car& operator=(Car c);
	
	// ----------------- GETS -----------------------
	Energy getEnergy() const;
	string getBrand () const;
	string getModel () const;
	char getId () const;
	bool getIsDamaged()const;
	bool getIsMoving()const;
	Point getPosition()const;
	int getMaxSpeed() const;
	int getCurrentSpeed() const;
	// ----------------------------------------------

	// ----------------- SETS -----------------------
	void setIsDamaged(bool isD);
	void setIsMoving(bool isM);
	void setPosition(const Point& p);
	void show();
	void hide();
	// ----------------------------------------------

	void acceleratorPressed(int value);
	void brakePressed(int value);
	bool checkForEnergyEmpty();
	void subEnergy();
	void addEnergy();

	void move(int raceLength);

	void turnEmergencySignalOn();
	void turnEmergencySignalOff();
	bool getEmergencySignal()const;

	int getNumberOfMs()const;

	int getCurrentRealPosition()const;
	void rechargeBattery();
	void rechargeBatteryValue(double value);
	void setCurrentPositionOnSquare(int value);
	void resetSpeed();
};

