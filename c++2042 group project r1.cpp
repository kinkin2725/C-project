#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

char giftID[15][4];
char giftDescription[15][100];
int Price[15];
int pointsRequired[15];
char CustomerID[20][20];
char CustomerRank[20][20];
int pointsBalance[20];

void R1()
{
	const char* id[15] = { "A01","A02","A03","B01","B02","B03","B04","B05","C01","C02","C03","C04","D01","D02","D03" };
	const char* desciption[15] = { "LG Internet TV","Pionner Hifi Set","Sony DVD Player","Healthy Air Fryer","Tefal Microwave Oven","Famous Coffee Maker","Smart Rice Cooker",
	"TechCook Toaster Oven","Wellcome $50 Coupon","Mannings $50 Coupon","Carol Restaurant $100 Coupon","Shell $200 Coupon","Clever Headset","HP Optic Mouse","Stylish Bluetooth Speaker" };
	const int P[15] = { 3900,2400,400,1500,480,1800,600,450,50,50,100,200,350,250,800 };
	const int points[15] = { 19000,11500,2000,7300,2400,8800,2900,2250,250,250,500,960,1750,1250,3900 };
	char Customer[20][20] = { "Tommy2015","DavidChan","Luna123","TigerMan","Max5678","Neo2000","CCTang","EchoWong","Rubychow","Ivy2023" };
	char Rank[20][20] = { "B","B","B","B","S","S","S","G","G","G" };
	int Balance[20] = { 8500,22800,650,14000,2580,8000,33554,8650,28000,12340 };
	for (int i = 0; i < 15; i++)
	{
		strcpy_s(giftID[i], id[i]);
		strcpy_s(giftDescription[i], desciption[i]);
		Price[i] = P[i];
		pointsRequired[i] = points[i];
		strcpy_s(CustomerID[i], Customer[i]);
		strcpy_s(CustomerRank[i], Rank[i]);
		pointsBalance[i] = Balance[i];
	}
	cout << "Starting Data Loaded\n\n\n";
}

int main()
{
    R1();

}
