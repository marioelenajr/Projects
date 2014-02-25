#include "Customer.h"
#pragma once


class AtmQ
{
public:
	AtmQ();				// initializes pointers and the private variables

	void insertCust();	// creates a new Customer* temp . uses a if statement to check if the lineup is empty.
						//if not , then it'll traverse the Queue and add the _timeNeeded of each customer in line up
						// then it'll put the temp customer in back of lineup.
					
	void custLeaves(); //This takes the Customer* _atm and sets it to _nextCust, and deletes temp because he is done.



	int returnTotalCustPassed() const;	// required to calculate average # of customers gone thru line up. 
	int checkTimeLeft();				// check _timeNeeded for Customer* _atm 
	void processCust();					// decreases _timeNeeded by one each time its called. 
	bool isEmpty();						// checks to see if _numCust is 0, and returns true if it is. 
	int returnLengthOfQ() const;
	int returnTotalTimeNeededForAtm() const;

	~AtmQ();

private:
	Customer *_atm;	
	int _numCust;			// number of customers in current line
	Customer *_custPtr;
	int _totalCustPassed;			// total customer objects that passed through AtmQ* lineup
	int _totalTimeNeededForAtm;		// totals of all _timeNeeded custs that passed thru AtmQ* lineup
};
