#pragma once
#include "Square.h"

class Parallelepiped : public Square {
	double A;
	double B;
	double C;
public:
	Parallelepiped();
	~Parallelepiped();
	void surfaceArea();
	void changeData();
};