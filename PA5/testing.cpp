#include "testing.h"


/*************************testing***********************/
void TestQueue::isEmpty()
{
	cout << "Testing isEmpty()" << endl;
	Queue alt;

	if (alt.isEmpty() == true)
	{
		cout << "Test was completed Succesfully!" << endl;
	}
	else
		cout << "Test was Unsuccessfull..." << endl;

}

void TestQueue::enqueuTest()
{
	cout << "Testing enqueue() on empty Queue" << endl;
	Queue alt;
	Data* empower = new Data;
	if (alt.isEmpty() == true)
	{
		if (alt.enqueue(empower) != nullptr)
		{
			cout << "All Queued up!" << endl;
		}
		else
			cout << "Could Not be Queued...." << endl;
	}

}

void TestQueue::testTwoEnqueue()
{
	cout << "TestingTwoenqueue(), one moment...." << endl;
	Queue alt;
	Data* empower = new Data;
	alt.enqueue(empower);
	if (alt.isEmpty() == false)
	{
		if (alt.enqueue(empower) != nullptr)
		{
			cout << "perfect! allocated a second Queue Succesfully" << endl;
		}
		else
			cout << "Could Not queue second Node..." << endl;
	}
}

void TestQueue::testDequeue()
{
	cout << "Testing dequeue(), one moment..." << endl;

	Queue alt;
	Data* empower = new Data;
	alt.enqueue(empower);
	alt.dequeue();
	if (alt.isEmpty() == true)
	{
		cout << "Test dequeue completed!" << endl;
	}
	else
		cout << "Test was Unsuccessfull..." << endl;
}
void TestQueue::testTwoDequeue()
{
	cout << "Testing dequeue() on Queue with two Nodes!" << endl;

	Data* empower = new Data;
	Queue alt;
	alt.enqueue(empower);
	alt.enqueue(empower);

	if (!alt.isEmpty())
	{
		alt.dequeue();
		if (alt.isEmpty() == true)
		{
			cout << "test failed...." << endl;
		}
		alt.dequeue();
		if (alt.isEmpty() == true)
		{
			cout << "Successfully Dequeued, test successfull!" << endl;
		}
	}
}

void TestQueue::TwentyFourHourTest()
{
}
