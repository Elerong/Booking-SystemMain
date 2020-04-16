#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
using namespace std;
class Transaction
{
public:
	Transaction();
	void CalcTransaction(int, float);
	int gettransactionID();
	void MakeTransactionID();
	void SetTransactionID(int);
	string NowTimeDate();
	void SetTimeLeft(int);
	float gettotalcost();
	~Transaction();
	void ReCallTimeLeft(string);
	void ReCallBookingTime(string);
	string GetTimeLeft();
	string BookingTime();
	void ReCallTotalCost(float);
	
private:
	int ID=0;
	float cost;
	string NowTime;
	string TimeLeft;
};

