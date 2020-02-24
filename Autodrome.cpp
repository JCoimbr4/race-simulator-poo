#include "Autodrome.h" 
#include "Race.h"
#include <iostream>
#include "Console.h"
/**
 * Construtores
*/

Autodrome::Autodrome(int mc, int l, string n) : maxCars(mc), length(l), name(n) {
	for (int i = 0; i < maxCars; i++) {
		Track aux;
		tracks.push_back(aux);
	}
}

/**
 * Destrutor
*/
Autodrome::~Autodrome() {
}

/**
 * Devolve nome do autodrome
 *
 * @return name - nome do autodrome
*/
string Autodrome::getName()const {
	return name;
}

/**
 * Devolve numero maximo de carros do autodrome
 *
 * @return maxCars - numero maximo de carros permitidos
*/
int Autodrome::getMaxCars()const {
	return maxCars;
}

/**
 * Devolve comprimento do autodrome
 *
 * @return length - comprimento do autodrome
*/
int Autodrome::getLength()const {
	return length;
}

/**
 * Adicionar carro a garagem
 *
 * @param - ponteiro para carro pretendido
*/
void Autodrome::addCarToGarage(Car* car) {
	garage.addCar(car);
}

/**
 * Manda imprimir carros na garagem
*/
void Autodrome::printCarsOnGarage() {
	garage.printAllCarsOnGarage();
}


/**
 * Verifica se o carro esta na garagem
 *
 * @param carLetter - letra do carro a verificar
 * @return true - Carro esta numa garagem
 * @return false - carro nao esta em nenhuma garagem
*/
bool Autodrome::checkIfCarIsOnGarage(char carLetter) {
	return garage.checkIfCarIsOnGarage(carLetter);
}

/**
 * Faz as dimensoes das pistas
 * Width e length base de 80
*/
void Autodrome::setTrackPosition() {
	int trackNumber = 0, trackWidth, counter = 1;

	auto it = tracks.begin();
	while (it != tracks.end()) {
		trackWidth = 80 / tracks.size(); //divide largura max pelo numero de carros
		it->setTrackPosition(trackWidth, 20, counter, 1, trackNumber);
		counter = counter + trackWidth; //proxima posicao afrente
		trackNumber++;
		it++;
	}
}

/**
 * Manda desenhar rectangulos das pistas
*/
void Autodrome::showTracks() {
	auto it = tracks.begin();
	while (it != tracks.end()) {
		it->show();
		it++;
	}
}

/**
 * Vai buscar uma race que percenta a x pista
 *
 * @param trackNumber - numero da pista
*/
Race* Autodrome::getRace(int trackNumber) {
	int counter=0;
	auto it = tracks.begin();
	while (it != tracks.end()) {
		if (counter == trackNumber)
			return it->getRace();
		it++;
	}
	return NULL;
}

/**
 * Verifica se o carro esta na garagem
 *
 * @param trackNumber - pista para adicionar race
 * @param r - ponteiro para a race
*/
void Autodrome::addRace(int trackNumber, Race* r) {
	int counter = 0;
	auto it = tracks.begin();
	while (it != tracks.end()) {
		if (counter == trackNumber) {
			r->setRaceLength(length);
			it->addRace(r);
			return; //CHANGED

		}
		it++;
		counter++; //CHANGED
	}
}

/**
 * Operator=
*/
Autodrome& Autodrome::operator=(const Autodrome& c)
{
	if (this == &c)
		return *this;

	return *this;// TODO: inserir instrução de retorno aqui// TODO: inserir instrução de retorno aqui
}