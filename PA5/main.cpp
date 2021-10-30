#include "Data.h"
#include "testing.h"

int main()
{
	int randomizedExpress = 0,
		randomizedNormal = 0,
		serviceTime = 0,
		ExpressAtemp = 0,
		ExpressA = 0, 
		NormalA = 0, 
		NormalAtemp = 0;
	int elapsedDuration = 0, 
		expressLineDuration = 0,
		normalLineDuration = 0,
		arrivalDuration = 0,
		ExpressS = 0,
		ExpressC = 1, 
		NormalC = 1, 
		normalS = 0;
	int TotalRunDuration = 0;
	Data ExpressD, normalD;
	QueueNode* tempNode;
	Queue express, normal; 
	srand(time(NULL));
	
	cout << "Please Input how many minutes you wish to run the program for: ";
	cin >> TotalRunDuration;
	for (elapsedDuration = 0; 
		elapsedDuration < TotalRunDuration; 
		elapsedDuration++)
	{		
		if (elapsedDuration == 0)
		{
			ExpressA = ExpressD.randomizedExpress();
			NormalA = normalD.randomizedNormal();
			ExpressD.setTotalDuration(0);
			normalD.setTotalDuration(0);
		}
		/*************************************first runs express operations****************************************************8*/
		if (ExpressA == 0)
		{
			cout << "Express Customer: " << ExpressC << " arrived in the Express Line at: " << elapsedDuration << " Minutes" << endl;
			if (ExpressA == 0 && ExpressS == 0)
			{
				ExpressD.setCustomerDuration(ExpressC);
				ExpressS = ExpressD.randomizedExpress();
				ExpressD.setServiceDuration(ExpressS);
				ExpressD.setTotalDuration(ExpressD.getServiceDuration());
				express.enqueue(&ExpressD);
				expressLineDuration = 0;
				ExpressC++;
			}
			ExpressA = ExpressD.randomizedExpress();
		}

		/*************************************************************************************************************************/
		/************************************followed by normal operations************************************/
		if (NormalA == 0)
		{
			cout << "Normal Customer: " << NormalC << " arrived in the Normal Line at: " << elapsedDuration << " Minutes" << endl;
			if (NormalA == 0 && normalS == 0)
			{
				normalD.setCustomerDuration(NormalC);
				normalS = normalD.randomizedNormal();
				normalD.setServiceDuration(normalS);
				normalD.setTotalDuration(normalD.getServiceDuration());
				normal.enqueue(&normalD);
				normalLineDuration = 0;
				NormalC++;
			}
			NormalA = normalD.randomizedNormal();
		}
		/*************************************************************************************************************************/
		if (ExpressA > 0)
		{
			ExpressA--;
		}
		if (NormalA > 0)
		{
			NormalA--;
		}
	
		if (normalS > 0)
		{
			if (NormalC != 2)
			{
				normalLineDuration++;
			}
			normalS--;
			if (normalS == 0)
			{
				normal.getHead()->getD()->setLineDuration(normalLineDuration);
				cout << "Express Customer: " << normal.getHead()->getD()->getCustomerNumber() <<" Finished checking out in Normal line After being in line for " << normal.getHead()->getD()->getLineDuration() << " Minutes" << endl;
			}
		}
		if (ExpressS > 0)
		{
			if (ExpressC != 2)
			{
				expressLineDuration++;
			}
			ExpressS--;
			if (ExpressS == 0)
			{
				express.getHead()->getD()->setLineDuration(normalLineDuration);
				cout << "Express Customer: " << express.getHead()->getD()->getCustomerNumber() <<" Finished checking out in Express line After being in line for " << express.getHead()->getD()->getLineDuration() << " Minutes" << endl;
			}
		}
		if ((elapsedDuration > 0) && (elapsedDuration % 10 == 0))
		{
			express.DisplayQueue(express.getHead(), 1);
			express.DisplayQueue(normal.getHead(), 2);
		}
	}
	system("pause");

	TestQueue one;
	
	one.isEmpty(); system("pause"); system("cls");

	one.enqueuTest(); system("pause"); system("cls");
	
	one.testTwoEnqueue(); system("pause"); system("cls");
	
	one.testDequeue(); system("pause"); system("cls");
	
	one.testTwoDequeue(); system("pause");system("cls");

}
