#include "Transaction.h"
#define _CRT_SECURE_NO_WARNINGS

Transaction::Transaction(){}
void Transaction::CalcTransaction(int months, float length, int x)
{
	cost = length * 10 * months;
    ID = x;
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
void Transaction::SetTimeLeft(int xmonths)
{
    
    
    using std::chrono::system_clock;

    using days = std::chrono::duration
    <int, std::ratio_multiply<std::ratio<24>, std::chrono::hours::period>>;
    using years = std::chrono::duration
    <int, std::ratio_multiply<std::ratio<146097, 400>, days::period>>;
    using months = std::chrono::duration
    <int, std::ratio_divide<years::period, std::ratio<12>>>;
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now() + months{ xmonths };
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_c);
    char buffer[80];
    strftime(buffer,80, "%d-%m-%Y", &now_tm);
      
    TimeLeft = buffer;
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