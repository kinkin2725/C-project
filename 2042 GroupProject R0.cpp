#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

float money; // the global variables of the data
int w = 20;
char giftID[15][4];
char giftDescription[15][100];
int Price[15];
int pointsRequired[15];
char CustomerID[20][20];
char CustomerRank[20][20];
int pointsBalance[20];

void R1()
{
	const char* id[15] = { "A01","A02","A03","B01","B02","B03","B04","B05","C01","C02","C03","C04","D01","D02","D03" }; //these are the variables to store data
	const char* desciption[15] = { "LG Internet TV","Pionner Hifi Set","Sony DVD Player","Healthy Air Fryer","Tefal Microwave Oven","Famous Coffee Maker","Smart Rice Cooker",
	"TechCook Toaster Oven","Wellcome $50 Coupon","Mannings $50 Coupon","Carol Restaurant $100 Coupon","Shell $200 Coupon","Clever Headset","HP Optic Mouse","Stylish Bluetooth Speaker" };
	const int P[15] = { 3900,2400,400,1500,480,1800,600,450,50,50,100,200,350,250,800 };
	const int points[15] = { 19000,11500,2000,7300,2400,8800,2900,2250,250,250,500,960,1750,1250,3900 };
	char Customer[20][20] = { "Tommy2015","DavidChan","Luna123","TigerMan","Max5678","Neo2000","CCTang","EchoWong","Rubychow","Ivy2023" };
	char Rank[20][20] = { "B","B","B","B","S","S","S","G","G","G" };
	int Balance[20] = { 8500,22800,650,14000,2580,8000,33554,8650,28000,12340 };
	for (int i = 0; i < 15; i++)
	{
		strcpy_s(giftID[i], id[i]); //copy the data to global variables
		strcpy_s(giftDescription[i], desciption[i]);
		Price[i] = P[i];
		pointsRequired[i] = points[i];
		strcpy_s(CustomerID[i], Customer[i]);
		strcpy_s(CustomerRank[i], Rank[i]);
		pointsBalance[i] = Balance[i];
	}
	cout << "Starting Data Loaded\n\n\n";
}

void sortstr(char ID[][20], char rank[][20], int points[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (strcmp(ID[j], ID[j + 1]) > 0)
			{
				char temp[20];
				int temps[10];
				{
					strcpy_s(temp, ID[j]);  //the function to sort alphabetically
					strcpy_s(ID[j], ID[j + 1]);
					strcpy_s(ID[j + 1], temp);
					strcpy_s(temp, rank[j]);
					strcpy_s(rank[j], rank[j + 1]);
					strcpy_s(rank[j + 1], temp);
					temps[i] = points[j];
					points[j] = points[j + 1];
					points[j + 1] = temps[i];
				}
			}
		}
	}
}

void R2()
{
	cout << "Gift ID" << setw(20) << "Gift Description" << setw(24);	//to show the data of giftID
	cout << "Price(HKD)" << setw(20) << "Points Required\n";
	cout << "----------------------------------------------------------------------\n";
	cout << left;
	for (int i = 0; i < 15; i++)
	{
		cout << setw(11) << giftID[i] << setw(30) << giftDescription[i] << setw(14) << Price[i] << pointsRequired[i] << endl;
	}
	cout << right;
	cout << "\n\n";
	sortstr(CustomerID, CustomerRank, pointsBalance, 10); //sort the customer ID alphabetically 
	cout << "Customer ID" << setw(10) << "Rank" << setw(20) << "Points Balance\n"; //to show to the data of Customer ID
	cout << "----------------------------------------\n";
	cout << left;
	for (int i = 0; i < 10; i++)
	{
		cout << setw(17) << CustomerID[i] << setw(9) << CustomerRank[i] << pointsBalance[i] << endl;
	}
	cout << "\n\n";
	cout << right;
}

void R3()
{
	//insert your code here
}

