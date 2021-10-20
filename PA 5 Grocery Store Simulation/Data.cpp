#include "Data.h"

Data::Data(int newNum, int newTime, int newTotal)
{
	customerNumber = newNum;
	serviceTime = newTime;
	totalTime = newTotal;
}

/*
	Getter functions
	These don't take in any parameters and return the value of the data member requested
*/
int Data::getCustomerNumber()
{
	return this->customerNumber;
}

int Data::getServiceTime()
{
	return this->serviceTime;
}

int Data::getTotalTime()
{
	return this->totalTime;
}
