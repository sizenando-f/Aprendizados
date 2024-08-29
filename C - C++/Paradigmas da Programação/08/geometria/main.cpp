#include <iostream>
#include <vector>

using namespace std;

class SGeometria{
  public:
    virtual float calcArea()=0; // Virtual para poder sobrescrever e acessar da derivada
    virtual ~SGeometria(){};  // Não pode ser virtual puro
};

class SQuadrado : public SGeometria{
  float lado;
  public:
    SQuadrado(float side = 1.0):lado(side){}

    virtual float calcArea(){
      return lado * lado;
    }

};

class SRetangulo : public SGeometria{
  float l1, l2;
  public:
    SRetangulo(float lado1 = 1.0, float lado2 = 1.0) : l1(lado1), l2(lado2){}
    
    virtual float calcArea(){
      return l1 * l2;
    }
};

class SCalc{
  vector<SGeometria*> geos;
  
  public:
    void insert(SGeometria* sGeo){
      geos.push_back(sGeo);
    }

    float areaTotal(){
      vector<SGeometria*>::iterator it; // iterator do tipo da base
      float area = 0.0;
      for(it = geos.begin(); it != geos.end(); it++){
        area += (*it)->calcArea();
      }
      return area;
    }

  ~SCalc(){
    vector<SGeometria*>::iterator it; // iterator do tipo da base
    for(it = geos.begin(); it != geos.end(); it++){
      delete *it;
    }
  }
};

int main(){
  // SGeometria geo; 
  SCalc calculator;
  calculator.insert(new SQuadrado);
  calculator.insert(new SQuadrado);
  calculator.insert(new SRetangulo);
  calculator.insert(new SRetangulo);

  cout << calculator.areaTotal() << endl;
  return 0;
}