void selectionSort(int list[], int price[], char id[][4], char description[][100], int listSize)
{
	int smallestIndex, temp;
	char tempId[4];
	char tempdescription[100];
	for (int index = 0; index < listSize - 1; index++)	//sort the data by price in acsending order
	{
		smallestIndex = index;
		for (int pos = index + 1; pos < listSize; pos++)
			if (list[pos] < list[smallestIndex])
				smallestIndex = pos;
		temp = list[smallestIndex];
		list[smallestIndex] = list[index];
		list[index] = temp;
		temp = price[smallestIndex];
		price[smallestIndex] = price[index];
		price[index] = temp;
		strcpy_s(tempId, id[smallestIndex]);
		strcpy_s(id[smallestIndex], id[index]);
		strcpy_s(id[index], tempId);
		strcpy_s(tempdescription, description[smallestIndex]);
		strcpy_s(description[smallestIndex], description[index]);
		strcpy_s(description[index], tempdescription);

	}
}
void R4(string InputID)
{
	for (int j = 0; j < 10; j++)
	{
		if (InputID == CustomerID[j])	//if CustomerID is correct,Enter Customer View
		{
			int option;
			do
			{
				string redeem;
				int k = 0;
				int amount;
				char category;
				cout << "Action for Customer ID: " << CustomerID[j] << endl;
				cout << "***** Customer View Menu *****" << endl;		//switch 1-4
				cout << "[1] Earn CC Points" << endl;
				cout << "[2] Redeem Gifts" << endl;
				cout << "[3] Modify CC Points Balance" << endl;
				cout << "[4] Return to Main Menu" << endl;
				cout << "**************************" << endl;
				cout << "Option (1 - 4): ";
				cin >> option;	//input option
				switch (option)
				{
				case 1:	//Earn CC Points
					cout << "Input amount of money spent: ";
					cin >> money;
					pointsBalance[j] = money / 250 + pointsBalance[j];
					cout << "New Points Balance " << pointsBalance[j] << endl;
					break;
				case 2:	//Redeem Gifts
					selectionSort(pointsRequired, Price, giftID, giftDescription, 15);
					if (CustomerRank[j][0] == 'S')
					{
						for (int i = 0; i < 15; i++)
						{
							pointsRequired[i] *= 0.95;
						}
					}
					else if (CustomerRank[j][0] == 'G')
					{
						for (int i = 0; i < 15; i++)
						{
							pointsRequired[i] *= 0.90;
						}
					}
					cout << "Input Gift Category (A to D) : ";
					cin >> category;
					cout << endl;
					cout << "! represents You Have Enough CC points to redeem the gift" << endl;
					switch (category)
					{
					case 'A':
						cout << "Gift ID" << setw(w) << "Gift Description" << setw(25) << "Price(HKD)" << setw(w) << "Points Requried" << endl;
						cout << "************************************************************************" << endl;
						for (int i = 0; i < 15; i++)
						{
							if (giftID[i][0] == 'A')
							{
								cout << left;
								if (pointsBalance[j] > pointsRequired[i])
								{
									cout << "!" << setw(10) << giftID[i] << setw(31) << giftDescription[i] << setw(15) << Price[i] << pointsRequired[i] << endl;
								}
								else
									cout << " " << setw(10) << giftID[i] << setw(31) << giftDescription[i] << setw(15) << Price[i] << pointsRequired[i] << endl;
								cout << right;
							}
						}
						while (k <= 2)
						{
							int temp = 0;
							cout << "Enter GiftID of the gift that you want to redeem: ";
							cin >> redeem;
							for (int i = 0; i < 15; i++)
							{
								if (strncmp(redeem.c_str(), giftID[i], 3) == 0)
								{
									cout << "Amount of CC points you would like to use: ";
									cin >> amount;
									if (amount <= pointsBalance[j])
									{
										if (amount >= pointsRequired[i])
										{
											cout << "Extra money needed = $0" << endl;
											cout << "(" << pointsRequired[i] << " CC points is required and to be deducted" << ")" << endl;
											pointsBalance[j] = pointsBalance[j] - pointsRequired[i];
											cout << "Remaining CC points: " << pointsBalance[j] << endl;
											k += 99;
										}
										else
										{
											amount *= 0.2;
											int extra;
											extra = Price[i] - amount;
											cout << "Extra money needed = $ " << Price[i] << "- " << amount << "= $" << extra << endl;
											cout << "(" << pointsRequired[i] << " CC points is required" << ")" << endl;
											cout << "Type 'y' to confirm your purchase" << endl;
											char confirm;
											char confirmation = 'y';
											cin >> confirm;
											if (confirm == confirmation)
											{
												pointsBalance[j] = pointsBalance[j] - amount;
												cout << "Remaining CC points: " << pointsBalance[j] << endl;
												k += 99;
											}
										}
									}
									else {
										temp++;
									}
								}
							}
							if (temp != 0)
							{
								cout << "Error, Invalid Input" << endl;
							}
							k++;
						}
						if (CustomerRank[j][0] == 'S')
						{
							for (int i = 0; i < 15; i++)
							{
								pointsRequired[i] = pointsRequired[i] * (100.0 / 95.0);
							}
						}
						else if (CustomerRank[j][0] == 'G')
						{
							for (int i = 0; i < 15; i++)
							{
								pointsRequired[i] = pointsRequired[i] * (10.0 / 9.0);
							}
						}
						break;
					case 'B':
						cout << "Gift ID" << setw(w) << "Gift Description" << setw(25) << "Price(HKD)" << setw(w) << "Points Requried" << endl;
						cout << "************************************************************************" << endl;
						for (int i = 0; i < 15; i++)
						{
							if (giftID[i][0] == 'B')
							{
								cout << left;
								if (pointsBalance[j] > pointsRequired[i])
								{
									cout << "!" << setw(10) << giftID[i] << setw(31) << giftDescription[i] << setw(15) << Price[i] << pointsRequired[i] << endl;
								}
								else
									cout << " " << setw(10) << giftID[i] << setw(31) << giftDescription[i] << setw(15) << Price[i] << pointsRequired[i] << endl;
								cout << right;
							}
						}
						while (k <= 2)
						{
							int temp = 0;
							cout << "Enter GiftID of the gift that you want to redeem: ";
							cin >> redeem;
							for (int i = 0; i < 15; i++)
							{
								if (strncmp(redeem.c_str(), giftID[i], 3) == 0)
								{
									cout << "Amount of CC points you would like to use: ";
									cin >> amount;
									if (amount <= pointsBalance[j])
									{
										if (amount >= pointsRequired[i])
										{
											cout << "Extra money needed = $0" << endl;
											cout << "(" << pointsRequired[i] << " CC points is required and to be deducted" << ")" << endl;
											pointsBalance[j] = pointsBalance[j] - pointsRequired[i];
											cout << "Remaining CC points: " << pointsBalance[j] << endl;
											k += 99;
										}
										else
										{
											amount *= 0.2;
											int extra;
											extra = Price[i] - amount;
											cout << "Extra money needed = $ " << Price[i] << "- " << amount << "= $" << extra << endl;
											cout << "(" << pointsRequired[i] << " CC points is required" << ")" << endl;
											cout << "Type 'y' to confirm your purchase" << endl;
											char confirm;
											char confirmation = 'y';
											cin >> confirm;
											if (confirm == confirmation)
											{
												pointsBalance[j] = pointsBalance[j] - amount;
												cout << "Remaining CC points: " << pointsBalance[j] << endl;
												k += 99;
											}
										}
									}
									else {
										temp++;
									}
								}
							}
							if (temp != 0)
							{
								cout << "Error, Invalid Input" << endl;
							}
							k++;
						}
						if (CustomerRank[j][0] == 'S')
						{
							for (int i = 0; i < 15; i++)
							{
								pointsRequired[i] = pointsRequired[i] * (100.0 / 95.0);
							}
						}
						else if (CustomerRank[j][0] == 'G')
						{
							for (int i = 0; i < 15; i++)
							{
								pointsRequired[i] = pointsRequired[i] * (10.0 / 9.0);
							}
						}
						break;
					case 'C':
						cout << "Gift ID" << setw(w) << "Gift Description" << setw(25) << "Price(HKD)" << setw(w) << "Points Requried" << endl;
						cout << "************************************************************************" << endl;
						for (int i = 0; i < 15; i++)
						{
							if (giftID[i][0] == 'C')
							{
								cout << left;
								if (pointsBalance[j] > pointsRequired[i])
								{
									cout << "!" << setw(10) << giftID[i] << setw(31) << giftDescription[i] << setw(15) << Price[i] << pointsRequired[i] << endl;
								}
								else
									cout << " " << setw(10) << giftID[i] << setw(31) << giftDescription[i] << setw(15) << Price[i] << pointsRequired[i] << endl;
								cout << right;
							}
						}
						while (k <= 2)
						{
							int temp = 0;
							cout << "Enter GiftID of the gift that you want to redeem: ";
							cin >> redeem;
							for (int i = 0; i < 15; i++)
							{
								if (strncmp(redeem.c_str(), giftID[i], 3) == 0)
								{
									cout << "Amount of CC points you would like to use: ";
									cin >> amount;
									if (amount <= pointsBalance[j])
									{
										if (amount >= pointsRequired[i])
										{
											cout << "Extra money needed = $0" << endl;
											cout << "(" << pointsRequired[i] << " CC points is required and to be deducted" << ")" << endl;
											pointsBalance[j] = pointsBalance[j] - pointsRequired[i];
											cout << "Remaining CC points: " << pointsBalance[j] << endl;
											k += 99;
										}
										else
										{
											amount *= 0.2;
											int extra;
											extra = Price[i] - amount;
											cout << "Extra money needed = $ " << Price[i] << "- " << amount << "= $" << extra << endl;
											cout << "(" << pointsRequired[i] << " CC points is required" << ")" << endl;
											cout << "Type 'y' to confirm your purchase" << endl;
											char confirm;
											char confirmation = 'y';
											cin >> confirm;
											if (confirm == confirmation)
											{
												pointsBalance[j] = pointsBalance[j] - amount;
												cout << "Remaining CC points: " << pointsBalance[j] << endl;
												k += 99;
											}
										}
									}
									else {
										temp++;
									}
								}
							}
							if (temp != 0)
							{
								cout << "Error, Invalid Input" << endl;
							}
							k++;
						}
						if (CustomerRank[j][0] == 'S')
						{
							for (int i = 0; i < 15; i++)
							{
								pointsRequired[i] = pointsRequired[i] * (100.0 / 95.0);
							}
						}
						else if (CustomerRank[j][0] == 'G')
						{
							for (int i = 0; i < 15; i++)
							{
								pointsRequired[i] = pointsRequired[i] * (10.0 / 9.0);
							}
						}
						break;
					case 'D':
						cout << "Gift ID" << setw(w) << "Gift Description" << setw(25) << "Price(HKD)" << setw(w) << "Points Requried" << endl;
						cout << "************************************************************************" << endl;
						for (int i = 0; i < 15; i++)
						{
							if (giftID[i][0] == 'D')
							{
								cout << left;
								if (pointsBalance[j] > pointsRequired[i])
								{
									cout << "!" << setw(10) << giftID[i] << setw(31) << giftDescription[i] << setw(15) << Price[i] << pointsRequired[i] << endl;
								}
								else
									cout << " " << setw(10) << giftID[i] << setw(31) << giftDescription[i] << setw(15) << Price[i] << pointsRequired[i] << endl;
								cout << right;
							}
						}
						while (k <= 2)
						{
							int temp = 0;
							cout << "Enter GiftID of the gift that you want to redeem: ";
							cin >> redeem;
							for (int i = 0; i < 15; i++)
							{
								if (strncmp(redeem.c_str(), giftID[i], 3) == 0)
								{
									cout << "Amount of CC points you would like to use: ";
									cin >> amount;
									if (amount <= pointsBalance[j])
									{
										if (amount >= pointsRequired[i])
										{
											cout << "Extra money needed = $0" << endl;
											cout << "(" << pointsRequired[i] << " CC points is required and to be deducted" << ")" << endl;
											pointsBalance[j] = pointsBalance[j] - pointsRequired[i];
											cout << "Remaining CC points: " << pointsBalance[j] << endl;
											k += 99;
										}
										else
										{
											amount *= 0.2;
											int extra;
											extra = Price[i] - amount;
											cout << "Extra money needed = $ " << Price[i] << "- " << amount << "= $" << extra << endl;
											cout << "(" << pointsRequired[i] << " CC points is required" << ")" << endl;
											cout << "Type 'y' to confirm your purchase" << endl;
											char confirm;
											char confirmation = 'y';
											cin >> confirm;
											if (confirm == confirmation)
											{
												pointsBalance[j] = pointsBalance[j] - amount;
												cout << "Remaining CC points: " << pointsBalance[j] << endl;
												k += 99;
											}
										}
									}
									else {
										temp++;
									}
								}
							}
							if (temp != 0)
							{
								cout << "Error, Invalid Input" << endl;
							}
							k++;
						}
						if (CustomerRank[j][0] == 'S')
						{
							for (int i = 0; i < 15; i++)
							{
								pointsRequired[i] = pointsRequired[i] * (100.0 / 95.0);
							}
						}
						else if (CustomerRank[j][0] == 'G')
						{
							for (int i = 0; i < 15; i++)
							{
								pointsRequired[i] = pointsRequired[i] * (10.0 / 9.0);
							}
						}
						break;
					}
				case 3:
					cout << "current CC Points Balance: " << pointsBalance[j] << endl;
					cout << "Input a new CC Points Balance value: ";
					int tempo;
					tempo = pointsBalance[j];
					cin >> pointsBalance[j];
					if (pointsBalance[j] >= 0)
					{
						cout << "Sucess, the new CC Points Balance is :" << pointsBalance[j] << endl;
					}
					else
					{
						pointsBalance[j] = tempo;
						cout << "Invalid input , the CC Points value should be positive." << endl;
						cout << "return to customer view" << endl;
					}
					break;
				case 4:
					break;
				}
			} while (option != 4);

		}
	}
	cout << "\nCustomer ID Not Found, return to Main Menu\n\n";
}

