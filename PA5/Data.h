#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
/***************************************data class, getter/setter*************************************/
class Data
{
public: 

	Data(int customerNumber = 0, int serviceTime = 0, int totalTime = 0); // all paramaters in one nice line this time! 
	Data(Data& copy); 
	~Data(); 
	int randomizedExpress();
	int randomizedNormal();
	void setCustomerDuration(int number); 
	void setServiceDuration(int time); 
	void setTotalDuration(int time);
	void setLineDuration(int time);
	int getCustomerNumber(); 
	int getServiceDuration();
	int getTotalDuration(); 
	int getLineDuration();
private:
	int customerNumber; 
	int serviceTime;   
	int totalTime;     
	int lineDuration; 
};
/**************************************************************************************************************************************/
/***************************************************member function***********************************************************************************/
class QueueNode
{
public: 
	QueueNode(Data* Data, QueueNode* Next); 
	QueueNode(QueueNode& copy);
	~QueueNode(); 
	void setD(Data* data); 
	void setN(QueueNode* next);
	Data* getD();
	QueueNode* getN();
private:
	Data* pD;    
	QueueNode* pN; 
};

/**************************************************************************************************************************************/
/*******************************************************Queue*******************************************************************************/
class Queue
{
public:
	Queue(QueueNode* pHead = nullptr, QueueNode* pTail = nullptr); 
	Queue(Queue& copy);
	~Queue(); 
	bool isEmpty(); 
	QueueNode* enqueue(Data* newData); 
	bool dequeue(); 
	void DisplayQueue(QueueNode* node, int line); 
	void setHead(QueueNode* head); 
	void setTail(QueueNode* tail); 
	QueueNode* getHead(); 
	QueueNode* getTail(); 
private:
	QueueNode* pHead; 
	QueueNode* pTail;
};
/**************************************************************************************************************************************/