#pragma once
#include "Customer.h"
#include <cstdlib>
#include <list>
#include <iostream>
#include <algorithm>
#include "MarinaManagment.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class LinkedList
{
public:
	LinkedList();
	void AddNode(Customer);
	void DeleteNode(Customer);
	void PrintList();
	void CalculateRemaingSpace();
	float ReturnRemainingSpace();
	int Size();
	void DeleteMatchingInstance(MarinaSpace);
	string FindFirst();
	Customer DeleteCustomer(string, string);
	MarinaSpace ReturnSpace();
private:
	MarinaSpace updatedspaces;
	typedef struct node {
		 Customer customer;
		 node* next;
	}*nodePtr;
	 nodePtr head;
	 nodePtr curr;
	 nodePtr temp;
	 float space;

};
#endif