void Rfour()
{
	string ID;
	cout << "Input your customer ID: ";
	cin >> ID; //input customerID
	R4(ID); //call function R4
}

void R5()
{
	//insert your code here
}

void R6()
{
	char input;

	do {
		cout << "Do you want to see the credits? (y/n) : "; // ask user to enter yes or no
		cin >> input;
		cout << "\n";
		{
			if (input == 'y' || input == 'Y') {
				cout << setw(10) << "Name\t" << "Student ID\t" << "Tutorial group\t" << endl; // show the credit (information of student)
				cout << "-------------------------------------------------\n";
				cout << "Lui Hin Wang\t" << "23127370A\t" << setw(8) << "B03D" << endl; // student 1
				cout << "So Yu Hin\t" << "23181767A\t" << setw(8) << "B03B" << endl; // student 2
				cout << "Tan Konh Kin\t" << "23146901A\t" << setw(8) << "B03A" << endl; // student 3
				cout << "Wan Ka Ho\t" << "23069061A\t" << setw(8) << "B03B" << endl; // student 4
				cout << "Wong Tsz Fung\t" << "23119333A\t" << setw(8) << "B03B" << endl; // student 5
				exit(0);
			}

			// if user enter no, go back to main menu
			else if (input == 'n' || input == 'N') {
				cout << "Return to main menu\n" << endl;
				return;
			}
			else {
				cout << "Invalid input, please try again" << endl; // wrong input, type again
			}
		}
	} while (input != 'Y' && input != 'y' && input != 'N' && input != 'n'); // keep ask user to enter yes or no if user enter other character
}

int main()
{
	char option;
	bool R1run = false;
	bool yn = true;
	while (yn)
	{
		cout << "Welcome! This is Gift Redemption System\n";
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
		if (option == '1' || option == '6')
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
			case '4':Rfour(); break;
			case '5':R5(); break;
			case '6':R6(); break;
			default:
				cout << "Error...\n\n\n";
				break;
			}
		}
		else if (!R1run)
		{
			cout << "Error...\n\n\n";
		}
	}

	return 0;
}
