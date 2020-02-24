#include "Simulation.h"
#include "Console.h"
#include <vector>
#include <string>
#include <iostream>

int RACENUMBERAUX = 0;
//construtor
Simulation::Simulation() {
}

//destrutor
Simulation::~Simulation() {
}

/**
 * Manda DVG adicionar piloto
 *
 * @param p - piloto a ser adicionado
*/
void Simulation::addPilot(string type, string name) {
	dgv.addPilot(type, name);
}

/**
 * Imprime toda a informação
*/
void Simulation::printAll() {
	dgv.printAll();
	auto it = autodromes.begin();
	cout << "\n-------------------";
	cout << "\n*Informacao sobre os Autodromes:*\n";
	while (it != autodromes.end()) {
		cout << "\nNome: " << it->getName();
		cout << "\nMaximo Carros: " << it->getMaxCars();
		cout << "\nComprimento: " << it->getLength();
		cout << "\nGaragem: ";
		it->printCarsOnGarage();
		cout << "\n";
		it++;
	}
	cout << "\n-------------------";
	cout << "\n*Informacao sobre o Campeonato:*\n";
	championship.printAllAutodromesOnChampionship();
}

/**
 * Imprime toda a informação
*/
void Simulation::printCars() {
	dgv.printCars();
}

/**
 * Devolve quantidade de pilotos no vector
 *
 * @return tamanho do vector
*/
int Simulation::getTotalPilots() {
	return dgv.getTotalPilots();
}

/**
 * Manda DVG procurar repeat no nome do piloto
 *
 * @return true - nome existe
 * @return false - nome nao existe
*/
bool Simulation::checkForPilotNameRepeat(string name) {
	if (dgv.checkForPilotNameRepeat(name))
		return true;
	return false;
}

/**
 * Adiciona novo Carro ao vetor
 *
 * @param c - carro a ser adicionado
*/
void Simulation::addCar(string carMaxSpeed, string carInicialCapacity, string carMaxCapacity, string carBrand, string carModel) {
	dgv.addCar(atoi(carMaxSpeed.c_str()), atof(carInicialCapacity.c_str()), atof(carMaxCapacity.c_str()), carBrand, carModel);
}

/**
 * Adiciona novo Autodrome ao vetor
 *
 * @param a - autodrome a ser adicionado
*/
void Simulation::addAutodrome(string autodromeMaxCars, string autodromeLength, string autodromeName) {
	Autodrome aux(stoi(autodromeMaxCars), stoi(autodromeLength), autodromeName);
	autodromes.push_back(aux);
	cout << "\n-- SUCCESS (Autodrome added)";
}


/**
 * Associa piloto a um carro
 *
 * @param carLeter - letra do carro, se for mais de que uma letra le so a primeira
 * @param pilotName - nome do piloto
 * @return true -  entrou com sucesso
 * @return false - nao entrou
*/
bool Simulation::pilotEnterCar(string carLetter, string pilotName) {
	if (carLetter.empty()) {
		cout << "\n-- FAILED (Car Letter Empty)";
		return false;
	}
	if (pilotName.empty()) {
		cout << "\n-- FAILED (Pilot Name Empty)";
		return false;
	}
	char letter = carLetter.at(0);
	return dgv.pilotEnterCar(letter, pilotName);
}

/**
 * Desassocia piloto de carro
 *
 * @param carLeter - letra do carro, se for mais de que uma letra le so a primeira
 * @return true -  saiu com sucesso
 * @return false - nao saiu
*/
bool Simulation::pilotLeaveCar(string carLetter) {
	if (carLetter.empty()) {
		cout << "\n-- FAILED (Car Letter Empty)";
		return false;
	}
	
	char letter = carLetter.at(0);
	return dgv.pilotLeaveCar(letter);
}

/**
 * Faz um autodrome parte de um campeonato
 *
 * @param autodromeName - nome do autodrome
 * @return true - autodrome adicionado ao campeonato
 * @return false - nao foi adicionado porque nao existe
*/
bool Simulation::makeAutodromePartOfChampionship(string autodromeName) {
	int raceNumber = 1;
	auto it = autodromes.begin();
	while (it != autodromes.end()) {
		if (autodromeName.compare(it->getName()) == 0) {
			championship.addAutodrome(&(*it));
			return true;
		}
		raceNumber++;
		it++;
	}
	return false;
}

/**
 * Associa carro a garagem num autodrome
 *
 * @param carLeter - letra do carro, se for mais de que uma letra le so a primeira
 * @param pilotName - nome do piloto
 * @return true -  entrou com sucesso
 * @return false - nao entrou
*/
bool Simulation::carEnterGarage(string carLetter, string autodromeName) {
	if (carLetter.empty()) {
		cout << "\n-- FAILED (Car Letter Empty)";
		return false;
	}
	if (autodromeName.empty()) {
		cout << "\n-- FAILED (Autodrome Name Empty)";
		return false;
	}
	char letter = carLetter.at(0);
	if (dgv.checkIfCarExistsByLetter(letter)) {
		auto it = autodromes.begin();
		while (it != autodromes.end()) {
			if (autodromeName.compare(it->getName()) == 0) {
				it->addCarToGarage(dgv.getCar(letter)); //adiciona carro a garagem
				dgv.pilotLeaveCar(letter); //piloto sai do carro
				return true;
			}
			it++;
		}
		cout << "\n-- FAILED (Autodrome Name Not Found)";
		return false;
	}
	else {
		return false;
	}
	
}

