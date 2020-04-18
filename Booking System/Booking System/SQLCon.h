#pragma once
#include <iostream>
#include <cstdlib>
#include <sqlite3.h>
#include <stdio.h>
#include <list>
#include "Customer.h"
#include "MarinaManagment.h"
#include "LinkedList.h"

#ifndef SQLCON_H
#define SQLCON_H
using namespace std;
class SQLCon
{
	
	public:
	
	static int createDB(const char* s);
	static int createTable(const char* s);
	static int insertData(const char* s, Customer);
	static int selectData(const char* s);
    static int callback(void* NotUsed, int argc, char** argv, char** azColName);
	static inline list<Customer> c_List;
	static inline LinkedList xlist;
	static int deletedata(const char* s, string, string, string);
private:
	
};

#endif