#pragma once
#include "libraries.h"
#include "Queue.h"

class Test
{
private:

public:
	void runTests();

	void testEnqueueOnEmpty();
	void testEnqueueOneNode();
	void testDequeueOneNode();
	void testDequeueTwoNodes();
};

