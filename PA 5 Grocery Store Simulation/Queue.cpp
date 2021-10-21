#include "Queue.h"

Queue::Queue(QueueNode* pNewHead, QueueNode* pNewTail)
{
	this->pHead = pNewHead;
	this->pTail = pNewTail;
}

/*
Function name: isEmpty
Predicate function that checks if the head node of the queue is empty and returns either true
or false
*/
bool Queue::isEmpty()
{
	return pHead == nullptr; //returns whether pHead equals null (true) or not (false)
}

bool Queue::enqueue(Data const &newData)
{
	bool success = false;
	Data* pNew = new Data(newData); //creates a new data object
	QueueNode* pNode = new QueueNode(pNew); //uses that new data to make a node
	if (pNode != nullptr)
	{
		success = true;
		if (pHead == nullptr) //if inserting into an empty queue
		{
			pHead = pTail = pNode; //sets the head and tail pointer to the new node
		}
		else
		{
			pTail->setNextNode(pNode);
			pTail = pNode;
		}
	}
	return success;
}

bool Queue::dequeue()
{
	bool success = false;
	QueueNode* pTemp = nullptr;
	if (pHead == pTail) //if there's only one node in the queue
	{
		pTemp = pHead;
		pHead = pTail = nullptr; //set both the head and tail to null
		delete pTemp; //and delete pTemp
		success = true;
	}
	else //there's more than one node in the queue
	{
		pTemp = pHead; //set the temp node to the head
		pHead = pHead->getNextNode(); //set the head to the next node in the queue
		delete pTemp; // delete the temp node
		success = true;
	}
	return success;
}

void Queue::setHeadPtr(QueueNode* const newHead)
{
	this->pHead = newHead;
}

void Queue::setTailPtr(QueueNode* const newTail)
{
	this->pTail = newTail;
}

QueueNode* Queue::getHeadPtr()
{
	return pHead;
}

QueueNode* Queue::getTailPtr()
{
	return pTail;
}

void Queue::printQueue(QueueNode* pNode)
{
	if (pNode != nullptr)
	{
		cout << "{ " << pNode->getData()->getCustomerNumber() << " } <---";
		printQueue(pNode->getNextNode());
	}
	else
	{
		cout << endl;
	}
}

