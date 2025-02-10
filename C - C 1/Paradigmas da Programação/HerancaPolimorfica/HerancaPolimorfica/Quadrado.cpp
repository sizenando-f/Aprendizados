#include "Quadrado.h"

Quadrado::Quadrado(float lado): lado(lado)
{
}

float Quadrado::calcArea()
{
	return lado * lado;
}

Formas* Quadrado::alocar()
{
	return new Quadrado(this->lado);
}

float Quadrado::getLado() const
{
	return lado;
}

void Quadrado::setLado(float l)
{
	lado = l;
}
