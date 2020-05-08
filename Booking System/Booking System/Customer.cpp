#include "Customer.h"



	/*CUSTOMER CLASS
	INFORMATION STORED IN CUSTOMER CLASS:
	- CUSTOMER INFORMATION
	- BOAT OBJECT (with all information)
	- TRANSACTION OBJECT (with all information)
	- CUSTOMER ID*/



	/*Basic constructor*/
	Customer::Customer()
	{
	};
	//Sets boat object to customer.
	void Customer::SetCustomerBoat(Boat newboat)
	{
		boat = newboat;
	};
	//Returns boat object that is stored within customer
	Boat Customer::GetCustomerBoat()
	{
		return boat;
	};
	//Sets customer name
	void Customer::SetCustomerName(string newName)
	{
		name = newName;
	};
	//Sets customer ID 
	void Customer::SetID(int x) 
	{
		ID = x;
	}
	//Gets customer ID
	int Customer::GetID()
	{
		return ID;
	};
	//Assigns the transaction object to customer
	void Customer::AddTransaction(Transaction newtransaction)
	{
		transaction = newtransaction;
	};
	//Gets customer name
	string Customer::GetCustomerName()
	{
		return name;
	};
	//Gets the transaction that is stored inside the customer
	Transaction Customer::GetTransaction()
	{
		return transaction;
	}
	//Sets customer surname/lastname
	void Customer::SetCustomerLName(string name)
	{
		lname = name;
	}
	//returns customer surname/lastname
	string Customer::GetCustomerLName()
	{
		return lname;
	}
	//Returns space in marina to which the customer is allocated to
	int Customer::GetMarinaSpace()
	{
			return space;
	}
	//Sets marina space to which the customer is going to be assigned
	void Customer::SetMarinaSpace(int newspace)
	{
		space = newspace;
	}
	
