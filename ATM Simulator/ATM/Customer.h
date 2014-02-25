#pragma once
// the is more like a customer Node. It can contain data and pointer to a customer.
class Customer
{
public:
	Customer();			// create a random _timeNeeded for the customer.

	//setters:
	void setNextCust(Customer* next);		// set the ptr to the parameter.
	//void setCustTime();
	void decreaseTime();					// decrease Customers time by one.
	void setTotalTime(int time);			
	void setTimeNeeded(int x);


	// getters:
	int returnTimeNeeded() const;		// returns the time they have left to use atm
	Customer* returnNextCust() const;
	int returnTotalWaitTime() const;



private:
	// all my global variables will be labled  _name;

	Customer* _nextCust;			// this is a ptr to the whomever is behind the customer.  
	int _totalWaitTime;			// this is total time the cust has been waiting in line 
	int _timeNeeded;			// this is the time needed by customer to use ATM 
};
