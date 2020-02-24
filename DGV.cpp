#include "DGV.h"
#include "Energy.h"
#include "Crazy.h"
#include "Fast.h"
#include "Surprise.h"
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Construtores
*/
DGV::DGV() {
	championship = NULL;
}

/**
 * Destrutores
*/
DGV::~DGV() {
}

/**
 * Adiciona novo piloto ao vetor
 *
 * @param p - piloto a ser adicionado
*/
void DGV::addPilot(string type, string name) {
	if (type.compare("normal") == 0)
		pilots.push_back(new Pilot(name));
	else if (type.compare("rapido") == 0)
		pilots.push_back(new Fast(name));
	else if (type.compare("crazy") == 0)
		pilots.push_back(new Crazy(name));
	else if (type.compare("surpresa") == 0)
		pilots.push_back(new Surprise(name));
	cout << "\n-- SUCCESS (Pilot added)";
}

/**
 * Percorre o vector dos pilotos e imprime nomes
*/
void DGV::printAll() {
	//imprime pilotos
	auto it = pilots.begin();
	cout << "\n-------------------";
	cout << "\n*Informacao sobre os pilotos:*\n";
	while (it != pilots.end()) {
		cout << "\nNome: " << (*it)->getName();
		cout << "\nTipo: " << (*it)->getType();
		cout << "\nCarro: " << (*it)->getPilotCarLetter();
		cout << "\n";
		it++;
	}

	auto it2 = cars.begin();
	cout << "\n-------------------";
	cout << "\n*Informacao sobre os carros:*\n";
	while (it2 != cars.end()) {
		cout << "\nID: " << (*it2)->getId();
		cout << "\nMarca: " << (*it2)->getBrand();
		cout << "\nModelo: " << (*it2)->getModel();
		Energy aux = (*it2)->getEnergy();
		cout << "\nEnergia Actual: " << aux.currentEnergy;
		cout << "\nEnergia Inicial: " << aux.inicialEnergy;
		cout << "\nEnergia Max: " << aux.maxEnergy;
		cout << "\nVelocidade Max: " << (*it2)->getMaxSpeed();
		cout << "\n";
		it2++;
	}

}

/**
 * Percorre o vector dos pilotos e imprime nomes
*/
void DGV::printCars() {
	auto it = cars.begin();
	cout << "\n-------------------";
	cout << "\n*Informacao sobre os carros:*\n";
	while (it != cars.end()) {
		cout << "\nID: " << (*it)->getId();
		cout << "\nMarca: " << (*it)->getBrand();
		cout << "\nModelo: " << (*it)->getModel();
		Energy energyAux = (*it)->getEnergy();
		cout << "\nEnergia Actual: " << energyAux.currentEnergy;
		cout << "\nEnergia Inicial: " << energyAux.inicialEnergy;
		cout << "\nEnergia Maxima: " << energyAux.maxEnergy;
		if ((*it)->getIsDamaged())
			cout << "\nDanificado";
		if ((*it)->getIsMoving())
			cout << "\nEm movimento";
		it++;
	}

}
/**
 * Procura no vector se o nome do pilot ja existe
 *
 * @return true - nome existe
 * @return false - nome nao existe
*/
bool DGV::checkForPilotNameRepeat(string name) {
	auto it = pilots.begin();
	while (it != pilots.end()) {
		if (name.compare((*it)->getName()) == 0)
			return true;
		it++;
	}
	return false;
}

/**
 * Devolve quantidade de pilotos no vector
 *
 * @return tamanho do vector
*/
int DGV::getTotalPilots() {
	return pilots.size();
}

/**
 * Devolve quantidade de carros no vector
 *
 * @return tamanho do vector
*/
int DGV::getTotalCars() {
	return cars.size();
}

