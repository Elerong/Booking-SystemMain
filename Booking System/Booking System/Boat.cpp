#include "Boat.h"
Boat::Boat(){
	boatlength = 0;
	draft = 0;
}
Boat::Boat(float newboatlength, float newboatdraft, string newboatname, string newboattype)
{
	boatlength = newboatlength;
	draft = newboatdraft;
	boatname = newboatname;
	boattype = newboattype;
}
Boat::~Boat(){}
string Boat::getboattype()
{
	return boattype;
}
void Boat::setboattype(string newboattype)
{
	boattype = newboattype;

	
}
string Boat::getboatname()
{
	return boatname;
}
void Boat::setboatname(string newboatname) 
{
	boatname = newboatname;
	

}
float Boat::getboatlength() {
	return boatlength;
}
void Boat::setboatlength(float newboatlength)
{
	boatlength = newboatlength;
}
float Boat::getboatdraft() 
{
	return draft;
}
void Boat::setboatdraft(float newdraft)
{
	draft = newdraft;
}