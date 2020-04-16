#include "Transaction.h"
#define _CRT_SECURE_NO_WARNINGS

Transaction::Transaction(){}
void Transaction::CalcTransaction(int months, float length)
{
	cost = length * 10 * months;
    ID += 1;
}
int Transaction::gettransactionID()
{
	return ID;
}
void Transaction::SetTransactionID(int x)
{
    ID = x;
}
void Transaction::MakeTransactionID()
{
	ID += 1;
}
string Transaction::NowTimeDate() 
{
    time_t rawtime;
    struct tm* timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);
    std::string str(buffer);
    NowTime = str;
    return str;
 
}
void Transaction::SetTimeLeft(int months)
{
    time_t currentime = time(0);
    tm* ltm = localtime(&currentime);
    int year = 1900 + ltm->tm_year;
    int month = months + 1 +  ltm->tm_mon;
    int day = ltm->tm_mday;
    TimeLeft = std::to_string(day) + "-" + std::to_string(month) + "-" + std::to_string(year);
}
float Transaction::gettotalcost()
{
    return cost;

}
Transaction::~Transaction() 
{
}
string Transaction::GetTimeLeft() 
{
    return TimeLeft;
}
string Transaction::BookingTime() 
{
    return NowTime;
}
void Transaction::ReCallTimeLeft(string x)
{
    TimeLeft = x;
}
void Transaction::ReCallBookingTime(string x)
{
    NowTime = x;
}
void Transaction::ReCallTotalCost(float x)
{
    cost = x;
}