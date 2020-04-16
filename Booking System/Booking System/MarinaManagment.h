#pragma once
#include "LinkedList.h"
class MarinaManagment
{
public:
	MarinaManagment();
	float getspaceleft();
	void substractspace(float);
private:
	float marina;
	LinkedList list;
};

