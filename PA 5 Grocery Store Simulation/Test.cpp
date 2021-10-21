#include "Test.h"

void Test::runTests()
{
	testEnqueueOnEmpty();
	testEnqueueOneNode();
	testDequeueOneNode();
	testDequeueTwoNodes();
}

void Test::testEnqueueOnEmpty()
{
	cout << "we will now test the enqueue function on an empty queue" << endl;
	Queue emptyTest;
	Data* newData = new Data(1, 2, 3);
	emptyTest.enqueue(*newData);
	if (emptyTest.getHeadPtr()->getData()->getCustomerNumber() == newData->getCustomerNumber())
	{
		cout << "Enqueue has inserted a node successfully" << endl;
	}
	else
	{
		cout << "Something is fucked with your code buddy, check it for bugs" << endl;
	}
}

void Test::testEnqueueOneNode()
{
	cout << "Now testing enqueue on a queue with one node in it" << endl;
	Queue oneNodeTest;
	Data* newData1 = new Data(1, 2, 3);
	oneNodeTest.enqueue(*newData1);
	Data* newData2 = new Data(4, 5, 6);
	oneNodeTest.enqueue(*newData2);

	if (oneNodeTest.getTailPtr()->getData()->getCustomerNumber() == newData2->getCustomerNumber())
	{
		cout << "Enqueue with one node in the queue works!" << endl;
	}
	else
	{
		cout << "Your code doesn't work dumbass, make it work" << endl;
	}
}

void Test::testDequeueOneNode()
{
	cout << "Now testing dequeue on a queue that has one node in it" << endl;
	Queue oneNodeDequeue;
	Data* newData = new Data(1, 2, 3);
	oneNodeDequeue.enqueue(*newData);
	oneNodeDequeue.dequeue();
	if (oneNodeDequeue.getHeadPtr() == nullptr && oneNodeDequeue.getTailPtr() == nullptr)
	{
		cout << "Successfully dequeued one node, both the head and tail == null" << endl;
	}
	else
	{
		cout << "Something isn't right bud, make it work" << endl;
	}
}

void Test::testDequeueTwoNodes()
{
	cout << "Now testing dequeue on a queue that has two nodes in it" << endl;
	Queue twoNodeDequeue;
	Data* newData1 = new Data(1, 2, 3);
	Data* newData2 = new Data(4, 5, 6);
	twoNodeDequeue.enqueue(*newData1);
	twoNodeDequeue.enqueue(*newData2);
	twoNodeDequeue.dequeue();

	//checks for newData2
	if (twoNodeDequeue.getHeadPtr()->getData()->getCustomerNumber() == newData2->getCustomerNumber())
	{
		cout << "Dequeue worked, newData2 is now the head pointer of the queue" << endl;
	}
	else
	{
		cout << "Something doesn't work, because dequeue didn't do its job" << endl;
	}
}