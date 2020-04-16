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
		if(delPtr == head)
		{
			head = head->next;
			temp = NULL;
		}
	}

}
void LinkedList::PrintList()
{
	curr = head;
	while (curr != NULL)
	{
		cout << curr->customer.GetID() << ", " << curr->customer.GetCustomerName() << ", " << endl << "Time Left: " << curr->customer.GetTransaction().GetTimeLeft()
			<< endl << "Booking total: " << curr->customer.GetTransaction().gettotalcost() << " GBP" << endl;
		curr = curr->next;
	}

}void LinkedList::PopulateList(Customer c)
{
	AddNode(c);
}