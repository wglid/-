#pragma once

class Dimensions {
	int height;
	int width;
	int depth;
public:
	Dimensions() {};
	Dimensions(int height, int width, int depth);
	Dimensions(const Dimensions& other);
	int maxValue();
	int minValue();
	void show();

	friend Dimensions& operator++(Dimensions& ob);
	friend Dimensions operator--(Dimensions& ob, int);

	Dimensions operator++(int);
	Dimensions& operator--();
};