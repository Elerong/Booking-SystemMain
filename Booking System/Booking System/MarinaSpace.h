#pragma once

#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <list>
using namespace std;

class MarinaSpace
{

public:
	void createspaces();

	int GetSpaceID();
	int CountSpaces();
	void SetSpaceID(int);
	int AssignSpace();
	list<int> xspace;

	int ID;
private:

	
};
