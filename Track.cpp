#include "Track.h"
#include <iostream>
#include "Console.h"
using namespace std;
//construtor
Track::Track() {
	race = NULL;
}

//destrutor
Track::~Track() {
}

/**
 * Adiciona carro á pista
 *
 * @param c - ponteiro para carro
*/
void Track::setPilotToRace(Pilot* p) {
	race->setPilot(p);
}

/**
 * Atribui as dimensoes á pista
 *
 * @param w, l, x, y, tN - largura comprimento x y numerodapista
*/
void Track::setTrackPosition(int w, int l, int x, int y, int tN){
	width = w;
	length = l;
	xAxis = x;
	yAxis = y;
	trackNumber = tN;
}

/**
 * Mostra pistas
*/
void Track::show() {
	Consola::gotoxy(xAxis, yAxis - 1);
	cout << trackNumber;
	Consola::drawRectangle(width, length, xAxis, yAxis); //desenha rectangulo
}

/**
 * devolve a corrida correspendente da pista
 *
 * @return race - corrida pertencente á pista
*/
Race* Track::getRace() {
	return race;
}

/**
 * Adiciona corrida á pista
 *
 * @param r - race para adicionar
*/
void Track::addRace(Race *r) {
	race = r;
    
}