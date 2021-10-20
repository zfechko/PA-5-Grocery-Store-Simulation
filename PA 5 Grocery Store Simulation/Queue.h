#pragma once
#include "libraries.h"
#include "QueueNode.h"

class Queue
{
private:
	QueueNode* pHead;
	QueueNode* pTail;


public:
	/*Constructors/Destructors*/
	Queue(QueueNode* pNewHead = nullptr, QueueNode* pNewTail = nullptr);

	/*Setters*/
	void setHeadPtr(QueueNode* const newHead);
	void setTailPtr(QueueNode* const newTail);

	/*Getters*/

	/*Member functions*/
	bool isEmpty();
	bool enqueue(Data const &newData);
	bool dequeue();
	void printQueue(QueueNode* pNode)
};

