// Booking System.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cstdlib>
#include <direct.h>
#include "RegSys.h"
#include "SQLCon.h"

#include <string>
#include "Customer.h"
#include <filesystem>
#include "MarinaManagment.h"
#include "LinkedList.h"

using namespace std;

int main()
{
	const char* c = "..\\Booking System\\DataBase.db";
	LinkedList list;
	SQLCon sqlcon;
	MarinaManagment marina;
	sqlcon.createDB(c);
	sqlcon.createTable(c);
	//to add read data
	sqlcon.selectData(c);
	
	


	
	
	
	int selection = 0;
	RegSys regsys;
	//sends remaining space to registration system
	regsys.PassOnRemainingSpace(marina.getspaceleft());
	do {
		std::cout << "1. Create a New Booking" << endl
			<< "2. View Bookings" << endl
			<< "3. Edit Existing Booking" << endl
			<< "4. Get a Quote" << endl
			<< "5. Exit" << endl;
		std::cout << "Make a Selection: ";
		//Ask for input
		std::cin >> selection;
		//Check the selection
		switch (selection)
		{
		case 1: {
			regsys.RegSysStart(list, c);
			selection = 0;
			break; } //Create Booking
		case 2: {
			system("CLS");

			list.PrintList();
			
				
			break; } //View Booking
		case 3: {
			system("CLS"); break; } //Edit Booking
		case 4: {
			system("CLS"); break; } //Get a Quote
		case 5: {system("exit"); //Close the program 
			break; }
			  //Any input other than from the list = Display error message
		default: {std::cout << "Incorrect Entry!" << endl << "Please try again." << endl << endl;
			selection = 0; }
		}
	} while (selection == 0);
	
	system("pause");
	return 0;

}






