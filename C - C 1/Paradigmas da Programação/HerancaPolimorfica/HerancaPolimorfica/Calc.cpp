#include "Calc.h"


void Calc::insert(Formas* forma)
{
	formas.push_back(forma->alocar());
}

float Calc::areaTotal() const
{
	float soma = 0.0;
	for (const auto& forma : formas) {
		soma += forma->calcArea();
	}
	return soma;
}

Calc::~Calc()
{
	for (const auto& forma : formas) {
		delete forma;
	}
}
