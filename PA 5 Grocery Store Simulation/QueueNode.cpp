#include "QueueNode.h"

QueueNode* QueueNode::getNextNode()
{
	return this->pNext;
}

void QueueNode::setNextNode(QueueNode* newNext)
{
	pNext = newNext;
}

void QueueNode::setData(Data* newData)
{
	pData = newData;
}

Data* QueueNode::getData()
{
	return pData;
}