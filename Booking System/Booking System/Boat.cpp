#include "Boat.h"

//All information of a boat are stored here, boat type, length, draft

//When boat is constructed setting values to 0 to prevent unexpected results
Boat::Boat(){
	boatlength = 0;
	draft = 0;
}
/*Another constructor that intakes values, at the moment this constructor is not used but can be implemented
in future development */
Boat::Boat(float newboatlength, float newboatdraft, string newboatname, string newboattype)
{
	boatlength = newboatlength;
	draft = newboatdraft;
	boatname = newboatname;
	boattype = newboattype;
}
//Boat Destructor
Boat::~Boat(){}
//Returns boat type
string Boat::getboattype()
{
	return boattype;
}
//Sets and assigns boat type
void Boat::setboattype(string newboattype)
{
	boattype = newboattype;

	
}
//Returns boat name
string Boat::getboatname()
{
	return boatname;
}
//Assigns boat name
void Boat::setboatname(string newboatname) 
{
	boatname = newboatname;
	

}
//Returns boat length
float Boat::getboatlength() {
	return boatlength;
}
//Assigns boat length
void Boat::setboatlength(float newboatlength)
{
	boatlength = newboatlength;
}
//returns boat draft
float Boat::getboatdraft() 
{
	return draft;
}
//Assigns boat draft
void Boat::setboatdraft(float newdraft)
{
	draft = newdraft;
}