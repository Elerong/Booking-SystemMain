#pragma once
//DECLARE FUNCTIONS
#include <iostream>
#include "LinkedList.h"
#include "SQLCon.h"
#include <string>
#include "Boat.h"
#include "Customer.h"
#include <ctype.h>
#include <locale>
#include <algorithm>
#include <chrono>
#include <thread>
#include <cctype>
#include <random>
#include "MarinaSpace.h"

using namespace std;
#ifndef REGSYS_H
#define REGSYS_H
class RegSys
{

public:
	RegSys();

	//overload constructor
	void RegSysStart(LinkedList,const char* DB, MarinaManagment, MarinaSpace);
	//Destructor
	~RegSys();
	MarinaManagment ReturnUpdatedSpace();
	void SetRamainingUpdatedSpace(int);
private:
	

	//member variables

	float length;
	float draft;
	int option;
	string newboattype;
	string newboatname;
	LinkedList xlist;
	MarinaManagment UpdatedSpace;


};

#endif

