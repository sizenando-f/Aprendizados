#pragma once
class Formas
{
public:
	virtual float calcArea() = 0;
	virtual Formas* alocar() = 0;
	virtual ~Formas();
};

