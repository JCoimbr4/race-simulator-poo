#include "Commands.h"
#include <iostream>
#include <sstream>

using namespace std;

/**
 * Lista de comandos utilizados no modo 1
*/
query cmdListMode1[] = {
	{"carregaP", 1},
	{"carregaC", 1},
	{"carregaA", 1},
	{"cria", 2},
	{"apaga", 2},
	{"entranocarro", 2},
	{"saidocarro", 2},
	{"lista", 0},
	{"savedgv", 1},
	{"loaddgv", 1},
	{"deldgv", 1},
	{"mode", 0},
	{"cls", 0},
	{"teste", 0},
	{"poegaragem", 2},
	{"rankings", 0}
};

/**
 * Lista de comandos utilizados no modo 2
*/
query cmdListMode2[] = {
	{"campeonato", 1},
	{"listacarros", 1},
	{"carregabat", 2},
	{"carregatudo", 0},
	{"corrida", 0},
	{"acidente", 1},
	{"stop", 1},
	{"destroi", 1},
	{"passatempo", 1},
	{"log", 0},
	{"mode", 0},
	{"cls", 0},
	{"classificacao", 0},
	{"rankings", 0}
};

/**
 * Compara o comando pretendido com os comandos existentes nas listas
 * Divisão no for por causa dos bytes
 *
 * @param input Input do utilizador
 * @param mode Modo escolhido
 * @return true - Se o comando existir
 * @return false - Se o comando não existir
*/
bool queryValidation(string input, int mode) {
	istringstream cmdBuf(input);
	string cmdTemp;
	
	//separa comando da string
	cmdBuf >> cmdTemp;

	switch (mode) {
	case 1:
		for (int i = 0; i < sizeof(cmdListMode1) / sizeof(cmdListMode1[0]); i++) {
			if (cmdTemp.compare(cmdListMode1[i].cmd) == 0) {
				return true;
			}
		}
		return false;
		break;
	case 2:
		for (int i = 0; i < sizeof(cmdListMode2) / sizeof(cmdListMode2[0]); i++) {
			if (cmdTemp.compare(cmdListMode2[i].cmd) == 0) {
				return true;
			}
		}
		return false;
		break;
	default:
		cout << "# Mode error on query validation";
		return false;
		break;
	}
	return false;
}


