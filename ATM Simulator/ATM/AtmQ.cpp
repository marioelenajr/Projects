#include "AtmQ.h"
#include <iostream>
#include "Customer.h"
#include <cstdlib>		
#include <time.h>

using namespace std;

AtmQ :: AtmQ()
{
	_atm = NULL;		
	_custPtr = NULL;
	_numCust = 0;
	_totalCustPassed = 0;		// this is total amount of customers the ATM has processed
	_totalTimeNeededForAtm = 0;
	
}

void AtmQ :: insertCust()
{

	// TEST :
	cout<< "The NUMBER OF CURRENT CUSTOMER(S) IN ATMQ IS: " << _numCust;
	cout << "_________________________________________________________________"<< endl<<endl;
	Customer* temp = new Customer();

	
	// TEST:
	cout << "This is the time _timeNeeded for the customer going in to the Queue: " << temp->returnTimeNeeded()<< endl;

	_totalTimeNeededForAtm += temp->returnTimeNeeded();
	
	// this is pretty much if the AtmQ is empty, put the cust in line 2 start usin atm. 

	if(_numCust == 0)
	{
		//TEST : 
		cout<< "WE HAVE ENTERED THE IF STATEMENT IN insertCust fn." << endl;

		_atm= temp;
		_custPtr = temp;

		//Test:
		cout<< "We have just made _atm = temp, and _custPtr = _atm" << endl<<endl;
		
	}
		
	else
	{
		//TEST: 
		cout<< "We have entered the ELSE statement in insertCust() and setting _custPtr to _atm"<<endl
			<<"to travers the Q. So this says theres customers in lineup" << endl<<endl;
			

		_custPtr = _atm;								// to get _custPtr to traverse the list
		
		//TEST: 
		cout<< "Using while loop Statement to add all the cust _timeNeeded only if theres more than 2 ppl in line" << endl;
		
		while(_custPtr->returnNextCust() != NULL)
			{
				// TEST:
				cout<< " This tells us that there is somebody behind the atm user," <<endl
					<< "now going to add to setTotalTime of temp, and travers list" <<endl;

				temp->setTotalTime(_custPtr->returnTimeNeeded());		// add the _totalWaitTime thats ahead of each cust. 
				_custPtr = _custPtr->returnNextCust();					// go to next customer. 				
			}
			
		// This if statement assures us that if the last person in line, has nobody behind them, to take his _timeNeeded and add it to
		//the temp cust _totalTimeNeeded.

		if(_custPtr->returnNextCust() == NULL)
		{
			temp->setTotalTime(_custPtr->returnTimeNeeded());
			cout<< "Added up the totalWatiTime, the total wait time(s) are : " << temp->returnTotalWaitTime() << endl <<endl;
			temp->setNextCust(_custPtr->returnNextCust());		// takes temp's Customer* _nextCust and sets it to the param _nextCust
			_custPtr->setNextCust(temp);		// now set the last person in lines Customer* _nextCust to that of CUstomer* temp. 
		}
	}


	_numCust++;
	_totalCustPassed++;
}

 
void AtmQ :: custLeaves()
{
	Customer* temp = _atm;
	_atm = _atm->returnNextCust();
	_numCust--;
	delete temp;
}



int AtmQ :: returnTotalCustPassed() const
{
	return _totalCustPassed;
}

int AtmQ :: checkTimeLeft()
{
	return _atm->returnTimeNeeded();
}

void AtmQ :: processCust()
{
	_atm->decreaseTime();
}

bool AtmQ :: isEmpty()
{
	return(_numCust == 0);

}

int AtmQ :: returnLengthOfQ() const
{
	return _numCust;
}

int AtmQ :: returnTotalTimeNeededForAtm() const
{
	return _totalTimeNeededForAtm;
}

AtmQ :: ~AtmQ()
{
}
