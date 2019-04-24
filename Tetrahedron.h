#pragma once
#include "Square.h"

class Tetrahedron : public Square {
	double A;
public:
	Tetrahedron();
	~Tetrahedron();
	void surfaceArea();
	void changeData();
};