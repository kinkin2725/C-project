#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
float money;
int	points = 22800;
char giftID[15][4] = { "A01","A02","A03","B01","B02","B03","B04","B05","C01","C02","C03","C04","D01","D02","D03" };
char CustomerID[10][20] = { "Tommy2015","DavidChan","Luna123","TigerMan","Max5678","Neo2000","CCTang","EchoWong","Rubychow","Ivy2023" };
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
				cout << points;

			case 2:
				cout << "Input Gift Category (A to D) : ";
				cin >> category;
				switch (category)
				{
				case 'A':
					cout << "Gift ID" << setw(5) << "Gift Description" << setw(5) << "Price(HKD)" << setw(5) << "Points Requried";


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