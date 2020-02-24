#include "Championship.h"
#include "Console.h"
#include <iostream>
#include <algorithm>
using namespace std;

//construtor
Championship::Championship() {
	raceTimer = 0;
	currentAutodrome = 0;
	currentRaceLength = 0;
}

//destrutor
Championship::~Championship() {
}

/**
 * Adiciona autodrome ao vector de ponteiros
 *
 * @param autodrome - autodrome a associar
*/
void Championship::addAutodrome(Autodrome* autodrome) {
	autodromes.push_back(autodrome);
	cout << "\n-- SUCCESS (" << autodrome->getName() << " was added to championship)";
}

/**
 * Imprime todos os autodromes
*/
void Championship::printAllAutodromesOnChampionship() {
	int raceNumber = 1;
	auto it = autodromes.begin();
	while (it != autodromes.end()) {
		cout << "\nRace: " << raceNumber;
		cout << "\nAutodrome: " << (*it)->getName();
		cout << "\n";
		it++;
		raceNumber++;
	}
}

/**
 * Começa Corrida
 *
 * @param raceNumber - numero da corrida
*/
bool Championship::setupTracks(int raceNumber) {
	Consola::clrscr();
	int counterRace = 0, trackCounter= 0, value = 0;
	auto it = autodromes.begin();
	while (it != autodromes.end()) {
		if (counterRace == raceNumber) { // ordem do autodrome na corrida
			currentAutodrome = raceNumber;
			(*it)->setTrackPosition();
			(*it)->showTracks();
			currentRaceLength = (*it)->getLength();
			for (int i = 0; i < (*it)->getMaxCars(); i++) {
				Race aux;
				races.push_back(aux);
				(*it)->addRace(raceNumber, &races.at(i));
			}
			return true;
		}
		counterRace++;
		it++;
	}
	return false;;
}

/**
 * Quanto autodromes existem no campeonato
 *
 * @return numero de autodromes
*/
int Championship::getNumberOfAutodromes()const {
	return autodromes.size();
}

/**
 * Delete vector de ponteiros para os autodromes
*/
void Championship::removeAllAutodromes() {
	for (auto p : autodromes)
	{
		delete p;
	}
	autodromes.clear();
	races.clear();
	currentAutodrome = 0;
	raceTimer = 0;
	currentRaceLength =0;
}

/**
 * Adiciona um piloto a uma race
 *
 * @param p - piloto para adicionar á pista
 * @param raceNumber - corrida a qual irá pertencer
*/
void Championship::addPilotToRace(Pilot* p, int raceNumber) {
	int counter = 0;
	auto it = races.begin();
	while (it != races.end()) {
		if (counter == raceNumber) {
			it->setPilot(p);
			Placement aux;
			aux.car = p->getCar();
			aux.pilot = p;
			placements.push_back(aux);
		}
		it++;
		counter++;
	}
}

/**
 * Todos os pilotos nas corridas fazem o seu movimento
*/
void Championship::makeMovement() {
	auto it = races.begin();
	while (it != races.end()) {
		if (it->getPilot() != NULL && it->getPilot()->getCar() != NULL) {
			if (it->getPilot()->getCar()->getEmergencySignal() || it->getPilot()->getCar()->getIsDamaged()) {
				auto it2 = autodromes.begin();
				int counter = 0;
				while (it2 != autodromes.end()) {
					if(counter == currentAutodrome){
						(*it2)->addCarToGarage(it->getPilot()->getCar());
						it->setPilot(NULL);
						return;
					}
					it2++;
				}
			}
			else {
				it->giveRaceTimeToPilot(raceTimer);
				it->makeMovement();
			}
		}
		updatePlacements();
		it++;
	}	
}