/**
 * Adiciona novo Carro ao vetor
 *
 * @param c - carro a ser adicionado
*/
void DGV::addCar(int carMaxSpeed, double carInicialCapacity, double carMaxCapacity, string carBrand, string carModel) {
	cars.push_back(new Car(carMaxSpeed, carInicialCapacity, carMaxCapacity, carBrand, carModel));
	cout << "\n-- SUCCESS (Car added)";
}

/**
 * atribui carro ao piloto
 *
 * @param carLetter - string com letra se for mais le so primeira
 * @param pilotName - nome do piloto
 * @return true - entrou
 * @return false - nao entrou
*/
bool DGV::pilotEnterCar(char carLetter, string pilotName) {
	auto it = cars.begin();
	while (it != cars.end()) {
		if (carLetter == (*it)->getId()) {
			auto it2 = pilots.begin();
			while (it2 != pilots.end()) {
				if (pilotName.compare((*it2)->getName()) == 0) {
					if (!checkIfPilotAsCar(carLetter) && (*it2)->getPilotCarLetter() == '*') {
						(*it2)->setCar((*it));
						cout << "\n-- SUCCESS (Pilot " << (*it2)->getName() << " entered Car " << (*it)->getId() << ")";
						return true;
					}
					else {
						cout << "\n-- FAILED (Car " << (*it)->getId() << " cant be used by Pilot)";
						return false;
					}
				}
				it2++;
			}
			cout << "\n-- FAILED (Pilot Name Cannot Be Found)";
			return false;
		}
		it++;
	}
	cout << "\n-- FAILED (Car Letter Cannot Be Found)";
	return false;
}

/**
 * atribui carro ao piloto
 *
 * @param carLetter - string com letra se for mais le so primeira
 * @param pilotName - nome do piloto
 * @return true - entrou
 * @return false - nao entrou
*/
bool DGV::pilotLeaveCar(char carLetter) {
	auto it = pilots.begin();
	while (it != pilots.end()) {
		if (carLetter == (*it)->getPilotCarLetter()) {
			(*it)->setCar(NULL);
			cout << "\n-- SUCCESS (Pilot " << (*it)->getName() << " left Car " << carLetter << ")";
			return true;
		}
		it++;
	}
	cout << "\n-- FAILED (Car Letter Cannot Be Found)";
	return false;
}

/**
 * verifica pela letra se o carro existe
 *
 * @param carLetter - string com letra se for mais le so primeira
 * @return true - existe
 * @return false - nao existe
*/
bool DGV::checkIfCarExistsByLetter(char carLetter) {
	auto it = cars.begin();
	while (it != cars.end()) {
		if (carLetter == (*it)->getId())
			return true;
		it++;
	}
	return false;
}

/**
 * verifica pela letra se o carro tem piloto
 *
 * @param carLetter - id carro
 * @return true - existe
 * @return false - nao existe
*/
bool DGV::checkIfPilotAsCar(char carLetter) {
	auto it = pilots.begin();
	while (it != pilots.end()) {
		if ((*it)->getPilotCarLetter() == carLetter)
			return true;
		it++;
	}
	return false;
}

/**
 * Vai buscar o carro correspondente á letra
 *
 * @return ponteiro para carro pertendido
*/
Car* DGV::getCar(char carLetter) {
	auto it = cars.begin();
	while (it != cars.end()) {
		if ((*it)->getId() == carLetter)
			return (*it);
		it++;
	}
	return NULL;
}

/**
 * Poe os carros na posicao inicial para começar a corrida
 *
 * @param trackWidth - width da pista
*/
void DGV::setPilotCarInitialPosition(int trackWidth, int raceNumber) {
	int counter = 1, trackCounter = 0;
	auto it = pilots.begin();
	while (it != pilots.end()) {
		if ((*it)->getPilotCarLetter() != '*') {
		
			Point aux(counter + 1, 19);
			(*it)->setCarPosition(aux);
			(*it)->setPlacement(0);
			(*it)->getCar()->setCurrentPositionOnSquare(0);
			if (!(*it)->getCar()->getIsDamaged()) {
				championship->addPilotToRace((*it), trackCounter);
				counter = counter + trackWidth; //proxima posicao afrente
				(*it)->showCar();
				trackCounter++;
			}
		}
		it++;
	}
}

