#include "Atm.h"
#include "AtmQ.h"
#include <cstdlib>		
#include <time.h>
#include <iostream>
using namespace std;


Atm :: Atm()
{
	lineup = new AtmQ;
}

void Atm :: createCustomers(int x)
{

	for(int k=0; k < x; k++)
	{
		
		lineup->insertCust();
	}
}


void Atm :: processCurrentCust()
{
	//Test::
	cout << " checking if current lineup isEmpty"<<endl;
	if(lineup->isEmpty()== false)
	{
		if(lineup->checkTimeLeft() == 0)
		{	// TEST::
			cout<<"the line up is NOT emplty, but the current customer is done"<<endl;

			lineup->custLeaves();
			
			//TEST::
			cout<< "Just did 'lineup->custLeaves()' current cust is done, now they left."<<endl;
		}
		
		if(lineup->isEmpty() == false) // going to process the _nextCust, but gonna check if there is one to process.
		{
			//TEST:: 
			cout<< "starting to process the current customer because the lineup->isEmpty is false."<<endl;

			lineup->processCust();
		}
	}

	// TEST: TEST TO SEE IF PROGRAM DOESN'T CRASH IF lineup isEmpty is true.
	else
	{
		cout<< "The line is empty, so ATM will not process Any new customers"<<endl;
	}
}
int Atm :: returnTotalCustPerLine()
{
	return lineup->returnTotalCustPassed();
}

double Atm :: returnAverageTimeSpentPerCust()
{
	return lineup->returnTotalTimeNeededForAtm() / lineup->returnTotalCustPassed();
}


int Atm :: lengthOfLineUp()
{
	return lineup->returnLengthOfQ();
}