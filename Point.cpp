#include "Point.h"
#include <iostream>

using namespace std;
/**
 * Construtor
*/
Point::Point(int xP, int yP) {
	x = xP;
	y = yP;
}

/**
 * Construtor
*/
Point::Point() {

}

/**
 * Destrutor
*/
Point::~Point() {
}

/**
 * Adiciona um ponto a outro
 *
 * @param p - ponto a adicionar
 * @return ponto com valor adicionado
*/
Point Point::add(const Point& p) const {
	return Point(x + p.x, y + p.y);
}

/**
 * Subtrai um ponto a outro
 *
 * @param p - ponto a subtrair
 * @return ponto com valor subtraido
*/
Point Point::sub(const Point& p) const {
	return Point(x - p.x, y - p.y);
}

/**
 * Operador de atribuição
 *
 * @return point
*/
Point& Point::operator=(const Point& outro) {
	if (this == &outro)
		return *this;
	x = outro.x;
	y = outro.y;
	return *this;
}

/**
 * Operador de comparaçao
 *
 * @return true - é igual
 * @return false - é diferente
*/
bool Point::operator==(const Point& p)const {
	if (this->x == p.x && this->y == p.y)
		return true;
	return false;
}

/**
 * Operador de comparacao
 *
 * @return true - é diferente
 * @return false - é igual
*/
bool Point::operator!=(const Point& p)const {
	if (this->x != p.x && this->y != p.y)
		return true;
	return false;
}

/**
 * Construtor por copia
*/
Point::Point(const Point& p) {
	x = p.x;
	y = p.y;

}