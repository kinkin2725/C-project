#include <iostream>
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
		switch (option)
		{
			case '1':R1();
			case '2':R2();
			case '3':R3();
			case '4':R4();
			case '5':R5();
			case '6':R6();
		}
	} while (option != '1' && option != '2' && option != '3' && option != '4' && option != '5' && option != '6');

	return 0;
}
