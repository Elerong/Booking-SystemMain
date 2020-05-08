#pragma once
//DECLARE FUNCTIONS
#include <iostream>
#include <string>
#include "Boat.h"
#include "Transaction.h"
#include "MarinaSpace.h"
using namespace std;
#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer
{

	//ALL OF THE FUNCTIONALITY IS EXPLAINED IN .CPP FILES
public:
	Customer();
	void SetCustomerBoat(Boat);
	Boat GetCustomerBoat();
	void SetCustomerName(string);
	void SetCustomerLName(string);
	string GetCustomerLName();
	string GetCustomerName();
	void SetID(int);
	int GetID();
	void AddTransaction(Transaction);
	Transaction GetTransaction();
	int GetMarinaSpace();
	void SetMarinaSpace(int);
private:
	//STORES CUSTOMER DETAILS
	int ID;
	string name;
	string lname;
	//OBJECTS THAT ARE HELD WITHIN CUSTOMER WITH DATA
	Boat boat;
	Transaction transaction;
	int space;
	



};
#endif