/**
 * Verifica se alguem já chegou á meta final
 *
 * @return true - alguem acabou a corrida
 * @return false - ainda nao acabou
*/
bool Championship::checkForWinner() {
	bool found1 = false, found2 = false, found3 = false; //CHANGED
	auto it = races.begin();
	while (it != races.end()) {
		if (it->getPilot() != NULL && it->getPilot()->getCar() != NULL) {
			if (it->getPilot()->getCar()->getCurrentRealPosition() >= currentRaceLength || getNumberOfCars() <= 1) {
				Consola::gotoxy(85, 6);
				cout << "The winner was " << it->getPilot()->getName() << " with the car " << it->getPilot()->getCar()->getId();

				int counterPlacement = 0;
				auto it2 = placements.begin();
				while (it2 != placements.end()) {
					if (counterPlacement == 0) {
						auto it3 = rankings.begin();
						while (it3 != rankings.end()) {
							if (it3->pilot->getName().compare(it2->pilot->getName()) == 0) {
								it3->points = it3->points + 10;
								sort(rankings.begin(), rankings.end(), [](Ranking& one, Ranking& two) {return one.points > two.points; });
								found1 = true;//CHANGED
								break;
							}
							it3++;
						}
						if (!found1) {//CHANGED
							Ranking aux;
							aux.pilot = it2->pilot;
							aux.points = 10;
							rankings.push_back(aux);
							sort(rankings.begin(), rankings.end(), [](Ranking& one, Ranking& two) {return one.points > two.points; });
						}
					}
					if (counterPlacement == 1) {
						auto it4 = rankings.begin();
						while (it4 != rankings.end()) {
							if (it4->pilot->getName().compare(it2->pilot->getName()) == 0) {
								it4->points = it4->points + 5;
								sort(rankings.begin(), rankings.end(), [](Ranking& one, Ranking& two) {return one.points > two.points; });
								found2 = true;//CHANGED
								break;
							}
							it4++;
						}
						if (!found2) {//CHANGED
							Ranking aux;
							aux.pilot = it2->pilot;
							aux.points = 5;
							rankings.push_back(aux);
							sort(rankings.begin(), rankings.end(), [](Ranking& one, Ranking& two) {return one.points > two.points; });
						}
					}
					if (counterPlacement == 2) {
						auto it5 = rankings.begin();
						while (it5 != rankings.end()) {
							if (it5->pilot->getName().compare(it2->pilot->getName()) == 0) {
								it5->points = it5->points + 2;
								sort(rankings.begin(), rankings.end(), [](Ranking& one, Ranking& two) {return one.points > two.points; });
								found3 = true;//CHANGED
								break;
							}
							it5++;
						}
						if (!found3) {//CHANGED
							Ranking aux;
							aux.pilot = it2->pilot;
							aux.points = 2;
							rankings.push_back(aux);
							sort(rankings.begin(), rankings.end(), [](Ranking& one, Ranking& two) {return one.points > two.points; });
						}
					}
					counterPlacement++;
					it2++;
				}
				sort(rankings.begin(), rankings.end(), [](Ranking& one, Ranking& two) {return one.points > two.points; });
				return true;
			}
		}
		it++;
	}
	return false;
}

/**
 * Mostra os nomes dos pilotos nas corridas
*/
void Championship::showNamePilotsOnRace() {
	int counter = 0;
	auto it = races.begin();
	while (it != races.end()) {
		if (it->getPilot() != NULL) {
			cout << "\nPista: " << counter << " Piloto: " << it->getPilot()->getName();
		}
		it++;
		counter++;
	}
}

void Championship::resetRaceTimer() {
	raceTimer = 0;
}

void Championship::giveTimeToPilots() {
	auto it = races.begin();
	while (it != races.end()) {
		it->giveRaceTimeToPilot(raceTimer);
		it++;
	}
}

void Championship::addSecondToTimer() {
	raceTimer++;
}
void Championship::removeSecondToTimer() {
	raceTimer--;
}

int Championship::getRaceTimer()const {
	return raceTimer;
}

void Championship::updateRankings() {

}

void Championship::updatePlacements() {
	int placementCounter = 1;
	sort(placements.begin(), placements.end(), [](Placement& one, Placement& two) {return one.car->getCurrentRealPosition() > two.car->getCurrentRealPosition(); });
	auto it = placements.begin();
	while (it != placements.end()) {
		it->pilot->setPlacement(placementCounter);
		it->pilot->setIsLast(false);
		placementCounter++;
		it++;
	}
	(&placements.back())->pilot->setIsLast(true);
}

void Championship::clearPlacementsAndRaces() {
	placements.clear();
	races.clear();

}

void Championship::printPlacements() {
	int placementCounter = 1, counter = 0;
	auto it2 = autodromes.begin();
	while (it2 != autodromes.end()) {
		if (counter == currentAutodrome) {
			cout << "\nInformacao sobre a corrida no autodromo " << (*it2)->getName() << " ( " << (*it2)->getLength() << " )";
		}
		counter++;
		it2++;
	}
	auto it = placements.begin();
	while (it != placements.end()) {
		cout << "\n" << placementCounter << ". " << it->car->getId() << " " << it->car->getBrand() << " / " << it->pilot->getName() << "( " << it->pilot->getType() << " ) - " << it->car->getEnergy().currentEnergy << ", " << it->car->getEnergy().maxEnergy << " - " << it->car->getCurrentRealPosition() << " - " << it->car->getCurrentSpeed();
		it++;
		placementCounter++;
	}
}

bool Championship::orderToStop(string pilotName) {
	auto it = placements.begin();
	while (it != placements.end()) {
		if (it->pilot->getName().compare(pilotName) == 0) {
			it->pilot->setOrderToStop(true);
			return true;
		}
		it++;
	}
	return false;
}

void Championship::printRankings() {
	int rankingCounter = 0;
	auto it = rankings.begin();
	while (it != rankings.end()) {
		cout << "\n" << rankingCounter << ". " << it->pilot->getName() << " - " << it->points << " pontos.";
		it++;
		rankingCounter++;
	}
}

void Championship::resetForNewRace() {
	races.clear();
	raceTimer = 0;
	currentRaceLength = 0;
	auto it = placements.begin();
	while (it != placements.end()) {
		it->car->setCurrentPositionOnSquare(0);
		it->car->resetSpeed();
		it++;
	}
	placements.clear();
}

int Championship::getNumberOfCars() {
	int currentRunners = 0;
	auto it = races.begin();
	while (it != races.end()) {
		if (it->getPilot() != NULL && it->getPilot()->getCar() != NULL) {
			currentRunners++;
		}
		it++;
	}
	return currentRunners;
}
