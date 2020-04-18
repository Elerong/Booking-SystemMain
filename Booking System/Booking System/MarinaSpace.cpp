#include "MarinaSpace.h"
int MarinaSpace::AssignSpace() 
{
	
	int temp = xspace.front();
	xspace.pop_front();
	return temp;

}

void MarinaSpace::createspaces()
{
	int space;
	for (int i = 0;i < 100; i++)
	{
		
		space = i + 1;
		xspace.push_back(space);
		
	}
}
int MarinaSpace::CountSpaces()
{
	return xspace.size();
}
int MarinaSpace::GetSpaceID()
{
	return ID;
}
void MarinaSpace::SetSpaceID(int x)
{
	ID = x;
}