#include "Garage.h"
#include <iostream>
#
/**
 * Construtor
*/
Garage::Garage() {
}

/**
 * destrutor
*/
Garage::~Garage() {
}

/**
 * Adiciona carro ao vector de ponteiros
 *
 * @param car - carro a associar
*/
void Garage::addCar(Car* car) {
	cars.push_back(car);
	cout << "\n-- SUCCESS (" << car->getId() << " was added to garage)";
}

/**
 * Imprime todos os autodromes
*/
void Garage::printAllCarsOnGarage() {
	auto it = cars.begin();
	while (it != cars.end()) {
		cout << (*it)->getId() << " ";
		it++;
	}
}

/**
 * Verifica se o carro esta na garagem
 *
 * @param carLetter - letra do carro a verificar
*/
bool Garage::checkIfCarIsOnGarage(char carLetter) {
	auto it = cars.begin();
	while (it != cars.end()) {
		if (carLetter == (*it)->getId())
			return true;
		it++;
	}
	return false;
}