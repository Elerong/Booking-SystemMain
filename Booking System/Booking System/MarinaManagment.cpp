#include "MarinaManagment.h"
MarinaManagment::MarinaManagment()
{
	marina = 150;
}
float MarinaManagment::getspaceleft() 
{
	return marina;
}
void MarinaManagment::substractspace(float minus) 
{
	marina -= minus;
}