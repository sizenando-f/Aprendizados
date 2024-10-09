#pragma once
#include "Formas.h"
class Circulo : public Formas
{
	float raio;
public:
	Circulo(float raio = 1.0);
	virtual float calcArea() override;
	Formas* alocar() override;

	virtual float getRaio() const;
	virtual void setRaio(float r);
};

