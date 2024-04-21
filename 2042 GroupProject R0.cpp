﻿#include <iostream>
#include <iomanip>
using namespace std;

const char giftID[15][4] = { "A01","A02","A03","B01","B02","B03","B04","B05","C01","C02","C03","C04","D01","D02","D03" };
const char giftDescription[15][100]{ "LG Internet TV","Pionner Hifi Set","Sony DVD Player","Healthy Air Fryer","Tefal Microwave Oven","Famous Coffee Maker","Smart Rice Cooker",
"TechCook Toaster Oven","Wellcome $50 Coupon","Mannings $50 Coupon","Carol Restaurant $100 Coupon","Shell $200 Coupon","Clever Headset","HP Optic Mouse","Stylish Bluetooth Speaker" };
char CustomerID[10][50] = { "Tommy2015","DavidChan","Luna123","TigerMan","Max5678","Neo2000","CCTang","EchoWong","Rubychow","Ivy2023" };
char CustomerRank[10][2] = { "B","B","B","B","S","S","S","G","G","G" };
const int Price[15] = { 3900,2400,400,1500,480,1800,600,450,50,50,100,200,350,250,800 };
const int pointsRequired[15] = { 19000,11500,2000,7300,2400,8800,2900,2250,250,250,500,960,1750,1250,3900 };
int pointsBalance[10] = { 8500,22800,650,14000,2580,8000,33554,8650,28000,12340 };
bool R1run = false;

void R1()
{
	cout << "Gift ID" << setw(20) << "Gift Description" << setw(24);
	cout << "Price(HKD)" << setw(20) << "Points Required\n";
	cout << "----------------------------------------------------------------------\n";
	cout << left;
	for (int i = 0; i < 15; i++)
	{
		cout << setw(11) << giftID[i] << setw(30) << giftDescription[i] << setw(14) << Price[i] << pointsRequired[i] << endl;
	}
	cout << right;
	cout << "\n\n";
	cout << "Customer ID" << setw(10) << "Rank" << setw(20) << "Points Balance\n";
	cout << "----------------------------------------\n";
	cout << left;
	for (int i = 0; i < 10; i++)
	{
		cout << setw(17) << CustomerID[i] << setw(9) << CustomerRank[i] << pointsBalance[i] << endl;
	}
	cout << "\n\n";
}

void R2()
{
	//insert your code here
}

void R3()
{
	//insert your code here
}

void R4()
{
	//insert your code here
}

void R5()
{
	//insert your code here
}

void R6()
{
	//insert your code here
}

int main()
{
	char option;
	do
	{
		cout << "Welcome Message designed by your group\n";
		cout << "*** Main Menu ***\n";
		cout << "[1] Load Starting Data\n";
		cout << "[2] Show Records\n";
		cout << "[3] Edit Customers\n";
		cout << "[4] Enter Customer View\n";
		cout << "[5] Show Transaction History\n";
		cout << "[6] Credits and Exit\n";
		cout << "*****************\n";
		cout << "Option (1 - 6): ";
		cin >> option;
		cout << "\n\n";
		if (option == '1')
		{
			R1run = true;
		}
		if (R1run)
		{
			switch (option)
			{
				case '1':R1(); break;
				case '2':R2(); break;
				case '3':R3(); break;
				case '4':R4(); break;
				case '5':R5(); break;
				case '6':break;
				default:
					cout << "Error...\n\n\n";
					break;
			}
		}
		else if(!R1run)
		{
			cout << "Error...\n\n\n";
		}
	} while (option != '6');

	R6();

	return 0;
}