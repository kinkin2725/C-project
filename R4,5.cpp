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
void selectionSort(int list[], int price[], char id[][4], char description[][100], int listSize) {
    int smallestIndex, temp;
    char tempId[4];
    char tempdescription[100];
    for (int index = 0; index < listSize - 1; index++) {
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


// ==========================================EarningCCPoints=============R5
// funtion header
void R5EarningCCPoints1(int userNum, int temp, float money);
void R5EarningCCPoints2(int userNum, int temp);

// ========================================RedeemGifts====================R5
// funtion header
void R5RedeemGifts1(int userNum, int temp, int GiftNum);
void R5RedeemGifts2(int userNum, int temp, int PointChange);
void R5RedeemGifts3(int userNum, int temp, int ExtraMoney);

// ==================================================ModifyCCPoints==========R5
// funtion header
void R5ModifyCCPoints1(int userNum, int temp, int BeforeModify);
void R5ModifyCCPoints2(int userNum, int temp, int AfterModify);

// ========================================Initial&FinalCCPoints=========R5
// funtion header
void R5RecordSummary1(int userNum, int Before);
void R5RecordSummary2(int userNum, int After);
// End of R5 funtion header

void R4(string InputID) {
    bool invaildInput = true;
    for (int j = 0; j < 10; j++) {
        if (InputID == CustomerID[j]) {
            invaildInput = false;
            int option;
            do {
                string redeem;
                int k = 0;
                int amount;
                char category;
                cout << "Action for Customer ID: " << CustomerID[j] << endl;
                cout << "***** Customer View Menu *****" << endl;
                cout << "[1] Earn CC Points" << endl;
                cout << "[2] Redeem Gifts" << endl;
                cout << "[3] Modify CC Points Balance" << endl;
                cout << "[4] Return to Main Menu" << endl;
                cout << "**************************" << endl;
                cout << "Option (1 - 4): ";
                cin >> option;
                cout << "\n\n";
                switch (option) {
                case 1:
                    if (!IsRecord[j]) {
                        IsRecord[j] = true;
                        R5RecordSummary1(j, pointsBalance[j]);
                    }
                    cout << "\nInput amount of money spent: ";
                    cin >> money;
                    R5EarningCCPoints1(j, EarningTemp[j], money);
                    pointsBalance[j] = money / 250 + pointsBalance[j];
                    R5EarningCCPoints2(j, EarningTemp[j]);
                    cout << "\nNew Points Balance \n" << pointsBalance[j] << endl;
                    EarningTemp[j]++;
                    break;
                case 2:
                    selectionSort(pointsRequired, Price, giftID, giftDescription, 15);
                    if (CustomerRank[j][0] == 'S') {
                        for (int i = 0; i < 15; i++) {
                            pointsRequired[i] *= 0.95;
                        }
                    }
                    else if (CustomerRank[j][0] == 'G') {
                        for (int i = 0; i < 15; i++) {
                            pointsRequired[i] *= 0.90;
                        }
                    }
                    cout << "Input Gift Category (A to D) : ";
                    cin >> category;
                    cout << endl;
                    cout << "! represents You Have Enough CC points to redeem the gift"
                        << endl;
                    switch (category) {
                    case 'A':
                        cout << "Gift ID" << setw(w) << "Gift Description" << setw(25)
                            << "Price(HKD)" << setw(w) << "Points Requried" << endl;
                        cout << "**********************************************************"
                            "**************"
                            << endl;
                        for (int i = 0; i < 15; i++) {
                            if (giftID[i][0] == 'A') {
                                cout << left;
                                if (pointsBalance[j] > pointsRequired[i]) {
                                    cout << "!" << setw(10) << giftID[i] << setw(31)
                                        << giftDescription[i] << setw(15) << Price[i]
                                        << pointsRequired[i] << endl;
                                }
                                else
                                    cout << " " << setw(10) << giftID[i] << setw(31)
                                    << giftDescription[i] << setw(15) << Price[i]
                                    << pointsRequired[i] << endl;
                                cout << right;
                            }
                        }
                        while (k <= 2) {
                            int temp = 0;
                            cout << "Enter GiftID of the gift that you want to redeem: ";
                            cin >> redeem;
                            for (int i = 0; i < 15; i++) {
                                if (strncmp(redeem.c_str(), giftID[i], 3) == 0) {
                                    cout << "Amount of CC points you would like to use: ";
                                    cin >> amount;
                                    if (amount <= pointsBalance[j]) {
                                        if (amount >= pointsRequired[i]) {
                                            if (!IsRecord[j]) {
                                                IsRecord[j] = true;
                                                R5RecordSummary1(j, pointsBalance[j]);
                                            }
                                            R5RedeemGifts1(j, RedeemGiftsTemp[j], i);
                                            R5RedeemGifts2(j, RedeemGiftsTemp[j], pointsRequired[i]);
                                            R5RedeemGifts3(j, RedeemGiftsTemp[j], amount);
                                            RedeemGiftsTemp[j]++;
                                            cout << "Extra money needed = $0" << endl;
                                            cout << "(" << pointsRequired[i]
                                                << " CC points is required and to be deducted"
                                                << ")" << endl;
                                            pointsBalance[j] = pointsBalance[j] - pointsRequired[i];
                                            cout << "Remaining CC points: " << pointsBalance[j]
                                                << endl;
                                            k += 99;
                                        }
                                        else {
                                            amount *= 0.2;
                                            int extra;
                                            extra = Price[i] - amount;
                                            cout << "Extra money needed = $ " << Price[i] << "- "
                                                << amount << "= $" << extra << endl;
                                            cout << "(" << pointsRequired[i]
                                                << " CC points is required"
                                                << ")" << endl;
                                            cout << "Type 'y' to confirm your purchase" << endl;
                                            char confirm;
                                            char confirmation = 'y';
                                            cin >> confirm;
                                            if (confirm == confirmation) {
                                                if (!IsRecord[j]) {
                                                    IsRecord[j] = true;
                                                    R5RecordSummary1(j, pointsBalance[j]);
                                                }
                                                R5RedeemGifts1(j, RedeemGiftsTemp[j], i);
                                                R5RedeemGifts2(j, RedeemGiftsTemp[j], pointsRequired[i]);
                                                R5RedeemGifts3(j, RedeemGiftsTemp[j], amount);
                                                RedeemGiftsTemp[j]++;
                                                pointsBalance[j] = pointsBalance[j] - amount;
                                                cout << "Remaining CC points: " << pointsBalance[j]
                                                    << endl;
                                                k += 99;
                                            }
                                        }
                                    }
                                    else {
                                        temp++;
                                    }
                                }
                            }
                            if (temp != 0) {
                                cout << "Error, Invalid Input" << endl;
                            }
                            k++;
                        }
                        if (CustomerRank[j][0] == 'S') {
                            for (int i = 0; i < 15; i++) {
                                pointsRequired[i] = pointsRequired[i] * (100.0 / 95.0);
                            }
                        }
                        else if (CustomerRank[j][0] == 'G') {
                            for (int i = 0; i < 15; i++) {
                                pointsRequired[i] = pointsRequired[i] * (10.0 / 9.0);
                            }
                        }
                        break;
                    case 'B':
                        cout << "Gift ID" << setw(w) << "Gift Description" << setw(25)
                            << "Price(HKD)" << setw(w) << "Points Requried" << endl;
                        cout << "**********************************************************"
                            "**************"
                            << endl;
                        for (int i = 0; i < 15; i++) {
                            if (giftID[i][0] == 'B') {
                                cout << left;
                                if (pointsBalance[j] > pointsRequired[i]) {
                                    cout << "!" << setw(10) << giftID[i] << setw(31)
                                        << giftDescription[i] << setw(15) << Price[i]
                                        << pointsRequired[i] << endl;
                                }
                                else
                                    cout << " " << setw(10) << giftID[i] << setw(31)
                                    << giftDescription[i] << setw(15) << Price[i]
                                    << pointsRequired[i] << endl;
                                cout << right;
                            }
                        }
                        while (k <= 2) {
                            int temp = 0;
                            cout << "Enter GiftID of the gift that you want to redeem: ";
                            cin >> redeem;
                            for (int i = 0; i < 15; i++) {
                                if (strncmp(redeem.c_str(), giftID[i], 3) == 0) {
                                    cout << "Amount of CC points you would like to use: ";
                                    cin >> amount;
                                    if (amount <= pointsBalance[j]) {
                                        if (amount >= pointsRequired[i]) {
                                            if (!IsRecord[j]) {
                                                IsRecord[j] = true;
                                                R5RecordSummary1(j, pointsBalance[j]);
                                            }
                                            R5RedeemGifts1(j, RedeemGiftsTemp[j], i);
                                            R5RedeemGifts2(j, RedeemGiftsTemp[j], pointsRequired[i]);
                                            R5RedeemGifts3(j, RedeemGiftsTemp[j], amount);
                                            RedeemGiftsTemp[j]++;
                                            cout << "Extra money needed = $0" << endl;
                                            cout << "(" << pointsRequired[i]
                                                << " CC points is required and to be deducted"
                                                << ")" << endl;
                                            pointsBalance[j] = pointsBalance[j] - pointsRequired[i];
                                            cout << "Remaining CC points: " << pointsBalance[j]
                                                << endl;
                                            k += 99;
                                        }
                                        else {
                                            amount *= 0.2;
                                            int extra;
                                            extra = Price[i] - amount;
                                            cout << "Extra money needed = $ " << Price[i] << "- "
                                                << amount << "= $" << extra << endl;
                                            cout << "(" << pointsRequired[i]
                                                << " CC points is required"
                                                << ")" << endl;
                                            cout << "Type 'y' to confirm your purchase" << endl;
                                            char confirm;
                                            char confirmation = 'y';
                                            cin >> confirm;
                                            if (confirm == confirmation) {
                                                if (!IsRecord[j]) {
                                                    IsRecord[j] = true;
                                                    R5RecordSummary1(j, pointsBalance[j]);
                                                }
                                                R5RedeemGifts1(j, RedeemGiftsTemp[j], i);
                                                R5RedeemGifts2(j, RedeemGiftsTemp[j], pointsRequired[i]);
                                                R5RedeemGifts3(j, RedeemGiftsTemp[j], amount);
                                                RedeemGiftsTemp[j]++;
                                                pointsBalance[j] = pointsBalance[j] - amount;
                                                cout << "Remaining CC points: " << pointsBalance[j]
                                                    << endl;
                                                k += 99;
                                            }
                                        }
                                    }
                                    else {
                                        temp++;
                                    }
                                }
                            }
                            if (temp != 0) {
                                cout << "Error, Invalid Input" << endl;
                            }
                            k++;
                        }
                        if (CustomerRank[j][0] == 'S') {
                            for (int i = 0; i < 15; i++) {
                                pointsRequired[i] = pointsRequired[i] * (100.0 / 95.0);
                            }
                        }
                        else if (CustomerRank[j][0] == 'G') {
                            for (int i = 0; i < 15; i++) {
                                pointsRequired[i] = pointsRequired[i] * (10.0 / 9.0);
                            }
                        }
                        break;
                    case 'C':
                        cout << "Gift ID" << setw(w) << "Gift Description" << setw(25)
                            << "Price(HKD)" << setw(w) << "Points Requried" << endl;
                        cout << "**********************************************************"
                            "**************"
                            << endl;
                        for (int i = 0; i < 15; i++) {
                            if (giftID[i][0] == 'C') {
                                cout << left;
                                if (pointsBalance[j] > pointsRequired[i]) {
                                    cout << "!" << setw(10) << giftID[i] << setw(31)
                                        << giftDescription[i] << setw(15) << Price[i]
                                        << pointsRequired[i] << endl;
                                }
                                else
                                    cout << " " << setw(10) << giftID[i] << setw(31)
                                    << giftDescription[i] << setw(15) << Price[i]
                                    << pointsRequired[i] << endl;
                                cout << right;
                            }
                        }
                        while (k <= 2) {
                            int temp = 0;
                            cout << "Enter GiftID of the gift that you want to redeem: ";
                            cin >> redeem;
                            for (int i = 0; i < 15; i++) {
                                if (strncmp(redeem.c_str(), giftID[i], 3) == 0) {
                                    cout << "Amount of CC points you would like to use: ";
                                    cin >> amount;
                                    if (amount <= pointsBalance[j]) {
                                        if (amount >= pointsRequired[i]) {
                                            if (!IsRecord[j]) {
                                                IsRecord[j] = true;
                                                R5RecordSummary1(j, pointsBalance[j]);
                                            }
                                            R5RedeemGifts1(j, RedeemGiftsTemp[j], i);
                                            R5RedeemGifts2(j, RedeemGiftsTemp[j], pointsRequired[i]);
                                            R5RedeemGifts3(j, RedeemGiftsTemp[j], amount);
                                            RedeemGiftsTemp[j]++;
                                            cout << "Extra money needed = $0" << endl;
                                            cout << "(" << pointsRequired[i]
                                                << " CC points is required and to be deducted"
                                                << ")" << endl;
                                            pointsBalance[j] = pointsBalance[j] - pointsRequired[i];
                                            cout << "Remaining CC points: " << pointsBalance[j]
                                                << endl;
                                            k += 99;
                                        }
                                        else {
                                            amount *= 0.2;
                                            int extra;
                                            extra = Price[i] - amount;
                                            cout << "Extra money needed = $ " << Price[i] << "- "
                                                << amount << "= $" << extra << endl;
                                            cout << "(" << pointsRequired[i]
                                                << " CC points is required"
                                                << ")" << endl;
                                            cout << "Type 'y' to confirm your purchase" << endl;
                                            char confirm;
                                            char confirmation = 'y';
                                            cin >> confirm;
                                            if (confirm == confirmation) {
                                                if (!IsRecord[j]) {
                                                    IsRecord[j] = true;
                                                    R5RecordSummary1(j, pointsBalance[j]);
                                                }
                                                R5RedeemGifts1(j, RedeemGiftsTemp[j], i);
                                                R5RedeemGifts2(j, RedeemGiftsTemp[j], pointsRequired[i]);
                                                R5RedeemGifts3(j, RedeemGiftsTemp[j], amount);
                                                RedeemGiftsTemp[j]++;
                                                pointsBalance[j] = pointsBalance[j] - amount;
                                                cout << "Remaining CC points: " << pointsBalance[j]
                                                    << endl;
                                                k += 99;
                                            }
                                        }
                                    }
                                    else {
                                        temp++;
                                    }
                                }
                            }
                            if (temp != 0) {
                                cout << "Error, Invalid Input" << endl;
                            }
                            k++;
                        }
                        if (CustomerRank[j][0] == 'S') {
                            for (int i = 0; i < 15; i++) {
                                pointsRequired[i] = pointsRequired[i] * (100.0 / 95.0);
                            }
                        }
                        else if (CustomerRank[j][0] == 'G') {
                            for (int i = 0; i < 15; i++) {
                                pointsRequired[i] = pointsRequired[i] * (10.0 / 9.0);
                            }
                        }
                        break;
                    case 'D':
                        cout << "Gift ID" << setw(w) << "Gift Description" << setw(25)
                            << "Price(HKD)" << setw(w) << "Points Requried" << endl;
                        cout << "**********************************************************"
                            "**************"
                            << endl;
                        for (int i = 0; i < 15; i++) {
                            if (giftID[i][0] == 'D') {
                                cout << left;
                                if (pointsBalance[j] > pointsRequired[i]) {
                                    cout << "!" << setw(10) << giftID[i] << setw(31)
                                        << giftDescription[i] << setw(15) << Price[i]
                                        << pointsRequired[i] << endl;
                                }
                                else
                                    cout << " " << setw(10) << giftID[i] << setw(31)
                                    << giftDescription[i] << setw(15) << Price[i]
                                    << pointsRequired[i] << endl;
                                cout << right;
                            }
                        }
                        while (k <= 2) {
                            int temp = 0;
                            cout << "Enter GiftID of the gift that you want to redeem: ";
                            cin >> redeem;
                            for (int i = 0; i < 15; i++) {
                                if (strncmp(redeem.c_str(), giftID[i], 3) == 0) {
                                    cout << "Amount of CC points you would like to use: ";
                                    cin >> amount;
                                    if (amount <= pointsBalance[j]) {
                                        if (amount >= pointsRequired[i]) {
                                            if (!IsRecord[j]) {
                                                IsRecord[j] = true;
                                                R5RecordSummary1(j, pointsBalance[j]);
                                            }
                                            R5RedeemGifts1(j, RedeemGiftsTemp[j], i);
                                            R5RedeemGifts2(j, RedeemGiftsTemp[j], pointsRequired[i]);
                                            R5RedeemGifts3(j, RedeemGiftsTemp[j], amount);
                                            RedeemGiftsTemp[j]++;
                                            cout << "Extra money needed = $0" << endl;
                                            cout << "(" << pointsRequired[i]
                                                << " CC points is required and to be deducted"
                                                << ")" << endl;
                                            pointsBalance[j] = pointsBalance[j] - pointsRequired[i];
                                            cout << "Remaining CC points: " << pointsBalance[j]
                                                << endl;
                                            k += 99;
                                        }
                                        else {
                                            amount *= 0.2;
                                            int extra;
                                            extra = Price[i] - amount;
                                            cout << "Extra money needed = $ " << Price[i] << "- "
                                                << amount << "= $" << extra << endl;
                                            cout << "(" << pointsRequired[i]
                                                << " CC points is required"
                                                << ")" << endl;
                                            cout << "Type 'y' to confirm your purchase" << endl;
                                            char confirm;
                                            char confirmation = 'y';
                                            cin >> confirm;
                                            if (confirm == confirmation) {
                                                if (!IsRecord[j]) {
                                                    IsRecord[j] = true;
                                                    R5RecordSummary1(j, pointsBalance[j]);
                                                }
                                                R5RedeemGifts1(j, RedeemGiftsTemp[j], i);
                                                R5RedeemGifts2(j, RedeemGiftsTemp[j], pointsRequired[i]);
                                                R5RedeemGifts3(j, RedeemGiftsTemp[j], amount);
                                                RedeemGiftsTemp[j]++;
                                                pointsBalance[j] = pointsBalance[j] - amount;
                                                cout << "Remaining CC points: " << pointsBalance[j]
                                                    << endl;
                                                k += 99;
                                            }
                                        }
                                    }
                                    else {
                                        temp++;
                                    }
                                }
                            }
                            if (temp != 0) {
                                cout << "Error, Invalid Input" << endl;
                            }
                            k++;
                        }
                        if (CustomerRank[j][0] == 'S') {
                            for (int i = 0; i < 15; i++) {
                                pointsRequired[i] = pointsRequired[i] * (100.0 / 95.0);
                            }
                        }
                        else if (CustomerRank[j][0] == 'G') {
                            for (int i = 0; i < 15; i++) {
                                pointsRequired[i] = pointsRequired[i] * (10.0 / 9.0);
                            }
                        }
                        break;
                    }
                    break;
                case 3:
                    if (!IsRecord[j]) {
                        IsRecord[j] = true;
                        R5RecordSummary1(j, pointsBalance[j]);
                    }
                    R5ModifyCCPoints1(j, ModifyTemp[j], pointsBalance[j]);
                    cout << "current CC Points Balance: " << pointsBalance[j] << endl;
                    cout << "Input a new CC Points Balance value: ";
                    int tempo;
                    tempo = pointsBalance[j];
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
                    cin >> pointsBalance[j];
                    cout << "Sucess, the new CC Points Balance is :" << pointsBalance[j]
                        << endl;
                    R5ModifyCCPoints2(j, ModifyTemp[j], pointsBalance[j]);
                    ModifyTemp[j]++;
                    break;
                case 4:
                    R5RecordSummary2(j, pointsBalance[j]);
                    break;
                }
            } while (option != 4);
        }
    }
    if (invaildInput) {
        cout << "\nCustomer ID Not Found\n";
    }
    cout << "\nReturning to Main Menu\n\n";
}

void Rfour() {
    string ID;
    cout << "Input your customer ID: ";
    cin >> ID;
    R4(ID);
}

// R5 funtion
//=======================================================================“Add CC

//Points”================
void R5PrintEarningCCPoints(int userNum, int temp) {
    if (temp != 0) {
        cout << "**********************" << endl;
        cout << "* Earrnig CC Points: *" << endl;
        cout << "**********************" << endl;
        cout << "No." << setw(10) << "Before" << setw(15) << "Money Spent" << setw(10) << "After\n";
        cout << "-----------------------------------------\n";
        cout << left;
        for (int i = 0; i < temp; i++) {
            cout << setw(7) << i << setw(10) << PointsEarnBalanceBefore[userNum][i] << setw(15) << EarningMoneyRecord[userNum][i] << PointsEarnBalanceAfter[userNum][i] << endl;
        }
        cout << "\n\n";
    }
} // Print “Add CC Points”
void R5EarningCCPoints1(int userNum, int temp, float money) {
    EarningMoneyRecord[userNum][temp] = money;
    PointsEarnBalanceBefore[userNum][temp] = pointsBalance[userNum];
}
void R5EarningCCPoints2(int userNum, int temp) {
    PointsEarnBalanceAfter[userNum][temp] = pointsBalance[userNum];
}

//=====================================================================“Modify
//CC Points Balance” ====
void R5PrintModifyCCPoints(int userNum, int temp) {
    if (temp != 0) {
        cout << "************************\n";
        cout << "* Modify of CC Points: *\n";
        cout << "************************\n";
        for (int i = 0; i < temp; i++) {
            cout << "\n\nCC Points modified: " << i + 1 << endl;
            cout << "-----------------------------------------\n";
            cout << "\nCC Points Balance BEFORE modified: "
                << PointBeforeModifyRecord[userNum][i] << endl;
            cout << "CC Points Balance AFTER modified: "
                << PointAfterModifyRecord[userNum][i] << endl;
            cout << "change in the CC Points Balance: ";
            if (PointBeforeModifyRecord[userNum][i] <
                PointAfterModifyRecord[userNum][i]) {
                cout << "Increase by "
                    << PointAfterModifyRecord[userNum][i] -
                    PointBeforeModifyRecord[userNum][i]
                    << endl;
            }
            else {
                cout << "Decrease by "
                    << PointBeforeModifyRecord[userNum][i] -
                    PointAfterModifyRecord[userNum][i]
                    << endl;
            }
        }
    }
} // Print “Modify CC Points Balance”
void R5ModifyCCPoints1(int userNum, int temp, int BeforeModify) {
    PointBeforeModifyRecord[userNum][temp] = BeforeModify;
    PointAfterModifyRecord[userNum][temp] = BeforeModify;
}
void R5ModifyCCPoints2(int userNum, int temp, int AfterModify) {
    PointAfterModifyRecord[userNum][temp] = AfterModify;
}

//====================================================================================“Redeem
//Gifts”=======
void R5PrintRedeemGifts(int userNum, int temp) {
    if (temp != 0) {
        cout << "*****************\n";
        cout << "* Redeem Gifts: *\n";
        cout << "*****************\n";
        for (int i = 0; i < temp; i++) {
            cout << "\n\nGift Redeemed: " << i + 1;
            cout << "\n--------------------------\n\n";
            cout << "Gift ID: " << *ptrGiftID[userNum][i] << endl;
            cout << "Gift Description: " << *ptrGiftDescription[userNum][i] << endl;
            cout << "Points Change: " << PointChangeRedeemGifts[userNum][i] << endl;
            if (ExtraMoneyRedeemGifts[userNum][i] !=
                0) { // Check Extra Money Redeem Gifts
                cout << "Extra Money Needed: " << ExtraMoneyRedeemGifts[userNum][i]
                    << endl;
            }
            else {
                cout << "No Extra Money Needed" << endl;
            }
        } // loop the gift array to show ALL the gift redeemed
        cout << "\n\n";
    }
} // "Print Redeem Gifts"
void R5RedeemGifts1(int userNum, int temp, int GiftNum) { // temp = count of Redeem; userNum = which
                                   // user; GiftNum = which Gift
    for (int k = 0; k < 4; k++) {
        ptrGiftID[userNum][temp][k] = &giftID[GiftNum][k];
    }
    for (int k = 0; k < 100; k++) {
        ptrGiftDescription[userNum][temp][k] = &giftDescription[GiftNum][k];
    }
} // Record GiftID & giftDescription of Redeem Gifts transaction
void R5RedeemGifts2(int userNum, int temp, int PointChange) {
    PointChangeRedeemGifts[userNum][temp] = PointChange;
} // Record Point use for Redeem Gifts transaction
void R5RedeemGifts3(int userNum, int temp, int ExtraMoney) {
    ExtraMoneyRedeemGifts[userNum][temp] = ExtraMoney;
} // Record Extra Money of Redeem Gifts transaction

//=============================================================================================
//summary ========
void R5PrintRecordSummary(int userNum) {
    if (InitialPointBalance[userNum] != FinalPointBalance[userNum]) {
        cout << "\n\nRecord Summary: ";
        cout << "\n**************************************************************"
            "\n\n";
        cout << "Initial Point Balance: " << InitialPointBalance[userNum]
            << endl; // original CC Points Balance
        cout << "Final Point Balance: " << FinalPointBalance[userNum]
            << endl; // final CC Points Balance
        cout << "Change in the CC Points Balance: "
            << FinalPointBalance[userNum] - InitialPointBalance[userNum]
            << endl; // change in CC Points Balance
        if (ExtraMoneyRedeemGifts[userNum] != 0) {
            int extra = 0;
            for (int i = 0; i < 10; i++) {
                extra += ExtraMoneyRedeemGifts[userNum][i];
            } // calculate the total extra money
            cout << "Total Money Spent: " << extra << endl;
        }
    } // check if extra money spent on Redeem Gifts
} // Print summary
void R5RecordSummary1(int userNum, int Before) {
    InitialPointBalance[userNum] = Before; // count = which customer
} // record original CC Points Balance
void R5RecordSummary2(int userNum, int After) {
    FinalPointBalance[userNum] = After; // count = which customer
} // record final CC Points Balance

// End of R5 function

void R5() {
    string InputID;
    cout << "InputID: ";
    cin >> InputID;
    bool vaildInput = false;

    for (int j = 0; j < 10; j++) {

        if (InputID == CustomerID[j]) {
            vaildInput = true;
            cout << "\nCustomer ID: " << CustomerID[j] << endl;
            cout << "*****************************************************\n\n";
            R5PrintEarningCCPoints(j, EarningTemp[j]);
            R5PrintRedeemGifts(j, RedeemGiftsTemp[j]);
            R5PrintModifyCCPoints(j, ModifyTemp[j]);
            R5PrintRecordSummary(j);
            if (EarningTemp[j] == 0 && ModifyTemp[j] == 0 &&
                RedeemGiftsTemp[j] == 0) {
                cout << "No transaction done yet" << endl;
            }
        }
    }
    if (!vaildInput) {
        cout << "\nCustomer ID Not Found\n";
    }
    cout << "\nReturning to Main Menu\n\n";
}