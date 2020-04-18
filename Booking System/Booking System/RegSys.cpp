#include "RegSys.h"

void RegSys::RegSysStart(LinkedList list, const char* DB, MarinaManagment marina, MarinaSpace space)
{
	
			Start:
	       
			system("CLS");

			Customer newcustomer;
			newcustomer.SetID(list.Size());
			Boat boat;
			string tempname;
			string templname;
			boatlength:
			std::cout << "What is the length of the boat? (in meters)" << endl;
			cin >> length;
			boat.setboatlength(length);
			if (length <= 15 && length > 0 && cin)
			{

				cout << endl;
				cout << "Checking available space.";
				std::chrono::seconds dura(2);
				cout << ".";
				std::this_thread::sleep_for(dura);
				cout << "." << endl;
				std::this_thread::sleep_for(dura);

				if (length > marina.getspaceleft())
				{

					cout << "There is not enough space in Marina to add this booking. Remaining space:" << marina.getspaceleft() << " meters" << " boat length: " << length << endl;
					cin.clear();
				}
				else
				{

					xdraft:
					std::cout << "What is the draft length?" << endl;
					cin >> draft;
					boat.setboatdraft(draft);
					if (boat.getboatdraft() <= 5 && boat.getboatdraft() > 0 && cin)
					{
					xswitch:
						std::cout << "What type of boat is it?" << endl
						<< "1. Narrow" << endl << "2. Sailing" << endl << "3. Motor" << endl << "(4. Cancel Booking)"<< endl << endl;
			

						cin >> option;

						switch (option)
						{
						case 1: {
							newboattype = "Narrow";
							boat.setboattype(newboattype);
							

						}
						case 2:
						{
							newboattype = "Sailing";
							boat.setboattype(newboattype);
							
						}
						case 3: {
							newboattype = "Motor";
							boat.setboattype(newboattype);
							
						}
						case 4: {break; }
						default:
							system("CLS");
							cout << "Incorrect Entry";
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							goto xswitch;

						}

						if (boat.getboattype() == "Motor"
							|| boat.getboattype() == "Sailing"
							|| boat.getboattype() == "Narrow")
						{
							
							system("CLS");
							int temp;
							AfterBoat:
							cout << "How many months does the customer plan to stay in the Marina?" << endl;

							cin >> temp;
						
							Transaction transaction;
							if (cin)
							{



								finalentry:
								int randNum;
								srand(time(0));
								randNum = (rand() % 99999) + 1;

								
								transaction.CalcTransaction(temp, boat.getboatlength(), randNum);
								cout << endl << "To stay at the Marine for: " << temp << " months" << endl << "It will cost total of: " << transaction.gettotalcost() << " GBP";
								cout << " || " << transaction.gettotalcost() / temp << " GBP per month" << endl << endl;

								cout << "1. Accept the Quote" << endl
									<< "2. Reject the quote and try again" << endl
									<< "3. Main Menu" << endl
									<< "4. Exit program"
									<< endl << endl;



							}
							else
							{
								std::cin.clear();
								cout << "Only numbers are allowed" << endl;
								goto AfterBoat;
							}
							
							int selection;
							cin >> selection;
							if (cin)
							{

								switch (selection)
								{
								case 1:
								{
								FirstName:
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
									std::cout << "What is the customer's first name?" << endl;
									getline(cin, tempname);
									newcustomer.SetCustomerName(tempname);
									if (tempname != "")
									{
									LastName:
										cout << "What is customer's last name?" << endl;
										getline(cin, templname);
										newcustomer.SetCustomerLName(templname);
										if (templname != "")
										{
											std::cout << "What is the boat name? " << endl;
											getline(cin, newboatname);
											boat.setboatname(newboatname);
											std::this_thread::sleep_for(dura);
											marina.setspaceleft(boat.getboatlength());
											UpdatedSpace.marina = marina.getspaceleft();
											cout << endl << "Customer " << newcustomer.GetCustomerName() << " "
												<< newcustomer.GetCustomerLName() << " has been successfully booked in." << endl;
											std::this_thread::sleep_for(dura);
											cout << "Time of Check in: " << transaction.NowTimeDate() << endl;
											transaction.SetTimeLeft(temp);
											std::this_thread::sleep_for(dura);
											cout << "Time until checkout: " << transaction.GetTimeLeft() << endl << endl;
											newcustomer.SetMarinaSpace(space.AssignSpace());
											newcustomer.SetCustomerBoat(boat);
											newcustomer.AddTransaction(transaction);
											SQLCon::insertData(DB, newcustomer);
											list.AddNode(newcustomer);
											string temp = list.FindFirst();
											cout << endl;
											cout << "Please Wait.";
											std::this_thread::sleep_for(dura);
											cout << ".";
											std::this_thread::sleep_for(dura);
											cout << "." << endl << endl;
											std::this_thread::sleep_for(dura);

											if (newcustomer.GetMarinaSpace() != 1)
											{
												system("CLS");
												cout << "Please wait." << endl;
												cout << "Entering Marina:      Leaving Marina:        Waiting: " << endl;
												cout << "                                            " << newcustomer.GetCustomerLName() << " || " << newcustomer.GetCustomerBoat().getboatname() << " (" << newcustomer.GetMarinaSpace() << ")" << endl;
												cout << "                                            " << temp << endl;
												std::this_thread::sleep_for(dura);

												system("CLS");
												cout << "Please wait.." << endl;
												cout << "Entering Marina:      Leaving Marina:        Waiting: " << endl;
												cout << "                                            " << newcustomer.GetCustomerLName() << " || " << newcustomer.GetCustomerBoat().getboatname() << " (" << newcustomer.GetMarinaSpace() << ")" << endl;
												cout << "	              " << temp << endl;
												std::this_thread::sleep_for(dura);

												system("CLS");
												cout << "Please wait..." << endl;
												cout << "Entering Marina:      Leaving Marina:        Waiting: " << endl;
												cout << "                                            " << newcustomer.GetCustomerLName() << " || " << newcustomer.GetCustomerBoat().getboatname() << " (" << newcustomer.GetMarinaSpace() << ")" << endl;
												cout << "                                            " << temp << endl;
												std::this_thread::sleep_for(dura);

												system("CLS");
												cout << "Please wait." << endl;
												cout << "Entering Marina:      Leaving Marina:        Waiting: " << endl;
												cout << newcustomer.GetCustomerLName() << " || " << newcustomer.GetCustomerBoat().getboatname() << " (" << newcustomer.GetMarinaSpace() << ")" << endl;
												cout << "                                            " << temp << endl;
											}
											std::this_thread::sleep_for(dura);
											system("CLS");
											cout << "Please wait.." << endl;
											cout << "Entering Marina:      Leaving Marina:        Waiting: " << endl;
											cout << "                                            " << temp << endl;
											std::this_thread::sleep_for(dura);

											system("CLS");
											cout << "Please wait..." << endl;
											cout << "Entering Marina:      Leaving Marina:        Waiting: " << endl;
											cout << temp << endl << endl;
											std::this_thread::sleep_for(dura);
											std::this_thread::sleep_for(dura);
											cout << "Booking Confirmed!" << endl << "Loading Main Menu..." << endl;
											std::this_thread::sleep_for(dura);
											system("CLS");


											break;

										}
										else
										{
											system("CLS");
											cout << "Incorrect input was given, numbers are not allowed." << endl << "Please try again." << endl << endl;
											std::cin.clear();
											std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
											goto LastName;
										}
									}
									else
									{
										system("CLS");
										cout << "Incorrect input was given, numbers are not allowed." << endl << "Please try again." << endl << endl;
										std::cin.clear();
										std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
										goto FirstName;
									}
								}
								case 2:
								{
									goto Start;
								}
								case 3:
								{
									break;
								}
								case 4:
								{
									system("Exit");
								}
								}
							}
							else
							 {
							
							 cout << "Incorrect Entry, please try again" << endl;
							 cin.clear();
							 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							 goto finalentry;
							}

						}
					}
					else
					{
					system("CLS");
					std::cout << "Sorry, the boat draft needs to be less than 5 meters." << endl;
					std::cout << "Please try again, only numbers are allowed in this field." << endl << endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					goto xdraft;
					}
				}
			



				

		
			}
			else
			 {
			 system("CLS");
			 cout << "Incorrect input was given, ONLY numbers are allowed."
			 << endl << "Please try again." << endl << endl;
			 std::cin.clear();
			 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			 goto boatlength;

			}

}


RegSys::~RegSys()
{
}
MarinaManagment RegSys::ReturnUpdatedSpace()
{
	return UpdatedSpace;
}
void RegSys::SetRamainingUpdatedSpace(int x)
{
	UpdatedSpace.marina = x;
}
RegSys::RegSys()
{

}
