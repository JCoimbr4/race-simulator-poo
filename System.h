#pragma once
#include "Simulation.h"
using namespace std;

class System
{
	Simulation simulation;
	int mode;
	bool mode1FirstPick = false;
public:
	System();
	~System();
	int waitMode();
	void waitQuery();

	bool applyQueryMode1(string query);
	bool applyQueryMode2(string query);

	// ----------------- PILOTS & CARS---------------------
	bool verifyPilotType(string type);
	bool verifyPilotName(string name);
	bool verifyEnergyValuesAndSpeed(string energ1, string energ2, string speed)const;
	bool verifyIfCarExists(string name);
	// ----------------------------------------------

	// ----------------- AUTODROME ------------------
	bool verifyAutodromeParameters(string maxcars, string lenght, string name);
	bool verifyAutodromeName(string name);
	// ----------------------------------------------

	// ---------- EXECUTAR COMANDOS MODO 1 ----------
	bool exec_carregaP(string query);
	bool exec_carregaC(string query);
	bool exec_carregaA(string query);
	bool exec_cria(string query);
	bool exec_apaga(string query);
	bool exec_entranocarro(string query);
	bool exec_saidocarro(string query);
	bool exec_lista(string query);
	bool exec_savedgv(string query);
	bool exec_loaddgv(string query);
	bool exec_deldgv(string query);
	bool exec_poegaragem(string query);
	// ----------------------------------------------

	// ---------- EXECUTAR COMANDOS MODO 2 ----------
	bool exec_campeonato(string query);
	bool exec_listacarros(string query);
	bool exec_carregabat(string query);
	bool exec_carregatudo(string query);
	bool exec_corrida(string query);
	bool exec_acidente(string query);
	bool exec_stop(string query);
	bool exec_destroi(string query);
	bool exec_passatempo(string query);
	bool exec_log(string query);
	bool exec_classificacao(string query);
	bool exec_rankings(string query);
	// ----------------------------------------------
};