#include "Customer.h"
	Customer::Customer()
	{
		ID = 0;
		MakeID();
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
	void Customer::MakeID()
	{
		ID = ID + 1;
	}
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
	