/**
 * Verifica se existem pilotos em carros
 *
 * @return true - existem pilotos em carros
 * @return false - nao existem pilotos em carros
*/
bool DGV::checkIfAnyPilotAsCar() {
	auto it = pilots.begin();
	while (it != pilots.end()) {
		if ((*it)->getPilotCarLetter() != '*')
			return true;
		it++;
	}
	return false;
}

/**
 * Diz a DGV qual o campeonato para por os pilotos e carros
 *
 * @param c - ponteiro para o campeonato
*/
void DGV::setChampionship(Championship* c) {
	championship = c;
}

/**
 * Remove o carro
 *
 * @param c - letra do carro
 * @return true - removido com sucesso
 * @return false - falhou a remover
*/
bool DGV::removeCar(string c) {
	int i = 0;
	char chacter, tmp;
	chacter = c.at(0);// converte de string para char a posicao da string em 1
	auto it = cars.begin();
	while (it != cars.end()) {
		tmp = ((*it)->getId());
		if (tmp == chacter) {
			auto it2 = pilots.begin();
			while (it2 != pilots.end())
			{
				if (((*it)->getId()) == ((*it2)->getIDofCarDrivenbyPilot())) {
					pilotLeaveCar((*it2)->getPilotCarLetter());
					cout << "\n CARRO DELETE: " << (*it)->getId();
					cars.erase(it);
					cout << "\n-- SUCCESS (Car Removed)";
					return true;
				}
				it2++;
			}
			cars.erase(it);
			cout << "\n-- SUCCESS (Car Removed)";
			return true;
		}
		i++;
		it++;
	}
	return false;
}

/**
 * Remove o piloto
 *
 * @param p - nome do piloto
 * @return true - removido com sucesso
 * @return false - falhou a remover
*/
bool DGV::removePilot(string p) {
	auto it = pilots.begin(); string name;
	int i = 0;
	while (it != pilots.end()) {
		if (p.compare((*it)->getName()) == 0) //
		{
			if ((*it)->getPilotCarLetter() == '*')
			{
				delete* it;
				pilots.erase(it);
				cout << "\n-- SUCCESS (Pilot Removed)";
				return true;
			}
			else
			{
				(*it)->setCar(NULL);
				delete* it;
				pilots.erase(it);
				cout << "\n-- SUCCESS (Pilot Left car and was removed)";
				return true;
			}
		}
		it++;
	}
	return false;
}

void DGV::giveDamageToCar(string c) {
	char chacter, tmp;
	chacter = c.at(0);// converte de string para char a posicao da string em 1
	auto it = cars.begin();
	while (it != cars.end()) {
		tmp = ((*it)->getId());
		if (tmp == chacter) {
			(*it)->setIsDamaged(true);
			return;
		}
		it++;
	}
}

void DGV::rechargeAllBatteries() {
	auto it = cars.begin();
	while (it != cars.end()) {
		(*it)->rechargeBattery();
		it++;
	}
}

void DGV::rechargeCarBattery(char carLetter, double value) {
	auto it = cars.begin();
	while (it != cars.end()) {
		if (carLetter = ((*it)->getId())) {
			(*it)->rechargeBatteryValue(value);
			return;
		}
		it++;
	}
}

void DGV::setDGVName(string nameDGV) {
	name.assign(nameDGV);
}

string DGV::getDGVName()const {
	return name;
}

int DGV::checkNumberOfPilotAsCar()
{
	int incrementor = 0;
	auto it = pilots.begin();
	while (it != pilots.end()) {
		if ((*it)->getPilotCarLetter() != '*')
			incrementor++;
		it++;
	}
	return incrementor;
}