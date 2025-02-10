#include <iostream>
#include <vector>

using namespace std;

class SGeometria{
  public:
    virtual float calcArea()=0; // Virtual para poder sobrescrever e acessar da derivada
    virtual SGeometria* alocar() = 0;
    virtual ~SGeometria(){};  // Não pode ser virtual puro
};

class SQuadrado : public SGeometria{
  float lado;
  public:
    SQuadrado(float side = 1.0):lado(side){}

    virtual float calcArea(){
      return lado * lado;
    }

    SGeometria* alocar(){
      return new SQuadrado(this->lado);
    };

    float getLado(){
      return lado;
    }

    void setLado(float side){
      this->lado = side;
    }
};

class SRetangulo : public SGeometria{
  float l1, l2;
  public:
    SRetangulo(float lado1 = 1.0, float lado2 = 1.0) : l1(lado1), l2(lado2){}
    
    virtual float calcArea(){
      return l1 * l2;
    }

    SGeometria* alocar(){
      return new SRetangulo(this->l1, this->l2);
    };

    float getL1(){
      return l1;
    }

    float getL2(){
      return l2;
    }

    void setL1(float lado){
      this->l1 = lado;
    }

    void setL2(float lado){
      this->l2 = lado;
    }

};

class SCalc{
  vector<SGeometria*> geos;
  
  public:
    void insert(SGeometria* sGeo){  // Ponteiro da classe base para receber diferentes tipos de geometria
      geos.push_back(sGeo->alocar());
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

//! So vai mexer aqui pra baixo
class SAppCalcArea{
  vector<SGeometriaApp*> registrosDeGeometrias;
  SCalc calc;

  public:
    void registraGeometria(SGeometriaApp* pGeo){
      registrosDeGeometrias.push_back(pGeo->alocarGeoApp());
    }

    void mainDoApp(){
      unsigned numeroLido;
      vector<SGeometriaApp*>::iterator it;
      unsigned i;

      do{
        cout << "Digite 0 (para sair)";
        for(it = registrosDeGeometrias.begin(), i=1; it != registrosDeGeometrias.end(); it++, i++){
          cout << "," << i << "(para " << (*it)->getNome() << ") ";
        }
        cout << ": ";
        cin >> numeroLido; 
        // TODO: Leitura das geometrias
      }while(numeroLido != 0);

      cout << endl << "Area Total: " << calc.areaTotal() << endl;
    }

    ~SAppCalcArea(){
      vector<SGeometriaApp*>::iterator it; // iterator do tipo da base
      for(it = registrosDeGeometrias.begin(); it != registrosDeGeometrias.end(); it++){
        delete *it;
      }
    }
};

class SGeometriaApp{
  string nome;
  public:
    void setNome(const string &name){
      this->nome = name;
    }

    const string &getNome() const {
      return nome;
    }

    virtual void lerParametroDeGeometria() = 0;

    virtual SGeometriaApp* alocarGeoApp() = 0;
};

class SQuadradoApp : private SQuadrado, public SGeometriaApp{
  public:
    SQuadradoApp(){
      SGeometriaApp::setNome("Quadrado");
    }

    void lerParametroDeGeometria(){
      float lado;
      cout << "\nDigite lado: ";
      cin >> lado;
      setLado(lado);
      cout << endl;
    }

    SGeometriaApp* alocarGeoApp(){
      return new SQuadradoApp;
    };
};

class SRetanguloApp : private SRetangulo, public SGeometriaApp{
  public:
    SRetanguloApp(){
      SGeometriaApp::setNome("Retangulo");
    }

    void lerParametroDeGeometria(){
      float l1, l2;
      cout << "\nDigite lado 1: ";
      cin >> l1;
      cout << "\nDigite lado 2: ";
      cin >> l2;
      setL1(l1);
      setL2(l2);
      cout << endl;
    }

    SGeometriaApp* alocarGeoApp(){
      return new SRetanguloApp;
    };
};

int main(){
  // SGeometria geo; 
  SAppCalcArea app;
  SQuadradoApp q1;
  SRetanguloApp r1;

  app.registraGeometria(&q1);
  app.registraGeometria(&r1);

  app.mainDoApp();

  return 0;
}