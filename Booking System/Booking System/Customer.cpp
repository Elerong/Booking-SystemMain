#include "Customer.h"
	Customer::Customer()
	{
		Boat boat;
	};
	void Customer::SetCustomerBoat(Boat newboat)
	{
		boat = newboat;
	};
	Boat Customer::GetCustomerBoat()
	{
		return boat;
	};
	void Customer::SetCustomerName(string newName)
	{
		name = newName;
	};

	void Customer::SetID(int x) 
	{
		ID = x;
	}
	int Customer::GetID()
	{
		return ID;
	};
	void Customer::AddTransaction(Transaction newtransaction)
	{
		transaction = newtransaction;
	};
	string Customer::GetCustomerName()
	{
		return name;
	};
	Transaction Customer::GetTransaction()
	{
		return transaction;
	}
	void Customer::SetCustomerLName(string name)
	{
		lname = name;
	}
	string Customer::GetCustomerLName()
	{
		return lname;
	}
	int Customer::GetMarinaSpace()
	{

			return space;
		
		
	
	}
	void Customer::SetMarinaSpace(int newspace)
	{
		space = newspace;
	}
	
