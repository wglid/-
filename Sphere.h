#pragma once
#include "Square.h"

class Sphere : public Square {
	double R;
public:
	Sphere();
	~Sphere();
	void surfaceArea();
	void changeData();
};

