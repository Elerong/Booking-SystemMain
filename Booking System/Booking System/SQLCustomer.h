#pragma once
#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include <string>
using namespace std;
#ifndef SQLCUSTOMER_H
#define SQLCUSTOMER_H
class SQLCustomer
{
public:
	static int createDB(const char* s);
	static int createTable(const char* s);
	string sql;
	int exit;
	string messageError;
	sqlite3* DB;
	
};
#endif

