#pragma once
#include "Customer.h"
#include <cstdlib>
#include <iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class LinkedList
{
public:
	LinkedList();
	void AddNode(Customer);
	void DeleteNode(Customer);
	void PrintList();
	void PopulateList(Customer);
private:
	typedef struct node {
		 Customer customer;
		 node* next;
	}*nodePtr;
	 nodePtr head;
	 nodePtr curr;
	 nodePtr temp;
	
};
#endif

