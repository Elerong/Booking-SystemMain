#pragma once
//DECLARE FUNCTIONS
#include <iostream>
#include <string>
using namespace std;
#ifndef BOAT_H
#define BOAT_H
class Boat
{
public:
	
	//ALL OF THE FUNCTIONALITY IS EXPLAINED IN .CPP FILES

	//default constructor
	Boat();
	//overload constructor
	Boat(float, float, string, string);
	//destructor
	~Boat();
	//accessor
	float getboatlength();

	void setboatlength(float);
	
	float getboatdraft();

	void setboatdraft(float);
	
	string getboattype();

	void setboattype(string);

	string getboatname();

	void setboatname(string);
	
private:
	//MEMBER VARIABLES USED FOR STORING BOAT DATAS
	float boatlength;
	float draft;
	string boattype;
	string boatname;
};
#endif
