#include <iostream>
#include "Atm.h"
#include "AtmQ.h"
#include "runAtm.h"
using namespace std;
#include <cstdlib>
#include <ctime> 


///////////////////////////
/// it is assumed... within a minute.. if A customer comes to use the ATM, and requires only one minute, they will be removed
/// at the start time 0 of the next minute. If another customer uses the ATM at next mintue, the previous custoemr
/// will be delted at start of next minute, and the new customer will move forward and their _totalTimeNeeded will 
/// be decreased.

// ALSO THIS PROGRAM ONLY TAKES INTO CONSIDERATION ONE ATM NOT A ARRAY OF ATM'S. 


	int maxCustPerMin = 0;
	int simMins = 0;
	int maxPerMin = 0;
	int i = 0;
	Atm* _atm = new Atm;




void processMinute()
{
	_atm->createCustomers(maxPerMin);
	_atm->processCurrentCust();
}

void processAtm()
{
		srand(unsigned int(time(NULL)));			
		
		// i must be less than or equal to simMins to ensure the simulation is done and to start processing the customers without new customers 
		for(i=1; i<=simMins; i++)
		{
			cout<< "mintue : " << i<<endl;
			maxPerMin = rand()%maxCustPerMin;

			// if the simulation minutes are up, then just process the customers
			if(i == simMins)
			{
				while(_atm->lengthOfLineUp() != 0)
				{
					maxPerMin = 0;
					cout<< "The simMins are up, now going to process the customers till _atm->lengthOfQ reaches 0."<<endl;
					processMinute();
				}
				cout<< "PROGRAM END"<<endl;
				
			}

			else
			{
				cout<< "maxPerMin is : " << maxPerMin<<endl;
				processMinute();
			}
		}
}

int returnLenghtOfLineup()
{	
	return _atm->lengthOfLineUp();
}

void processStats()
{
	cout<< "The Avg time Spent in line by all customers is : " <<_atm->returnAverageTimeSpentPerCust()<<endl;
}


int main()
{

	cout<< " Whats max Custeomrs Per Minute you would like?"<<endl;
	cin >>	maxCustPerMin;
	cout<<"Whats total Simulation Minutes you want?"<<endl<<endl;
	cin >>	simMins;
	processAtm();
	processStats();

	cin >> simMins;
	return 0;
}