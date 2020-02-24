#include "Car.h"
#include "Console.h"
#include <iostream>
using namespace std;
int Car::idAscii = 97; //97 = a em ascii

/**
 * Construtores
*/
Car::Car() : idAux(0) {

}

Car::Car(int ms, double ic, double mc, string b, string m) : idAux(idAscii++), brand(b), model(m) {
	if (idAux > 122)
		id = 63; // 63 = ? em ascci
	id = idAux;
	energy.currentEnergy = ic;
	energy.maxEnergy = mc;
	energy.inicialEnergy = ic;
	isDamaged = false;
	isMoving = false;
	position.x = 0;
	position.y = 0;
    emergencySignalOn = false;
    speed = new Speed();
    speed->setMaxSpeed(ms);
    accelerator.setCarSpeed(speed);
    brake.setCarSpeed(speed);
    currentPositionOnSquare = 0;
    currentTile = 0;
}

/**
 * Destrutor
*/
Car::~Car() {
}

/**
 * Devolve a marca do carro
 *
 * @return brand - marca do carro
*/
string Car::getBrand() const{
	return brand;
}

/**
 * Devolve o modelo do carro
 *
 * @return model - modelo do carro
*/
string Car::getModel() const {
	return model;
}

/**
 * Devolve energia
 *
 * @return energy - energia do carro
*/
Energy Car::getEnergy() const {
	return energy;
}
/**
 * Devolve o id(letra) do carro
 *
 * @return id - id(letra) do carro
*/
char Car::getId() const {
	return id;
}

/**
 * Tem dano
 *
 * @param ap - true esta piloto no carro false nao esta
*/
void Car::setIsDamaged(bool isD) {
	isDamaged = isD;
}

/**
 * Esta em movimento
 *
 * @param ap - true esta piloto no carro false nao esta
*/
void Car::setIsMoving(bool isM) {
	isMoving = isM;
}

/**
 * Devolve se o carro tem dano
 *
 * @return true - tem
 * @return false - nao tem
*/
bool Car::getIsDamaged()const {
	return isDamaged;
}

/**
 * Devolve se o carro esta em movimento
 *
 * @return true - esta
 * @return false - nao esta
*/
bool Car::getIsMoving()const {
	return isMoving;
}

/**
 * Atribui posicao ao carro
 *
 * @param p - position
*/
void Car::setPosition(const Point& p) {
	position = p;
}

/**
 * Mostra carro em posicao
*/
void Car::show() {
	Consola::gotoxy(position.x, position.y);
	cout << id << position.y;
}

/**
 * Esconde carro em posicao
*/
void Car::hide() {
	Consola::gotoxy(position.x, position.y);
	cout << ' ';
}

/**
 * Devolve posicao do carro
 *
 * @return position - posicao do carro
*/
Point Car::getPosition()const {
	return position;
}

/**
 * Devolve velocidade
 *
 * @return speed do carro
*/
int Car::getMaxSpeed() const {
    return speed->getMaxSpeed();
}

int Car::getCurrentSpeed() const {
    return speed->getCurrentSpeed();
}

/**
 * Operator=
*/
Car& Car::operator=(Car c)
{
    c.idAscii = this->idAscii;
    c.id = this->id;
    swap(this->position, c.position);
    swap(this->brand, c.brand);
    swap(this->model, c.model);
    swap(this->energy, c.energy);
    swap(this->speed, c.speed);
    swap(this->isMoving, c.isMoving);
    swap(this->accelerator, c.accelerator);
    swap(this->brake, c.brake);
    swap(this->isDamaged, c.isDamaged);

    return *this;
}

void Car::acceleratorPressed(int value) {
    accelerator.pressAccelerator(value);
}

void Car::brakePressed(int value) {
    brake.pressBrake(value);
}

void Car::move(int raceLength) {
    
    Consola::gotoxy(position.x, position.y);
    cout << ' ';
    int valuePerPixel = raceLength / 20;
    currentPositionOnSquare = currentPositionOnSquare + speed->getCurrentSpeed();
    for (int i = 0; i < speed->getCurrentSpeed(); i++)
        subEnergy();
    int newPosition = currentPositionOnSquare * valuePerPixel;
    position.y = 19 - newPosition;
    
    if (position.y < 1)
        position.y = 1;
    Consola::gotoxy(position.x, position.y);
    cout << id;
}

void Car::subEnergy() {
    if(energy.currentEnergy != 0)
        energy.currentEnergy = energy.currentEnergy - 0.1;
}

void Car::addEnergy() {
    if (energy.currentEnergy != 0)
        energy.currentEnergy = energy.currentEnergy + 0.1;
}

bool Car::checkForEnergyEmpty() {
    if (energy.currentEnergy <= 0)
        return true;
    return false;
}

void Car::turnEmergencySignalOn() {
    emergencySignalOn = true;
}

bool Car::getEmergencySignal()const {
    return emergencySignalOn;
}

void Car::turnEmergencySignalOff() {
    emergencySignalOn = false;
}

int Car::getNumberOfMs()const {
    return currentPositionOnSquare;
}

int Car::getCurrentRealPosition()const {
    return currentPositionOnSquare;
}

void Car::rechargeBattery() {
    energy.currentEnergy = energy.maxEnergy;
}

void Car::rechargeBatteryValue(double value) {
    energy.currentEnergy = energy.currentEnergy + value;
    if (energy.currentEnergy > energy.maxEnergy)
        energy.currentEnergy = energy.maxEnergy;
}

void Car::setCurrentPositionOnSquare(int value) {
    currentPositionOnSquare = value;
}

void Car::resetSpeed() {
    speed->setCurrentSpeed(0);
}