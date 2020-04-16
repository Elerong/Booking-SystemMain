#pragma once
//DECLARE FUNCTIONS
#include <iostream>
#include "LinkedList.h"
#include "SQLCon.h"
#include <string>
#include "Boat.h"
#include "Customer.h"
#include <locale>

using namespace std;
#ifndef REGSYS_H
#define REGSYS_H
class RegSys
{
public:


	//overload constructor
	LinkedList RegSysStart(LinkedList,const char* DB);
	//Destructor
	~RegSys();
	void PassOnRemainingSpace(float);
private:
	

	string name;
	//member variables
	Customer customer;
	float length;
	float draft;
	int option;
	string newboattype;
	string newboatname;
	float price;
	int months;
	float marina;


};

#endif

