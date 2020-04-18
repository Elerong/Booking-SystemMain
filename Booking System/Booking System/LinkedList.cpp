#include "LinkedList.h"
LinkedList::LinkedList() 
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}
void LinkedList::AddNode(Customer addCustomer)
{
	nodePtr n = new node;
	n->next = NULL;
	n->customer = addCustomer;
	if (head != NULL)
	{
		curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = n;
	}
	else
	{
		head = n;
	}
}
void LinkedList::DeleteNode(Customer delData)
{ 
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;
	while (curr != NULL && curr->customer.GetID() != delData.GetID())
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		cout << delData.GetID() << "data could not be found in the list" << endl;
	}
	else
	{
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		delete delPtr;
cout << "The value" << delData.GetID() << ", " << delData.GetCustomerName() << " was deleted" << endl;
if (delPtr == head)
{
	head = head->next;
	temp = NULL;
}
	}

}
void LinkedList::PrintList()
{
	int sum = 0;
	int months = 0;
	int space = 150;
	
	curr = head;
	while (curr != nullptr)
	{

		cout << "Customer ID: " << curr->customer.GetID() << endl
			<< "SPACE: " << curr->customer.GetMarinaSpace() << endl
			<< "Customer Name: " << curr->customer.GetCustomerName() << " " << curr->customer.GetCustomerLName() << endl
			<< "Transaction ID: " << curr->customer.GetTransaction().gettransactionID() << endl
			<< "Boat Name: " << curr->customer.GetCustomerBoat().getboatname() << endl
			<< "Boat Length: " << curr->customer.GetCustomerBoat().getboatlength() << endl
			<< "Booking Expiry: " << curr->customer.GetTransaction().GetTimeLeft() << endl
			<< "Booking Price: " << curr->customer.GetTransaction().gettotalcost() << " GBP" << endl;
		cout << "_________________" << endl << endl;
		sum += curr->customer.GetTransaction().gettotalcost();
		space -= curr->customer.GetCustomerBoat().getboatlength();

		curr = curr->next;
		
	
	}
	cout << "Total earnings from all bookings: " << sum << " GBP" << endl;
	cout << "_________________" << endl << endl;
	cout << "Marina space left: " << space << " meters" << endl << endl;
	
}
void LinkedList::CalculateRemaingSpace()
{

	int space = 150;

	curr = head;
	while (curr != nullptr)
	{

		space -= curr->customer.GetCustomerBoat().getboatlength();

		curr = curr->next;


	}
	this->space = space;

}
float LinkedList::ReturnRemainingSpace()
{
	return space;
}
int LinkedList::Size()
{
	int size = 0;
	curr = head;
	while (curr != NULL)
	{
		size++;
		curr = curr->next;
	}

	return size;
}
void LinkedList::DeleteMatchingInstance(MarinaSpace x)
{
	curr = head;
	while (curr != NULL)
	{
		x.xspace.remove(curr->customer.GetMarinaSpace());
		curr = curr->next;


	}

	updatedspaces = x;
}

MarinaSpace LinkedList::ReturnSpace()
{
	return updatedspaces;
}
string LinkedList::FindFirst()
{
	curr = head;
	string tmp;

	while (curr != NULL)
	{
		if (curr->customer.GetMarinaSpace() == 1)
		{
			tmp = curr->customer.GetCustomerLName() + " || " + curr->customer.GetCustomerBoat().getboatname() + " (1)";
			break;
		}

		curr = curr->next;
	}

	return tmp;
}

Customer LinkedList::DeleteCustomer(string lname, string boatname)
{
	string currdata;
	string currdata2;
	string inputdata;
	string inputdata2;
	inputdata = lname;	
	inputdata2 = boatname;
	std::for_each(inputdata.begin(), inputdata.end(), [](char& c) {
		c = ::toupper(c);
	});
	inputdata2 = boatname;
	std::for_each(inputdata2.begin(), inputdata2.end(), [](char& c) {
		c = ::toupper(c);
	});
	curr = head;
	while (curr != NULL)
	{
		currdata = curr->customer.GetCustomerLName();
		std::for_each(currdata.begin(), currdata.end(), [](char& c) {
			c = ::toupper(c);
		});
		currdata2 = curr->customer.GetCustomerBoat().getboatname();
		std::for_each(currdata2.begin(), currdata2.end(), [](char& c) {
			c = ::toupper(c);
		});

	 if (currdata == inputdata && currdata2 == inputdata2)
	 {
		 Customer tmp;
		 tmp = curr->customer;
		 return tmp;
	 }
	 curr = curr->next;
	}
}