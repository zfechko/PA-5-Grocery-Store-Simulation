#include "Queue.h"

Queue::Queue(QueueNode* pNewHead, QueueNode* pNewTail)
{
	this->pHead = pNewHead;
	this->pTail = pNewTail;
}

Queue::~Queue()
{
	this->noRussian();
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

void Queue::noRussian()
{
	while (!isEmpty())
	{
		this->dequeue();
	}
}

/*
Runs the simulation for a set amount of time
Some of this code was inspired by how Zach Nett does his simulation (he's a lifesaver)
*/
void runSimulation(int simTime)
{
	Queue normalLane;
	Queue expressLane;

	int totalSimTime = 0; //for keeping track how many minutes the simulation has been running
	int totalTime = 0; //for summing up the total service times
	int customerNum = 1;

	int normalArrivalTime = rand() % 5 + 1; //picks a random number between 1 and 5
	int expressArrivalTime = rand() % 8 + 3; //picks a random number between 3 and 8

	int timeUntilNextNormal = normalArrivalTime;
	int timeUntilNextExpress = expressArrivalTime;

	int timeAtFrontOfNormal = 0, timeAtFrontOfExpress = 0;

	while (totalSimTime != simTime) //while we haven't hit the simulation time
	{
		if (timeAtFrontOfNormal < 0 && !normalLane.isEmpty()) //if the time runs out and the queue for the normal lane isn't empty
		{
			timeAtFrontOfNormal = normalLane.getTailPtr()->getData()->getServiceTime(); //we set it to the service time of the customer at the end of the queue
		}

		if (timeAtFrontOfExpress < 0 && !expressLane.isEmpty()) //same deal as above but with the express lane
		{
			timeAtFrontOfExpress = expressLane.getTailPtr()->getData()->getServiceTime();
		}

		if (normalArrivalTime == 0) //if it's time to add another customer to the normal queue
		{
			int serviceTime = rand() % 5 + 1; //generate a new service time
			totalTime += serviceTime;
			Data* newNormalCustomer = new Data(customerNum++, serviceTime, totalTime);
			cout << "New customer " << newNormalCustomer->getCustomerNumber() << " has entered the normal queue" << endl;
			normalLane.enqueue(*newNormalCustomer);	
			timeUntilNextNormal = rand() % 5 + 1; //generate a new time  until we get another customer in the line
		}

		if (expressArrivalTime == 0)
		{
			int serviceTime = rand() % 8 + 3; //pick a random service time
			totalTime +=
		}
	}
}

