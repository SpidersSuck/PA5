#include "Data.h"
/******************************************************Data member*************************************************/
Data::Data(int customerNumber, int serviceTime, int totalTime)
{
	this->customerNumber = 0;
	this->serviceTime = 0;
	this->totalTime = 0;
}
Data::Data(Data& copy)
{
	this->customerNumber = copy.customerNumber;
	this->serviceTime = copy.serviceTime;
	this->totalTime = copy.totalTime;
}
Data::~Data()
{
}

/*******randomized express and normal insperation from stack overflow*********/
int Data::randomizedExpress()
{
	int randomizedExpress = 0;
	randomizedExpress = rand() % 5 + 1;
	return randomizedExpress;
}
int Data::randomizedNormal()
{
	int randomizedNormal = 0;
	randomizedNormal = rand() % 8 + 3;
	return randomizedNormal;
}
/************************************************************************************/
void Data::setCustomerDuration(int number)
{
	this->customerNumber = number;
}
void Data::setServiceDuration(int time)
{
	this->serviceTime = time;
}

void Data::setTotalDuration(int time)
{
	this->totalTime += time;
}
void Data::setLineDuration(int time)
{
	this->lineDuration = time;
}
int Data::getCustomerNumber()
{
	return this->customerNumber;
}
int Data::getServiceDuration()
{
	return this->serviceTime;
}
int Data::getTotalDuration()
{
	return this->totalTime;
}
int Data::getLineDuration()
{
	return this->lineDuration;
}
/*******************************************************************************************************/

/******************************************************Queue*************************************************/
Queue::Queue(QueueNode * pHead, QueueNode * pTail)
{
	this->pHead = nullptr;
	this->pTail = nullptr;
}

Queue::Queue(Queue & copy)
{
	this->pHead = copy.pHead;
	this->pTail = copy.pTail;
}

Queue::~Queue()
{
}

bool Queue::isEmpty()
{
	if (this->pHead == nullptr && this->pTail == nullptr)
	{
		return true;
	}
	return false;
}

QueueNode* Queue::enqueue(Data* newData)
{
	QueueNode* pMem = new QueueNode(newData, nullptr);

	if (pMem)
	{
		if (isEmpty())
		{
			this->pHead = this->pTail = pMem;
		}
		else
		{
			this->pTail->setN(pMem); 
			this->pTail = pMem; 
		}
		return pMem;
	}
	else
	{
		return nullptr;
	}
}

bool Queue::dequeue()
{
	QueueNode* pCur = nullptr;
	if (!isEmpty())
	{
		pCur = this->pHead;
		if (this->pHead == this->pTail)
		{
			this->pHead = this->pTail = nullptr;
		}
		else
		{
			this->pHead = this->pHead->getN();
		}
		delete pCur;
	}
	return false;
}

void Queue::DisplayQueue(QueueNode* node, int line)
{
	system("pause");
	system("cls");
	if (line == 1)
	{
		cout << "::::::10 mintes into Express lane::::::" << endl;
		while (node->getN()!= nullptr)
		{
			cout << "Customer Number: " << node->getD()->getCustomerNumber() << endl;
			cout << "Service Duration: " << node->getD()->getServiceDuration() << endl;
			cout << "Total Duration: " << node->getD()->getTotalDuration() << endl;
			node = node->getN();
		}
	}
	if (line == 2)
	{
		cout << "::::::10 mintes into Normal lane::::::" << endl;
		while (node->getN() != nullptr)
		{
			cout << "Customer Number: " << node->getD()->getCustomerNumber() << endl;
			cout << "Service Duration: " << node->getD()->getServiceDuration() << endl;
			cout << "Total Duration: " << node->getD()->getTotalDuration() << endl;
			node = node->getN();
		}
	}	
}
void Queue::setHead(QueueNode * head)
{
	this->pHead = head;
}

void Queue::setTail(QueueNode * tail)
{
	this->pTail = tail;
}

QueueNode * Queue::getHead()
{
	return this->pHead;
}

QueueNode * Queue::getTail()
{
	return this->pTail;
}

QueueNode::QueueNode(Data* Data, QueueNode* Next)
{
	this->pD = Data;
	this->pN = Next;
}

QueueNode::QueueNode(QueueNode& copy)
{
	this->pD = copy.pD;
	this->pN = copy.pN;
}

QueueNode::~QueueNode()
{
}

void QueueNode::setD(Data* data)
{
	this->pD = data;
}

void QueueNode::setN(QueueNode* next)
{
	this->pN = next;
}

Data* QueueNode::getD()
{

	return this->pD;
}

QueueNode* QueueNode::getN()
{
	return this->pN;
}

/*******************************************************************************************************/