#pragma once
#include "libraries.h"
#include "Data.h"

class QueueNode
{
private:
	Data* pData;    // The memory for Data will need to be allocated on the heap as well!
	QueueNode* pNext;

public:
	/*Constructors*/
	QueueNode(Data* newData = nullptr);
	/*Getters*/
	QueueNode* getNextNode();
	Data* getData();
	/*Setters*/
	void setNextNode(QueueNode* newNext);
	void setData(Data* newData);
};

