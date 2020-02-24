#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "System.h"
#include "Commands.h"
#include "Console.h"
using namespace std;

string TYPESOFPILOTS[] = { "normal", "crazy", "rapido", "surpresa", "idc" };
int NUMBEROFRACES = 0;
int RACECOUNTER = 0;
bool CORRIDAEXECUTED = false;
/**
 * Construtor
*/
System::System() {
	this->mode = 0;
}

/**
 * Destrutor
*/
System::~System() {
	cout << "\nSystem was destructed...\n";
}

/**
 * Verifica qual o comando a executar do modo 1
 *
 * @param query - Query pretendida pelo utilizador
*/
bool System::applyQueryMode1(string query) {
	istringstream cmdBuf(query);
	string cmdTemp, args;

	//separa comando da string
	cmdBuf >> cmdTemp;

	if (cmdTemp.compare("carregaP") == 0) {
		if (exec_carregaP(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("carregaC") == 0) {
		if (exec_carregaC(query)) {
			return true;
		}
		else {
			return false;
		}
	}	
	else if (cmdTemp.compare("carregaA") == 0) {
		if (exec_carregaA(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("cria") == 0) {
		if (exec_cria(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("apaga") == 0) {
		if (exec_apaga(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("entranocarro") == 0) {
		if (exec_entranocarro(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("saidocarro") == 0) {
		if (exec_saidocarro(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("lista") == 0) {
		if (exec_lista(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("savedgv") == 0) {
		if (exec_savedgv(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("loaddgv") == 0) {
		if (exec_loaddgv(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("deldgv") == 0) {
		if (exec_deldgv(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("mode") == 0) {
		waitMode();
		return true;
	}
	else if (cmdTemp.compare("cls") == 0) {
		Consola::clrscr();
		return true;
	}
	else if (cmdTemp.compare("teste") == 0) {

		return true;
	}
	else if (cmdTemp.compare("poegaragem") == 0) {
		if (exec_poegaragem(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("rankings") == 0) {
		if (exec_rankings(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

/**
 * Verifica qual o comando a executar do modo 2
 *
 * @param query - Query pretendida pelo utilizador
*/
bool System::applyQueryMode2(string query) {
	istringstream cmdBuf(query);
	string cmdTemp, args;

	//separa comando da string
	cmdBuf >> cmdTemp;

	if (cmdTemp.compare("campeonato") == 0) {
		if (exec_campeonato(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("listacarros") == 0) {
		if (exec_listacarros(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("carregabat") == 0) {
		if (exec_carregabat(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("carregatudo") == 0) {
		if (exec_carregatudo(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("corrida") == 0) {
		if (exec_corrida(query)) {
			CORRIDAEXECUTED = true;
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("acidente") == 0) {
		if (exec_acidente(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("stop") == 0) {
		if (exec_stop(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("destroi") == 0) {
		if (exec_destroi(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("passatempo") == 0) {
		if (CORRIDAEXECUTED) {
			if (exec_passatempo(query)) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			cout << "\n-- FAILED (You need to do 'corrida' first)";
		}
	}
	else if (cmdTemp.compare("log") == 0) {
		if (exec_log(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("mode") == 0) {
		waitMode();
		return true;
	}
	else if (cmdTemp.compare("cls") == 0) {
		Consola::clrscr();
		return true;
	}
	else if (cmdTemp.compare("classificacao") == 0) {
		if (exec_classificacao(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (cmdTemp.compare("rankings") == 0) {
		if (exec_rankings(query)) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

/**
 * Escolha do modo pretendido pelo utilizador
*/
int System::waitMode() {
	int choice;
	Consola::setScreenSize(90, 90);
	Consola::clrscr();
	choice = modeInterface();
	if (choice == 1) {
		mode = 1;
		mode1FirstPick = true;
		waitQuery();
	}
	else if (choice == 2) {
		if (mode1FirstPick) {
			mode = 2;
			waitQuery();
		}
		else {
			Consola::goAndWrite(2, 12, "\n-- FAILED (You have to configure Mode 1 first)");
			Consola::getch();
			waitMode();
		}
	}
	else if (choice == 3) { //para chamar todos destrutores
		mode = 3;
		return 0;
	}
	return 0;
}


/**
 * Escolha da query pretendida pelo utilzador
*/
void System::waitQuery() {
	string input;
	bool status;
	Consola::clrscr();
	
	while (true) {
		if (mode == 3) //para chamar destrutores FIXED
			return;
		cout << "\n$ ";
		getline(cin, input);
		status = queryValidation(input, mode);
		if (!status) {
			cout << "\n-- FAILED (Unknown Query)";
		}
		else {
			switch (mode)
			{
			case 1:
				if (applyQueryMode1(input))
					cout << "\n -- SUCCESS (" << input << ")";
				else
					cout << "\n -- FAILED (" << input << ")";
				break;
			case 2:
				if (applyQueryMode2(input))
					cout << "\n -- SUCCESS (" << input << ")";
				else
					cout << "\n -- FAILED (" << input << ")";
				break;
			case 3://para chamar destrutores FIXED
				return;
			default:
				cout << "\n-- FAILED (Error Applying Query)";
			}
		}
	};
	return;
}

/**
 * Executa o comando carregaP <nomeFicheiro>
 * Obtêm um conjunto de pilotos que deverão ser criados a partir dos dados presentes no ficheiro
 * Linhas têm o seguinte formato: tipo nome
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_carregaP(string query) {
	string fileName, pilotType, pilotName, line;
	if (query.find_first_of(" \t") != string::npos) { // separa palavra se returnar npos não há nome de ficheiro
		fileName = query.substr(query.find_first_of(" \t") + 1); //separa segunda palavra da string
		ifstream infile(fileName);
		if (infile.good()) { //nao ha erros no ficheiro
			if (infile.is_open()) //aberto
			{
				while (getline(infile, line)) //get linha
				{
					istringstream lineBuf(line);
					lineBuf >> pilotType >> pilotName;
					while (!verifyPilotType(pilotType)) { //verifica tipo repeat ate correto
						cout << "\n-- FAILED (Invalid Pilot Type '" << pilotType << "')";
						cout << "\n   Insert New Type";
						cout << "\n$ ";
						getline(cin, pilotType);
					}
					while (!verifyPilotName(pilotName)) { //verifica nome repeat ate correto
						cout << "\n-- FAILED (Invalid Pilot Name '" << pilotName << "')";
						cout << "\n   Insert New Name";
						cout << "\n$ ";
						getline(cin, pilotName);
					}
					simulation.addPilot(pilotType, pilotName); //adiciona piloto
				}
			}
		}
		else {
			cout << "\n-- FAILED (File Not Found)";
			return false;
		}
		return true;
	}
	else {
		cout << "\n-- FAILED (Insert File Name)";
		return false;
	}
}

/**
 * Executa o comando carregaC <nomeFicheiro>
 * Obtêm um conjunto de carros que deverão ser criados a partir dos dados presentes no ficheiro
 * Linhas têm o seguinte formato: capacidadeInicial capacidadeMaxima marca modelo 
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_carregaC(string query) {
	string fileName, carInicialCapacity, carMaxCapacity, carBrand, carModel, carMaxSpeed, line;
	if (query.find_first_of(" \t") != string::npos) { // separa palavra se returnar npos não há nome de ficheiro
		fileName = query.substr(query.find_first_of(" \t") + 1); //separa segunda palavra da string
		ifstream infile(fileName);
		if (infile.good()) { //nao ha erros no ficheiro
			if (infile.is_open()) //aberto
			{
				while (getline(infile, line)) //get linha
				{
					istringstream lineBuf(line);
					carInicialCapacity.clear();
					carMaxCapacity.clear();
					carBrand.clear();
					carModel.clear();
					carMaxSpeed.clear();
					lineBuf >> carMaxSpeed >> carInicialCapacity >> carMaxCapacity >> carBrand >> carModel;
					if(!carInicialCapacity.empty() && !carMaxCapacity.empty() && !carBrand.empty() && !carModel.empty() && !carMaxSpeed.empty() && atoi(carMaxSpeed.c_str()) != 0)
						simulation.addCar(carMaxSpeed, carInicialCapacity, carMaxCapacity, carBrand, carModel); //adiciona carro
					else {
						cout << "\n-- FAILED (Something wrong with the parameters)";
						cout << "\n   Needs <Inicial Capacity> <Max Capacity> <Brand> <Model> <Max Speed Bigger than 0>";
					}
				}
			}
		}
		else {
			cout << "\n-- FAILED (File not found)";
			return false;
		}
		return true;
	}
	else {
		cout << "\n-- FAILED (Insert file name)";
		return false;
	}
}

/**
 * Executa o comando carregaA <nomeFicheiro>
 * Obtêm um conjunto de autódromos a incluir neste campeonato que deverão ser criados a partir dos dados presentes no ficheiro
 * Linhas têm o seguinte formato: N comprimento nome
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_carregaA(string query) {
	string fileName, autodromeMaxCars, autodromeLength, autodromeName, line;
	if (query.find_first_of(" \t") != string::npos) { // separa palavra se returnar npos não há nome de ficheiro
		fileName = query.substr(query.find_first_of(" \t") + 1); //separa segunda palavra da string
		ifstream infile(fileName);
		if (infile.good()) { //nao ha erros no ficheiro
			if (infile.is_open()) //aberto
			{
				while (getline(infile, line)) //get linha
				{
					istringstream lineBuf(line);
					lineBuf >> autodromeMaxCars >> autodromeLength >> autodromeName;
					simulation.addAutodrome(autodromeMaxCars, autodromeLength, autodromeName); //adiciona autodrome
				}
			}
		}
		else {
			cout << "\n-- FAILED (File not found)";
			return false;
		}
		return true;
	}
	else {
		cout << "\n-- FAILED (Insert file name)";
		return false;
	}
}

/**
 * Executa o comando cria
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_cria(string query) {
	istringstream buf(query);
	string tmp, pORc, arg1, arg2, arg3, arg4, arg5, Generic; //piloto p < tipo> <nome> || carro c <marca  modelo, capacidadeini, capadmax>

	buf >> tmp >> pORc;
	if (pORc == "p") {
		buf >> arg1;
		buf >> arg2;
		if (!verifyPilotName(arg2) || (arg1.empty()) || (!verifyPilotType(arg1)) || (arg2.empty())) {
			cout << " \n-- FAILED(Insert valid	parameters) " << arg2 << endl;
			return false;

		}
		simulation.addPilot(arg1, arg2);
		return true;

	}
	else	if (pORc == "c") // velocidade  ccapacidadeInicial capacidadeMaxima marca modelo

	{
		buf >> arg1 >> arg2 >> arg3 >> arg4 >> arg5;
		if (arg5.size() == 0) {
			arg5 = "Generic";
		}
		if (verifyEnergyValuesAndSpeed(arg2, arg3, arg1) == false) {
			return false;
		}

		//ring carInicialCapacity, string carMaxCapacity, string carBrand, string carModel, string carMaxSpeed
		simulation.addCar(arg1, arg2, arg3, arg4, arg5);
		return true;

	}
	else if (pORc == "a")
	{                    //string maxcars, string lenght, string name)
		buf >> arg1 >> arg2 >> arg3;
		if (arg3.size() == 0)
			return false;
		if (verifyAutodromeParameters(arg1, arg2, arg3)) {
			simulation.addAutodrome(arg1, arg2, arg3);
			return true;
		}
		return false;

	}
	return false;
}

/**
 * Executa o comando apaga
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_apaga(string query) {
	string pORc, arg1, tmp;
	istringstream buf(query);

	buf >> tmp >> pORc >> arg1;
	if (pORc == "p") {
		if (!verifyPilotName(arg1)) {
			simulation.removePilot(arg1);
			return true;
		}
		return false;

	}
	else if (pORc == "c")
	{
		if (!verifyIfCarExists(arg1)) {
			simulation.removeCar(arg1);
			return true;
		}
		return false;

	}
	else if (pORc == "a")
	{
		if (!verifyAutodromeName(arg1)) {
			simulation.removeAutodrome(arg1);
			return true;
		}
		return false;

	}
	return false;
}

bool System::verifyIfCarExists(string name)
{
	if (simulation.checkIfCarExists(name))
		return false;
	cout << "\n-- FAILED (Car not Found)" << endl;

	return true;
}

/**
 * Executa o comando entranocarro
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_entranocarro(string query) {
	string values, carLetter, pilotName;
	if (query.find_first_of(" \t") != string::npos) {
		values = query.substr(query.find_first_of(" \t") + 1);
		istringstream valuesBuf(values);
		valuesBuf >> carLetter >> pilotName;
		
		if (simulation.pilotEnterCar(carLetter, pilotName))
			return true;
		else
			return false;
	}
	else {
		cout << "\n-- FAILED (Insert parameters)";
		return false;
	}
	return false;
}

/**
 * Executa o comando saidocarro
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_saidocarro(string query) {
	string values, carLetter;
	if (query.find_first_of(" \t") != string::npos) {
		values = query.substr(query.find_first_of(" \t") + 1);
		istringstream valuesBuf(values);
		valuesBuf >> carLetter;

		if (simulation.pilotLeaveCar(carLetter))
			return true;
		else
			return false;
	}
	else {
		cout << "\n-- FAILED (Insert parameters)";
		return false;
	}
	return false;
}

/**
 * Executa o comando lista
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_lista(string query) {
	simulation.printAll();
	return true;
}

/**
 * Executa o comando savedgv
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_savedgv(string query) {
	string values, dgvName;
	if (query.find_first_of(" \t") != string::npos) {
		values = query.substr(query.find_first_of(" \t") + 1);
		istringstream valuesBuf(values);
		valuesBuf >> dgvName;
		simulation.saveDGV(dgvName);
		return true;
	}
	else {
		cout << "\n-- FAILED (Insert parameters)";
		return false;
	}
	return false;
}

/**
 * Executa o comando loaddgv
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_loaddgv(string query) {
	string values, dgvName;
	if (query.find_first_of(" \t") != string::npos) {
		values = query.substr(query.find_first_of(" \t") + 1);
		istringstream valuesBuf(values);
		valuesBuf >> dgvName;
		simulation.loadDGV(dgvName);
		return true;
	}
	else {
		cout << "\n-- FAILED (Insert parameters)";
		return false;
	}
	return false;
}

/**
 * Executa o comando deldgv
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_deldgv(string query) {
	string values, dgvName;
	if (query.find_first_of(" \t") != string::npos) {
		values = query.substr(query.find_first_of(" \t") + 1);
		istringstream valuesBuf(values);
		valuesBuf >> dgvName;
		simulation.delDGV(dgvName);
		return true;
	}
	else {
		cout << "\n-- FAILED (Insert parameters)";
		return false;
	}
	return false;
}

/**
 * Executa o comando poegaragem
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_poegaragem(string query) {
	string values, carLetter, autodromeName;
	if (query.find_first_of(" \t") != string::npos) {
		values = query.substr(query.find_first_of(" \t") + 1);
		istringstream valuesBuf(values);
		valuesBuf >> carLetter >> autodromeName;

		if (simulation.carEnterGarage(carLetter, autodromeName))
			return true;
		else
			return false;
	}
	else {
		cout << "\n-- FAILED (Insert parameters)";
		return false;
	}
	return false;
}

/**
 * Executa o comando campeonato
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_campeonato(string query) {
	string chosenAutodromes, splitedAutodrome;
	int raceNumber = 1;
	if (query.find_first_of(" \t") != string::npos) { // separa palavra se returnar npos campeonatos
		chosenAutodromes = query.substr(query.find_first_of(" \t") + 1);
		istringstream splitString(chosenAutodromes);
		string splitedAutodrome;
		splitString >> splitedAutodrome;
		do{ // split da string
			if (simulation.makeAutodromePartOfChampionship(splitedAutodrome)) {
				cout << "-- SUCCESS (" << splitedAutodrome << " added to be apart of championship on race " << raceNumber <<")";
			}
			else {
				cout << "-- FAILED (" << splitedAutodrome << " doesn't exist)";
			}
			raceNumber++;
			splitString >> splitedAutodrome;
		} while (splitString);
		NUMBEROFRACES = raceNumber;
		return true;
	}
	else {
		cout << "\n-- FAILED (Insert parameters)";
		return false;
	}
	return false;;
}

/**
 * Executa o comando listacarros
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_listacarros(string query) {
	simulation.printCars();
	return true;
}

/**
 * Executa o comando carregabat
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_carregabat(string query) {
	string values, carLetter, value;
	if (query.find_first_of(" \t") != string::npos) { // separa palavra se returnar npos campeonatos
		values = query.substr(query.find_first_of(" \t") + 1);
		istringstream valuesBuf(values);
		string splitedAutodrome;
		valuesBuf >> carLetter >> value;
		simulation.rechargeCarBattery(carLetter, stod(value));
		return true;
	}
	else {
		cout << "\n-- FAILED (Insert parameters)";
		return false;
	}
	return false;
}

/**
 * Executa o comando carregatudo
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_carregatudo(string query) {
	simulation.rechargeAllBatteries();
	return true;
}

/**
 * Executa o comando corrida
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_corrida(string query) {
	if (simulation.setupRace(RACECOUNTER)) {
		RACECOUNTER++;
		return true;
	}
	else {
		RACECOUNTER = 0;
		return false;
	}
	return false;
}

/**
 * Executa o comando acidente
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_acidente(string query) {
	istringstream buf(query);
	string letraCarro, cmd;
	buf >> cmd >> letraCarro;

	if (!verifyIfCarExists(letraCarro)) // carro existe
	{
		if (simulation.makeAcident(letraCarro))
			return true;
	}

	return false;
}

/**
 * Executa o comando stop
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_stop(string query) {
	istringstream buf(query);
	string pilotName;
	if (query.find_first_of(" \t") != string::npos) {
		buf >> pilotName;
		simulation.orderToStop(pilotName);
		return true;
	}
	else {
		cout << "\n-- FAILED (Insert parameters)";
		return false;
	}
	return false;
}

/**
 * Executa o comando destroi
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_destroi(string query) {
	istringstream buf(query);
	string carLetter, cmd;
	if (query.find_first_of(" \t") != string::npos) {
		buf >> cmd >> carLetter;
		if (!verifyIfCarExists(carLetter)) {
			simulation.removeCar(carLetter);
			return true;
		}
	}
	else {
		cout << "\n-- FAILED (Insert parameters)";
		return false;
	}
	return false;
}

/**
 * Executa o comando passatempo
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_passatempo(string query) {
	string numberOfSeconds;
	if (query.find_first_of(" \t") != string::npos) { // separa palavra se returnar npos campeonatos
		numberOfSeconds = query.substr(query.find_first_of(" \t") + 1);
		istringstream splitString(numberOfSeconds);
		string splitedSeconds;
		splitString >> splitedSeconds;
		
		simulation.makeMovement(stoi(splitedSeconds));
		
		return true;
	}
	else {
		cout << "\n-- FAILED (Insert parameters)";
		return false;
	}
	return false;
}

/**
 * Executa o comando log
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_log(string query) {
	return false;
}

/**
 * Executa o comando classificacao
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_classificacao(string query) {
	simulation.printPlacements();
	return true;
}

/**
 * Executa o comando rankings
 *
 * @param query - Query pretendida pelo utilizador
 * @return true - Comando executado com sucesso
 * @return false - Falha na execução do programa
*/
bool System::exec_rankings(string query) {
	simulation.printRankings();
	return true;
}

/**
 * Verifica se nome do piloto é valido
 *
 * @param name - nome do piloto
 * @return true - Nome valido
 * @return false - Nome invalido
*/
bool System::verifyPilotName(string name) {
	if (simulation.checkForPilotNameRepeat(name))
		return false;
	return true;
}

/**
 * Verifica se tipo do piloto é valido
 *
 * @param type - tipo do piloto
 * @return true - tipo valido
 * @return false - tipo invalido
*/
bool System::verifyPilotType(string type) {
	for (int i = 0; i < sizeof(TYPESOFPILOTS) / sizeof(TYPESOFPILOTS[0]); i++) {
		if (type.compare(TYPESOFPILOTS[i]) == 0) {
			return true;
		}
	}
	return false;
}

/**
 * Verifica os valores da energia
 *
 * @param energ1
 * @param energ2
 * @param speed
 * @return true - valores corretos
 * @return false - valores errados
*/
bool System::verifyEnergyValuesAndSpeed(string energ1, string energ2, string speed) const // verifica valores da energy
{
	stringstream convert(energ1), convert2(energ2), convert3(speed);
	int x, y, z;

	convert >> x, convert2 >> y, convert3 >> z;
	if ((x <= 0) || (y <= 0) || (x > y) || (z <= 0)) {
		cout << "\n-- FAILED (Energy values cant be 0 or smaller than 0)" << endl;
		return false;
	}
	return true;
}

/**
 * Verifica os parametros do autodrome
 *
 * @param maxcars - valores max dos carros
 * @param length - comprimento
 * @param name - nome do autodrome
 * @return true - valores corretos
 * @return false - valores errados
*/
bool System::verifyAutodromeParameters(string maxcars, string lenght, string name)
{
	stringstream convert(maxcars), conver2(lenght);
	int x = 0, y = 0;
	convert >> x, conver2 >> y;
	if ((x <= 0) || (y <= 0) || !(verifyAutodromeName(name) || (name.size() == 0)))
	{
		return false;
	}
	return true;
}

/**
 * Verifica se o nome do autodrome existe
 *
 * @return true - nome existe
 * @return false - nome nao existe
*/
bool System::verifyAutodromeName(string name)
{
	if (simulation.checkforAutodromeNameRepeat(name))
		return false;
	return true;
}