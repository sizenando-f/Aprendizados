#include <iostream>

using namespace std;

class ComplexNumber{
    float a, b;

    public:
    ComplexNumber() : a(0), b(0){   // Construtor Padrão
    }

    ComplexNumber(const float a, const float b) : a(a), b(b){   // Construtor Parametrizado
    }

    float getA() const {
        return a;
    }

    float getB() const {
        return b;
    }

    void setA(const float a){
        this->a = a;
    }

    void setB(const float b){
        this->b = b;
    }


    ComplexNumber soma(const ComplexNumber other) const {
        return ComplexNumber(a + other.a, b + other.b);
    }

};

int main(){
    ComplexNumber Z1(1, 2), Z2(2, 1), Z3;
    const ComplexNumber CC(1.0, 2.0);
    Z1.setA(2); Z1.setB(1);
    Z3 = Z1.soma(Z2);
    cout << Z3.getA() << " + " << Z3.getB() << "i" << endl;
    return 0;
}