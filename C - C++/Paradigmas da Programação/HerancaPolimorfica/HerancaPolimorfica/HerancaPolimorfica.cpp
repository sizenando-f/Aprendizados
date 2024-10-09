#include <iostream>
#include "Circulo.h"
#include "Quadrado.h"
#include "Calc.h"

using namespace std;

int main()
{
    Formas* circ = new Circulo(3);
    Formas* quad = new Quadrado(3);
    Calc c;
    c.insert(circ);
    c.insert(quad);
    cout << c.areaTotal();
}
