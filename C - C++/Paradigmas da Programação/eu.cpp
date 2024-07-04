#include <iostream>

using namespace std;

class Metro; // Forward declaration da classe Metro

class Centimetro {
    float medida;
public:
    Centimetro(const float medida = 0.0) : medida(medida) {};

    Centimetro(const Metro &metro); // Declaração do construtor de conversão

    operator Metro(); // Declaração do operador de conversão

    operator float() const {
        return medida;
    }
};

class Metro {
    float medida;
public:
    Metro(const float medida = 0.0) : medida(medida) {};

    Metro(const Centimetro &cm) {
        medida = (float)cm / 1000;
    }

    operator float() const {
        return medida;
    }

    operator Centimetro() {
        return Centimetro(medida * 1000);
    }
};

// Definição do construtor de conversão de Centimetro para Metro
Centimetro::Centimetro(const Metro &metro) {
    medida = (float)metro * 1000;
}

// Definição do operador de conversão de Centimetro para Metro
Centimetro::operator Metro() {
    return Metro(medida / 1000); // Correção: divide por 1000 para converter cm para m
}

class Quilometro {
    float medida;
public:
    Quilometro(const float medida = 0.0) : medida(medida) {};

    Quilometro(const Metro &metro) {
        medida = (float)metro / 1000;
    }

    Quilometro(const Centimetro &cm) {
        medida = (float)cm / 1000 / 1000;
    }

    operator Metro() {
        return Metro(medida * 1000);
    }

    operator Centimetro() {
        return Centimetro(medida * 1000 * 1000);
    }

    operator float() {
        return medida;
    }
};

int main() {
    Centimetro cm(1123812792);
    Metro me = cm; // Conversão de Centimetro para Metro

    cout << (float)me; // Exibe o valor da conversão
    return 0;
}
