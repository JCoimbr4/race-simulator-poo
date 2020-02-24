#include "Race.h"
#include "Pilot.h"
#include <iostream>
using namespace std;
//construtor
Race::Race(){
	pilot = new Pilot();
    raceLength = 0;
    currentPlacement = 0;
}

//destrutor
Race::~Race() {
}

/**
 * Adiciona piloto a pista
 *
 * @param p - ponteiro para piloto
*/
void Race::setPilot(Pilot* p){
	pilot = p;
}

/**
 * Devolve piloto da race
 *
 * @return pilot - piloto que pertence á race
*/
Pilot* Race::getPilot() {
	return pilot;
}

/**
 * Manda pilotos nas races fazerem os seus movimentos
*/
void Race::makeMovement() {
    if (pilot != NULL) {
        pilot->makeMovement(raceLength);
    }
}

/**
 * Operator=
 */
Race& Race::operator=(const Race& r) {
	if (this == &r)
		return *this;
	return *this;
}

void Race::giveRaceTimeToPilot(int time) {
    pilot->setCurrentRaceTime(time);
}

void Race::setRaceLength(int value) {
    raceLength = value;
}
int Race::getRaceLength()const {
    return raceLength;
}