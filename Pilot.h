#pragma once
#include <string>
#include "Car.h"
using namespace std;
class Pilot
{
protected:
	Car* car;
	string name;
	string type;
	int currentRaceTime;
	int currentPlacement;
	bool isLast;
	bool orderToStop;
public:
	Pilot();
	Pilot(string n);
	Pilot& operator=(const Pilot& p);
	virtual ~Pilot();
	void setCar(Car *c);
	void setCarPosition(const Point& p); //isto pode se apagar pois o piloto interage apenas com acelarador e travao
	void setCurrentRaceTime(int time);
	char getPilotCarLetter()const;
	string getType() const;
	string getName() const;
	void showCar();
	void hideCar();
	Point getCarPosition()const;
	Car* getCar()const;
	int getIDofCarDrivenbyPilot();
	void turnEmergencySignalOn();
	bool checkForEmptyEnergy();
	virtual void makeMovement(int raceLength);
	virtual void pressAccelerator(int value);
	virtual void pressBrake(int value);
	void setPlacement(int value);
	void setIsLast(bool value);

	void setOrderToStop(bool value);

	bool getOrderToStop()const;
};

