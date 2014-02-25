#include "AtmQ.h"
#pragma once


class Atm
{
public: 
	Atm();
	void createCustomers(int x);			//this should create how many customers come per minutes, x is the max number of
											// custs that arrive in that minute. x is deteremined randomly. 
	
	
	void processCurrentCust();				// reduces what Customer* _atm _timeNeeded by one.
											//but first checks if their current time is 0, if it is, then take him out, 
											// and get the _nextCust()
											// It also checks to see if the lineup isEmpty. if it is empty it wont do anything as far as processing a customer goes. 


	int returnTotalCustPerLine();			// return totalCustPassed thru lineup
	double returnAverageTimeSpentPerCust();	// returns _totalTimeNeeded / _totalCustPassed to calculate average time waiting 4 each Customer
	
	int lengthOfLineUp();					// return how many ppl are in current lineup
	
	
	
private:

	AtmQ* lineup;


};