﻿#include <iostream>
#include <iomanip>
using namespace std;
void R1()
{
	//insert your code here
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
		cout << "\n\n"
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
	}while(option != '6');

	R6();
	
	return 0;
}
