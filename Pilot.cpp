#include "Pilot.h"
#include <string>
#include <iostream>
using namespace std;

/**
 * Construtores
*/
Pilot::Pilot(){
	car = NULL;
    currentRaceTime = 0;
    currentPlacement = 0;
}
Pilot::Pilot(string n): name(n) {
	car = NULL;
    currentRaceTime = 0;
    currentPlacement = 0;
    isLast = false;
    orderToStop = false;
}

/**
 * Operator =
*/
Pilot& Pilot::operator=(const Pilot& p) {
	if (this == &p)
		return *this;
	return *this;
}

/**
 * Destrutor
*/
Pilot::~Pilot() {
}

/**
 * Devolve nome do piloto
 *
 * @return name - nome do piloto
*/
string Pilot::getName() const {
	return name;
}

/**
 * Devolve o tipo do piloto
 *
 * @return type - tipo do piloto
*/
string Pilot::getType() const {
	return type;
}

/**
 * Associar piloto a carro
 *
 * @return type - tipo do piloto
*/
void Pilot::setCar(Car* c){
	car = new Car();
	car = c;
}

/**
 * Vai buscar letra do carro em que o piloto esta
 *
 * @return letter - letra do carro
*/
char Pilot::getPilotCarLetter()const {
	if (car == NULL)
		return '*';
	return car->getId();
}

/**
 * Mete carro do piloto numa posicao
 *
 * @param p - ponto correspondente
*/
void Pilot::setCarPosition(const Point& p) {
	car->setPosition(p);
}

/**
 * Manda carro mostrar
*/
void Pilot::showCar() {
	car->show();
}

/**
 * Manda carro esconder
*/
void Pilot::hideCar() {
	car->hide();
}

/**
 * Prime acelarador do carro
*/
void Pilot::pressAccelerator(int value) {
    if (car != NULL) {
        car->acceleratorPressed(value);
    }
}

/**
 * Prime travao do carro
*/
void Pilot::pressBrake(int value) {
    if (car != NULL) {
        car->brakePressed(value);
    }
}

/**
 * Vai buscar a posicao do carro
 *
 * @return posicao do carro
*/
Point Pilot::getCarPosition() const{
	return car->getPosition();
}

/**
 * Vai buscar o carro do piloto
 *
 * @return carro
*/
Car* Pilot::getCar()const {
	return car;
}

/**
 * Busca id do carro
 *
 * @return id se tiver
 * @return null se nao tiver
*/
int Pilot::getIDofCarDrivenbyPilot()
{
	if (car == NULL)
		return NULL;
	return car->getId();
}

void Pilot::setCurrentRaceTime(int time) {
    currentRaceTime = time;
}

void Pilot::makeMovement(int raceLength) {
    if (orderToStop)
        pressBrake(1);
    else {
        pressAccelerator(1);
    }
}

void Pilot::turnEmergencySignalOn() {
    car->turnEmergencySignalOn();
}

void Pilot::setPlacement(int value) {
    currentPlacement = value;
}

bool Pilot::checkForEmptyEnergy() {
    return car->checkForEnergyEmpty();
}

void Pilot::setIsLast(bool value) {
    isLast = value;
}

void Pilot::setOrderToStop(bool value) {
    orderToStop = value;
}

bool Pilot::getOrderToStop()const {
    return orderToStop;
}