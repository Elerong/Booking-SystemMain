#pragma once
//DECLARE FUNCTIONS
#include <iostream>
#include <string>
#include "Boat.h"
#include "Transaction.h"
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
	string GetCustomerName();
	void MakeID();
	void SetID(int);
	int GetID();
	void AddTransaction(Transaction);
	Transaction GetTransaction();
private:
	int ID;
	string name;
	//to add transaction
	Boat boat;
	Transaction transaction;
	



};
#endif


