#pragma once
#include "och.h"

class Qprotected : protected och
{
public:
	void set(el* head);
	void setNum(int num);
	void process();
};