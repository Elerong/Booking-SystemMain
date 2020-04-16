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
	float boatlength;
	float draft;
	string boattype;
	string boatname;
};
#endif
