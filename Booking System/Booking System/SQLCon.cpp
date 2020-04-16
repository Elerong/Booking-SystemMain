#include "SQLCon.h"



int SQLCon::createDB(const char* s)
{
	sqlite3* DB;
	int exit = 0;
	exit = sqlite3_open(s, &DB);
	sqlite3_close(DB);
	return 0;
}
int SQLCon::createTable(const char* s)
{
	sqlite3* DB;

	string sql =
		"CREATE TABLE IF NOT EXISTS CUSTOMERS("
		"ID INTEGER PRIMARY KEY NOT NULL, "
		"NAME       CHAR(30),"
		"BOAT_NAME     CHAR(50),"
		"BOAT_TYPE     CHAR(50), "
		"BOAT_LENGTH      FLOAT(10,2),"
		"BOAT_DRAFT       FLOAT(10,2),"
		"BOOKING_EXPIRY CHAR(50),"
		"BOOKING_DATE  CHAR(50),"
		"TRANS_ID   INTEGER(6),"
		"COST       FLOAT(10));";
	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);
		char* messageError;
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK)
		{
			cerr << "Error Creating Table" << endl;
			sqlite3_free(messageError);
		}
		else {
			cout << "System Loaded..." << endl;
		}
		sqlite3_close(DB);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}
	return 0;
}
int SQLCon::insertData(const char* s, Customer customer)
{
	sqlite3* DB;
	char* messageError;
	int exit = sqlite3_open(s, &DB);
	

	std::string sql = "INSERT INTO CUSTOMERS (ID, NAME, BOAT_NAME, BOAT_TYPE, BOAT_LENGTH, BOAT_DRAFT, BOOKING_EXPIRY, BOOKING_DATE, TRANS_ID, COST) VALUES('"
		+ std::to_string(customer.GetID()) + 
		"', '" + customer.GetCustomerName() + "', '"
		+ customer.GetCustomerBoat().getboatname() + "', '"
		+ customer.GetCustomerBoat().getboattype() + "', '"
		+ std::to_string(customer.GetCustomerBoat().getboatlength()) + "', '"
		+ std::to_string(customer.GetCustomerBoat().getboatdraft()) + "', '"
		+ customer.GetTransaction().GetTimeLeft() + "', '"
		+ customer.GetTransaction().NowTimeDate() + "', '"  
		+ std::to_string(customer.GetTransaction().gettransactionID()) + "', '"
		+ std::to_string(customer.GetTransaction().gettotalcost()) + "');";
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK)
	{
		cerr << "Error Insert" << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records added Successfully!" << endl;

		return 0;
}
int SQLCon::selectData(const char* s)
{
	
	//Selects all customers
	sqlite3* DB;
	int exit = sqlite3_open(s, &DB);
	string sql = "SELECT * FROM CUSTOMERS";
	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
	
	return 0;
}
int SQLCon::callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	
	Customer c;
	Boat b;
	Transaction t;

	
	//Prints all customer data
		c.SetID(std::stoi(argv[0]));
		c.SetCustomerName(argv[1]);
		b.setboatname(argv[2]);
		b.setboattype(argv[3]);
		b.setboatlength(std::stof(argv[4]));
		b.setboatdraft(std::stof(argv[5]));
		t.ReCallTimeLeft(argv[6]);
		t.ReCallBookingTime(argv[7]);
		t.SetTransactionID(std::stoi(argv[8]));
		t.ReCallTotalCost(std::stof(argv[9]));
		
		
		
		c.SetCustomerBoat(b);
		c.AddTransaction(t);
		c_List.push_back(c);
		
	//cout << "ID: " << c.GetID() << endl;
	//cout << "Name: " << c.GetCustomerName() << endl;
	//cout << "Boat Name: " << c.GetCustomerBoat().getboatname() << endl;
	//cout << "Boat Type: " << c.GetCustomerBoat().getboattype() << endl;
	//cout << "Boat Length: " << c.GetCustomerBoat().getboatlength() << endl;
	//cout << "Boat Draft: " << c.GetCustomerBoat().getboatdraft() << endl;
	//cout << "Time Left: " << c.GetTransaction().GetTimeLeft() << endl;
	//cout << "Booking Time: " << c.GetTransaction().BookingTime() << endl;
	//cout << "Transaction: " << c.GetTransaction().gettransactionID() << endl;
	//cout << "Total Cost:" << c.GetTransaction().gettotalcost() << endl;
	cout << endl;
	return 0;
	
}




