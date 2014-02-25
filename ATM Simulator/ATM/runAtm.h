#include <iostream>
#include "Atm.h"
#include "AtmQ.h"
using namespace std;
#include <cstdlib>
#include <ctime> 
class runAtm{

public:
	runAtm();

	void processMinute();

	void processAtm();

	int returnLenghtOfLineup();

	void processStats();

	int main();
};