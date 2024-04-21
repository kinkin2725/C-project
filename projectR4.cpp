#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
float money;
int	points = 22800;
int w = 30;
char giftID[15][4] = { "A01","A02","A03","B01","B02","B03","B04","B05","C01","C02","C03","C04","D01","D02","D03" };
char giftDescription[15][100] {"LG Internet TV","Pionner Hifi Set","Sony DVD Player","Healthy Air Fryer","Tefal Microwave Oven","Famous Coffee Maker","Smart Rice Cooker",
"TechCook Toaster Oven","Wellcome $50 Coupon","Mannings $50 Coupon","Carol Restaurant $100 Coupon","Shell $200 Coupon","Clever Headset","HP Optic Mouse","Stylish Bluetooth Speaker" };
char CustomerID[10][50] = { "Tommy2015","DavidChan","Luna123","TigerMan","Max5678","Neo2000","CCTang","EchoWong","Rubychow","Ivy2023" };
char CustomerRank[10][2] = { "B","B","B","B","S","S","S","G","G","G" };
int Price[15] = { 3900,2400,400,1500,480,1800,600,450,50,50,100,200,350,250,800 };
int pointsRequired[15] = { 19000,11500,2000,7300,2400,8800,2900,2250,250,250,500,960,1750,1250,3900 };

void selectionSort(int list[], int listSize)
{
	int smallestIndex, temp;
	for (int index = 0; index < listSize - 1; index++)
	{
		smallestIndex = index;
		for (int pos = index + 1; pos < listSize; pos++)
			if (list[pos] < list[smallestIndex])
				smallestIndex = pos;
		temp = list[smallestIndex];
		list[smallestIndex] = list[index];
		list[index] = temp;
	}
}

void R4(string InputID)
{

	for (int i = 0; i < 10; i++)
	{
		if (InputID == CustomerID[i])
		{
			int option;
			char category;
			cout << "Action for Customer ID: " << CustomerID[i] << endl;
			cout << "***** Customer View Menu *****" << endl;
			cout << "[1] Earn CC Points" << endl;
			cout << "[2] Redeem Gifts" << endl;
			cout << "[3] Modify CC Points Balance" << endl;
			cout << "[4] Return to Main Menu" << endl;
			cout << "**************************" << endl;
			cout << "Option (1 - 4): ";
			cin >> option;
			switch (option)
			{
			case 1:
				cout << "Input amount of money spent: ";
				cin >> money;
				points = money / 250 + points;
				cout << "New Points Balance " << points << endl;
				R4(InputID);
			case 2:
				if (CustomerRank[i][0] == 'S')
				{
					for (int i = 0; i < 15; i++)
					{
						pointsRequired[i] *= 0.95;
					}
				}
				else if (CustomerRank[i][0] == 'G')
				{
					for (int i = 0; i < 15; i++)
					{
						pointsRequired[i] *= 0.90;
					}
				}
				cout << "Input Gift Category (A to D) : ";
				cin >> category;
				switch (category)
				{
				case 'A':
					cout << "Gift ID" << setw(w) << "Gift Description" << setw(w) << "Price(HKD)" << setw(w) << "Points Requried" << endl;
					cout << "************************************************************************************************" << endl;
					for (int i = 0; i < 3; i++)
					{
						cout << giftID[i] << setw(w) << giftDescription[i] << setw(w) << Price[i] << setw(w) << pointsRequired[i] << endl;
					}
					if (CustomerRank[i][0] == 'S')
					{
						for (int i = 0; i < 15; i++)
						{
							pointsRequired[i] = pointsRequired[i]*(100.0/95.0);
						}
					}
					else if (CustomerRank[i][0] == 'G')
					{
						for (int i = 0; i < 15; i++)
						{
							pointsRequired[i] = pointsRequired[i]*(10.0/9.0);
						}
					}
					R4(InputID);
				case 'B':
					cout << "Gift ID" << setw(w) << "Gift Description" << setw(w) << "Price(HKD)" << setw(w) << "Points Requried" << endl;
					cout << "************************************************************************************************" << endl;
					for (int i = 3; i < 8; i++)
					{
						cout << giftID[i] << setw(w) << giftDescription[i] << setw(w) << Price[i] << setw(w) << pointsRequired[i] << endl;
					}
					if (CustomerRank[i][0] == 'S')
					{
						for (int i = 0; i < 15; i++)
						{
							pointsRequired[i] = pointsRequired[i] * (100.0 / 95.0);
						}
					}
					else if (CustomerRank[i][0] == 'G')
					{
						for (int i = 0; i < 15; i++)
						{
							pointsRequired[i] = pointsRequired[i] * (10.0 / 9.0);
						}
					}
					R4(InputID);
				case 'C':
					cout << "Gift ID" << setw(w) << "Gift Description" << setw(w) << "Price(HKD)" << setw(w) << "Points Requried" << endl;
					cout << "************************************************************************************************" << endl;
					for (int i = 8; i < 12; i++)
					{
						cout << giftID[i] << setw(w) << giftDescription[i] << setw(w) << Price[i] << setw(w) << pointsRequired[i] << endl;
					}
					if (CustomerRank[i][0] == 'S')
					{
						for (int i = 0; i < 15; i++)
						{
							pointsRequired[i] = pointsRequired[i] * (100.0 / 95.0);
						}
					}
					else if (CustomerRank[i][0] == 'G')
					{
						for (int i = 0; i < 15; i++)
						{
							pointsRequired[i] = pointsRequired[i] * (10.0 / 9.0);
						}
					}
					R4(InputID);
				case 'D':
					cout << "Gift ID" << setw(w) << "Gift Description" << setw(w) << "Price(HKD)" << setw(w) << "Points Requried" << endl;
					cout << "************************************************************************************************" << endl;
					for (int i = 12; i < 15; i++)
					{
						cout << giftID[i] << setw(w) << giftDescription[i] << setw(w) << Price[i] << setw(w) << pointsRequired[i] << endl;
					}
					if (CustomerRank[i][0] == 'S')
					{
						for (int i = 0; i < 15; i++)
						{
							pointsRequired[i] = pointsRequired[i] * (100.0 / 95.0);
						}
					}
					else if (CustomerRank[i][0] == 'G')
					{
						for (int i = 0; i < 15; i++)
						{
							pointsRequired[i] = pointsRequired[i] * (10.0 / 9.0);
						}
					}
					R4(InputID);
				}
			}
			return;
		}
	}
		cout << "Customer ID Not Found, return to Main Menu";
}
	int main()
	{
		string ID;
		cout << "Input your customer ID: ";
		cin >> ID;
		R4(ID);
	}
