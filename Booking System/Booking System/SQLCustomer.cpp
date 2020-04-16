#include "SQLCustomer.h"
static int createDB(const char* s)
{
	sqlite3* DB;
	int exit = 0;
	exit = sqlite3_open(s, &DB);
	sqlite3_close(DB);
	
	return 0;

}
static int createTable(const char* s)
{
	sqlite3* DB;
	string sql = "CREATE TABLE IF NOT EXISTS GRADES("
		"ID INTEGER PRIMARY KEY,  "
		"NAME      TEXT NOT NULL,);";
		//"AGE       INT NOT NULL,  "
		//"BOAT-NAME  CHAR(50),     "
		//"BOAT-TYPE  CHAR(50),"
		//"EXPIRY     CHAR(50),"
		//"COST       FLOAT(5),"
		//"BOOKING-DATE CHAR(50);";
	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);

		char* messageError;
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error Create Table" << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table Created Successfully" << endl;
		sqlite3_close(DB);
		
	}
	catch (const exception& e)
	{
		cerr << e.what();

	}
}
