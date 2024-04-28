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
void R2() {
    cout << "Gift ID" << setw(20) << "Gift Description" << setw(24);
    cout << "Price(HKD)" << setw(20) << "Points Required\n";
    cout << "--------------------------------------------------------------------"
        "--\n";
    cout << left;
    for (int i = 0; i < 15; i++) {
        cout << setw(11) << giftID[i] << setw(30) << giftDescription[i] << setw(14)
            << Price[i] << pointsRequired[i] << endl;
    }
    cout << right;
    cout << "\n\n";
    sortstr(CustomerID, CustomerRank, pointsBalance, 10);
    cout << "Customer ID" << setw(10) << "Rank" << setw(20) << "Points Balance\n";
    cout << "----------------------------------------\n";
    cout << left;
    for (int i = 0; i < 10; i++) {
        cout << setw(17) << CustomerID[i] << setw(9) << CustomerRank[i]
            << pointsBalance[i] << endl;
    }
    cout << "\n\n";
    cout << right;
}
