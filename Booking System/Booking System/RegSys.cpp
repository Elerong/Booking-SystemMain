#include "RegSys.h"

LinkedList RegSys::RegSysStart(LinkedList list, const char* DB)
{

	

		

			system("CLS");
			Customer newcustomer;
			Boat boat;
			std::cout << "What is the length of the boat? (in meters)" << endl;
			cin >> length;
			boat.setboatlength(length);
			if (length < 15)
			{
				cout << "Checking available space..." << endl;
				if (length > marina)
				{
					
					cout << "There is not enough space in Marina to add this booking. Remaining space:" << marina << " meters" << " boat length: " << length << endl;
				}
				else
				{
					std::cout << "What is the boat name? " << endl;
					cin >> newboatname;
					boat.setboatname(newboatname);
					std::cout << "What is the draft length?" << endl;
					cin >> draft;
					boat.setboatdraft(draft);
					if (boat.getboatdraft() < 5 && boat.getboatdraft() > 0)
					{
						std::cout << "What type of boat is it?" << endl
							<< "1. Narrow" << endl << "2. Sailing" << endl << "3. Motor" << endl << "(4. Cancel booking)" << endl;
						cin >> option;
						cout << endl;
						switch (option)
						{
						case 1: {
							newboattype = "Narrow";
							boat.setboattype(newboattype);
							break;
						}
						case 2:
						{
							newboattype = "Sailing";
							boat.setboattype(newboattype);
							break;
						}
						case 3: {
							newboattype = "Motor";
							boat.setboattype(newboattype);
							newcustomer.SetCustomerBoat(boat);
						

							
						}
						case 4:
						{
						
							
						}
						default:
						{

						}
						}
						if (newcustomer.GetCustomerBoat().getboattype() == "Motor"
							|| newcustomer.GetCustomerBoat().getboattype() == "Sailing"
							|| newcustomer.GetCustomerBoat().getboattype() == "Narrow")
						{
							

							int temp;
							cout << "How many months does the customer plan to stay in the Marina?" << endl;
							cin >> temp;
							Transaction transaction;
							transaction.CalcTransaction(temp, newcustomer.GetCustomerBoat().getboatlength());
							cout << "To stay at the Marine for: " << temp << " months, will cost total:" << transaction.gettotalcost() << " GBP" << endl;
							cout << transaction.gettotalcost() / temp << " GBP per month" << endl;
							transaction.SetTimeLeft(temp);
							cout << "Time of Check in: " << transaction.NowTimeDate() << endl;
							cout << "Time until checkout: " << transaction.GetTimeLeft() << endl;
							newcustomer.AddTransaction(transaction);
							SQLCon::insertData(DB, newcustomer);
							return list;
							system("Pause");
						

						}
						else
						{
							cout << "Error has occured, returning to main menu.";
						}
					}
					else
					{
						std::cout << "Sorry the boat draft needs to be less than 5 meters." << endl;
					}
				}
			}
			else
			{
				cout << "Boat length is exceedes maximum length" << endl << "Booking Process Cancelled" << endl << endl;
			

			}

	

	
	
}

RegSys::~RegSys()
{
}
void RegSys::PassOnRemainingSpace(float space)
{
	marina = space;
}
