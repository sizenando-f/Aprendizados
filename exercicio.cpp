#include <iostream>

using namespace std;

class ComplexNumber{
    int a, b;

    public:
    ComplexNumber() : a(0), b(0){
    }

    ComplexNumber(int a, int b) : a(a), b(b){
    }

    int getA() const {
        return a;
    }

    int getB() const {
        return b;
    }

    void setA(int a){
        this->a = a;
    }

    void setB(int b){
        this->b = b;
    }


    ComplexNumber soma(ComplexNumber num){
        ComplexNumber Z3;
        Z3.a = a + num.a;
        Z3.b = b + num.b;
        return Z3;
    }

};

int main(){
    ComplexNumber Z1(1, 2), Z2(2, 1), Z3;
    Z1.setA(2); Z1.setB(1);
    Z3 = Z1.soma(Z2);
    cout << Z3.getA() << " + " << Z3.getB() << "i" << endl;
    return 0;
}