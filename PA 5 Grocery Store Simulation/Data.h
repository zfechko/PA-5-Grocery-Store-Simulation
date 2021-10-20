#pragma once
#include "libraries.h"

class Data
{
private:
    int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
    int serviceTime;   // Random time; varies between express and normal lanes; units in minutes (1-5 minutes for express lane customers; 3-8
    int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

public:
    /*Constructors/Destructors*/
    Data(int newNum, int newTime, int newTotal);

    /*Getters*/
    int getCustomerNumber();
    int getServiceTime();
    int getTotalTime();

    /*Setters*/

};

