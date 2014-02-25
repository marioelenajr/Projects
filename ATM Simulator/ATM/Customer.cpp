#include <iostream>
#include "Customer.h"
using namespace std;
#include <cstdlib>		
#include <time.h>




Customer :: Customer()		
{
	srand ( time(NULL) );			// this creates a random number.. sometimes...  i got this from www.cplusplus.com
	_timeNeeded = (rand()%5+1);
	
	
	_totalWaitTime = _timeNeeded;
	_nextCust = NULL;
}

 
void Customer :: setNextCust(Customer* next)
{
	_nextCust = next;
}

void Customer :: decreaseTime()
{
	//TEST:
	cout<<"Decreasing time of customer, which is now : ";

	_timeNeeded--;
	
	//TEST::
	cout<< _timeNeeded <<endl<<endl;
}


void Customer :: setTotalTime(int time)
{
	_totalWaitTime += time;
}

int Customer :: returnTimeNeeded() const
{
	return _timeNeeded;
}


// this returns whomever is benind the person in line

Customer* Customer :: returnNextCust() const
{
	return _nextCust;		
}

int Customer :: returnTotalWaitTime() const
{ 
	return _totalWaitTime;
}

//is this ever used?
void Customer :: setTimeNeeded(int x)
{
	_timeNeeded = x;
}