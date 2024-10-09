#include "Circulo.h"

Circulo::Circulo(float raio):raio(raio)
{
}

float Circulo::calcArea()
{
    return 3.14 * (raio * raio);
}

Formas* Circulo::alocar()
{
    return new Circulo(this->raio);
}

float Circulo::getRaio() const
{
    return raio;
}

void Circulo::setRaio(float r)
{
    raio = r;
}

