#pragma once

#include "Formas.h"
#include <vector>

using namespace std;

class Calc
{
	vector<Formas*> formas;
public:
	void insert(Formas* forma);
	float areaTotal() const;
	~Calc();
};