/**
 * Começa a corrida
*/
bool Simulation::setupRace(int raceNumber) {
	int trackWidth = 0;
	championship.clearPlacementsAndRaces();
	if (championship.getNumberOfAutodromes() > 0 && championship.getNumberOfAutodromes() > raceNumber) {
		if (dgv.checkIfAnyPilotAsCar() && dgv.checkNumberOfPilotAsCar() > 1) {
			if (championship.setupTracks(raceNumber)) {
				dgv.setChampionship(&championship); //diz a dgv qual o championship
				RACENUMBERAUX = raceNumber;
				trackWidth = 80 / autodromes.at(raceNumber).getMaxCars(); //divide largura max pelo numero de carros
				dgv.setPilotCarInitialPosition(trackWidth, raceNumber); //posicao inicial do carro + add á race
					
				Consola::gotoxy(1, 20);
				return true;
			}
			else {
				cout << "\n-- FAILED (Track not found)";
				return false;
			}
		}
		else {
			cout << "\n-- FAILED (No Pilots on Cars)";
			return false;
		}
		
		return false;
	}
	else {
		if (championship.getNumberOfAutodromes() <= 0) {
			championship.removeAllAutodromes();
			Championship reset; //CHANGED
			reset = championship; //CHANGED
			cout << "\n-- FAILED (No more Autodromes on Championship)";
		}
		cout << "\n-- FAILED (No Autodromes added to Championship)";
		return false;
	}
	return false;
}


/**
 * Faz x movimentos e verifica a cada um se ha vencedor
*/
void Simulation::makeMovement(int numberOfSeconds) {
	Consola::clrscr();
	autodromes.at(RACENUMBERAUX).showTracks();
	for (int i = 0; i < numberOfSeconds; i++) {
		championship.updatePlacements();
		if (!championship.checkForWinner()) {
			
			championship.makeMovement();
			Consola::gotoxy(90, 1);
			cout << "Timer: " << championship.getRaceTimer();
			Consola::getch();
			championship.addSecondToTimer();
		}
		else {
			Consola::gotoxy(90, 5);
			cout << "--** WE HAVE A WINNER **--";
			Consola::gotoxy(1, 20);
			Consola::getch();
			championship.resetForNewRace();
			break;
		}
	}
	Consola::gotoxy(1, 20);
}

/**
 * Verifica se nome de autodrome existe
*/
bool Simulation::checkforAutodromeNameRepeat(string name) {
	auto it = autodromes.begin();
	while (it != autodromes.end()) {
		if (name.compare(it->getName()) == 0)
			return true;
		it++;
	}
	return false;
}

/**
 * Verifica se carro existe
*/
bool Simulation::checkIfCarExists(string carLetter) {
	if (carLetter.empty()) {
		cout << "\n-- FAILED (Car Letter Empty)";
		return false;
	}
	char letter = carLetter.at(0);
	return dgv.checkIfCarExistsByLetter(letter);
}

/**
 * manda remover carro
*/
bool Simulation::removeCar(string& carId) {
	return dgv.removeCar(carId);
}

/**
 * manda remover piloto
*/
void Simulation::removePilot(string& nome) {
	dgv.removePilot(nome);
}

/**
 * manda remover autodrome
*/
bool Simulation::removeAutodrome(string& name) {
	auto it = autodromes.begin();
	while (it != autodromes.end())
	{
		if (name.compare(it->getName()) == 0) {
			autodromes.erase(it);
			cout << "\n-- SUCCESS (Autodrome Removed)" << endl;
			return true;
		}
		it++;
	}

	return false;
}

/**
 * Faz acidente
*/
bool Simulation::makeAcident(string& letra) {
	dgv.giveDamageToCar(letra);
	
	return true;
}

void Simulation::printPlacements() {
	championship.printPlacements();
}

void Simulation::printRankings() {
	championship.printRankings();
}

void Simulation::rechargeAllBatteries() {
	dgv.rechargeAllBatteries();
}

void Simulation::rechargeCarBattery(string & carLetter, double value) {
	char letter = carLetter.at(0);
	dgv.rechargeCarBattery(letter, value);
}

void Simulation::orderToStop(string pilotName) {
	if (championship.orderToStop(pilotName)) {
		cout << "\n-- SUCCESS (Pilot ordered to stop)" << endl;
	}
	else {
		cout << "\n-- FAILED (Pilot not in Championship)" << endl;
	}
	
}

void Simulation::saveDGV(string name) {
	dgv.setDGVName(name);
	savedDGV.push_back(dgv);
	cout << "\n -- SUCCESS (DGV Saved)";
}
void Simulation::loadDGV(string name) {
	auto it = savedDGV.begin();
	while (it != savedDGV.end())
	{
		if (it->getDGVName().compare(name) == 0) {
			dgv = *it;
			cout << "\n -- SUCCESS (DGV Loaded)";
			return;
		}
		it++;
	}
	cout << "\n -- FAILED (DGV doesnt exist)";
}
void Simulation::delDGV(string name) {
	
	auto it = savedDGV.begin();
	while (it != savedDGV.end())
	{
		if (it->getDGVName().compare(name) == 0) {
			savedDGV.erase(it);
			cout << "\n-- SUCCESS (DGV Removed)" << endl;
			return;
		}
		it++;
	}
	cout << "\n -- FAILED (DGV doesnt exist)";
}