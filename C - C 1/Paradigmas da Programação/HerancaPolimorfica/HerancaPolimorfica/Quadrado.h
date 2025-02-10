#pragma once
#include "Formas.h"
class Quadrado : public Formas
{
	float lado;
public:
	Quadrado(float lado = 1.0);
	virtual float calcArea() override;
	Formas* alocar() override;

	virtual float getLado() const;
	virtual void setLado(float l);
};

