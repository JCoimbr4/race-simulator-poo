#pragma once
#include "Autodrome.h"
#include "Ranking.h"
#include "Pilot.h"
#include "Race.h"
#include <vector>
#include "Placement.h"
using namespace std;
class Championship
{
	vector <Ranking> rankings;
	vector <Placement> placements;
	vector <Autodrome*> autodromes;
	vector <Race> races;
	int currentAutodrome;
	int raceTimer;
	int currentRaceLength;
public:
	Championship();
	~Championship();
	void removeAllAutodromes();
	bool checkForWinner();
	int getNumberOfAutodromes()const;
	void addAutodrome(Autodrome* autodrome);
	void printAllAutodromesOnChampionship();
	bool setupTracks(int raceNumber);
	void addPilotToRace(Pilot* p, int raceNumber);
	void makeMovement();
	void showNamePilotsOnRace();

	void clearPlacementsAndRaces();
	void resetRaceTimer();
	void addSecondToTimer();
	void removeSecondToTimer();
	int getRaceTimer()const;
	void giveTimeToPilots();
	void updateRankings();
	void updatePlacements();

	void printPlacements();

	bool orderToStop(string pilotName);

	void printRankings();
	int getNumberOfCars();
	void resetForNewRace();
};

