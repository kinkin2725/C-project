#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

float money;
int w = 20;
char giftID[15][4];
char giftDescription[15][100];
int Price[15];
int pointsRequired[15];
char CustomerID[20][20];
char CustomerRank[20][20];
int pointsBalance[20];

//================================R5==============================================
bool IsRecord[20] = { false };
//======================================================Earning CCPoints=======
float EarningMoneyRecord[20][10];
int PointsEarnBalanceBefore[20][10];
int PointsEarnBalanceAfter[20][10];
int EarningTemp[20];
//==========================================================Modify CC Points=====
int PointBeforeModifyRecord[20][10];
int PointAfterModifyRecord[20][10];
int ModifyTemp[20];

//================================================================Redeem Gifts===
char* ptrGiftID[20][10][4];
char* ptrGiftDescription[20][10][100];
int PointChangeRedeemGifts[20][10];
int ExtraMoneyRedeemGifts[20][10];
int RedeemGiftsTemp[20];
//=====================================================Initial & Final CCPoints==
int InitialPointBalance[20];
int FinalPointBalance[20];
//============================================================================================


void R1() {
    const char* id[15] = { "A01", "A02", "A03", "B01", "B02", "B03", "B04", "B05",
                          "C01", "C02", "C03", "C04", "D01", "D02", "D03" };
    const char* desciption[15] = { "LG Internet TV",
                                  "Pionner Hifi Set",
                                  "Sony DVD Player",
                                  "Healthy Air Fryer",
                                  "Tefal Microwave Oven",
                                  "Famous Coffee Maker",
                                  "Smart Rice Cooker",
                                  "TechCook Toaster Oven",
                                  "Wellcome $50 Coupon",
                                  "Mannings $50 Coupon",
                                  "Carol Restaurant $100 Coupon",
                                  "Shell $200 Coupon",
                                  "Clever Headset",
                                  "HP Optic Mouse",
                                  "Stylish Bluetooth Speaker" };
    const int P[15] = { 3900, 2400, 400, 1500, 480, 1800, 600, 450,
                       50,   50,   100, 200,  350, 250,  800 };
    const int points[15] = { 19000, 11500, 2000, 7300, 2400, 8800, 2900, 2250,
                            250,   250,   500,  960,  1750, 1250, 3900 };
    char Customer[20][20] = { "Tommy2015", "DavidChan", "Luna123", "TigerMan",
                             "Max5678",   "Neo2000",   "CCTang",  "EchoWong",
                             "Rubychow",  "Ivy2023" };
    char Rank[20][20] = { "B", "B", "B", "B", "S", "S", "S", "G", "G", "G" };
    int Balance[20] = { 8500, 22800, 650,  14000, 2580,
                       8000, 33554, 8650, 28000, 12340 };
    for (int i = 0; i < 15; i++) {
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

void sortstr(char ID[][20], char rank[][20], int points[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(ID[j], ID[j + 1]) > 0) {
                char temp[20];
                int temps[10];
                {
                    strcpy_s(temp, ID[j]);
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