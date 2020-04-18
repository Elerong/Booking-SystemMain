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
#include "MarinaSpace.h"
using namespace std;

int main()
{

	MarinaManagment marina;
	MarinaSpace space;
	int selection;
	RegSys regsys;
	const char* c = "..\\Booking System\\DataBase.db";

	//creates spaces
	space.createspaces();
	//creates database




	
	//marinaspace

	SQLCon sqlcon;
	sqlcon.createDB(c);
	sqlcon.createTable(c);


Menu:
	cout << endl;
	sqlcon.selectData(c);
	sqlcon.xlist.CalculateRemaingSpace();
	marina.setspaceleft(sqlcon.xlist.ReturnRemainingSpace());
	sqlcon.xlist.DeleteMatchingInstance(space);
	space = sqlcon.xlist.ReturnSpace();




	cout << "MARINA SPACE " << marina.getspaceleft() << endl;



	//sends remaining space to registration system
		std::cout << "1. Create a New Booking" << endl
			<< "2. View Bookings" << endl
			<< "3. Delete Existing Booking" << endl
			<< "5. Exit" << endl;
		std::cout << "Make a Selection: ";
		//Ask for input

		cin >> selection;
		//Check the selection

			switch (selection)
			{
			case 1: {
				regsys.RegSysStart(sqlcon.xlist, c, marina, space);
				break; } //Create Booking
			case 2: {
				cout << endl << endl;
				sqlcon.xlist.PrintList();
				system("Pause");
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
				 } //View Booking
			case 3: {
				if (sqlcon.xlist.Size() != 0)
				{
					string tmplname;
					string tempname;
					string tmpboatname;
					system("CLS");
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "What is the customer's first name" << endl;
					getline(cin, tempname);
					cout << "What is the customer's surname?" << endl;
					getline(cin, tmplname);
					cout << "What is the boat name?" << endl;
					getline(cin, tmpboatname);
					/*sqlcon.deletedata(c, sqlcon.xlist.DeleteCustomer(tmplname, tmpboatname));*/
					sqlcon.deletedata(c, tmplname, tmpboatname, tempname);
					break;
				}
				else
				{
					cout << "Database is empty." << endl << "No data to view." << endl;
				}
				goto Menu;
				} //Edit Booking
			case 4: {
				system("CLS"); break; } //Get a Quote
			case 5: {system("exit"); //Close the program 
				break; }
				  //Any input other than from the list = Display error message
			default: {std::cout << "Incorrect Entry!" << endl << "Please try again." << endl << endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


			}
			}
		

		goto Menu;
	system("pause");
	return 0;

}






