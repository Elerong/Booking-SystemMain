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
	int ID;
	string name;
	string lname;
	//to add transaction
	Boat boat;
	Transaction transaction;
	int space;
	



};
#endif


