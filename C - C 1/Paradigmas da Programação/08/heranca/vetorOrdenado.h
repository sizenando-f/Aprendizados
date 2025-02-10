#ifndef HERANCA_VETORORDENADO_H
#define HERANCA_VETORORDENADO_H

#include <vector>

using namespace std;

class vetorOrdenado : private vector<int>{
  public:
    void insert(int);
    int at(unsigned i);
};

#endif 
