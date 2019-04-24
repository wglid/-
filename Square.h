#pragma once

class Square {
public:
	virtual ~Square() {};
	virtual void surfaceArea() = 0;
	virtual void changeData() = 0;
};