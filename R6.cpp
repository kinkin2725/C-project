#include <cstring>
#include <iomanip>
#include <iostream>
class R6 {
private: 
    void displayCredits() {
        cout << setw(10) << "Name\t" << "Student ID\t" << "Tutorial group" << endl; // show the credit (information of student)
        cout << "Lui Hin Wang\t" << "23127370A\t" << setw(8) << "B03D" << endl; // student 1
        cout << "So Yu Hin\t" << "23181767A\t" << setw(8) << "B03B" << endl; // student 2
        cout << "Tan Long Kin\t" << "23146901A\t" << setw(8) << "B03A" << endl; // student 3
        cout << "Wan Ka Ho\t" << "23069061A\t" << setw(8) << "B03B" << endl; // student 4
        cout << "Wong Tsz Fung\t" << "23119333A\t" << setw(8) << "B03B" << endl; // student 5
    }

public:
    void Rsix() {
        char input;

        do {
            cout << "Do you want to see the credits? (y/n) ";
            cin >> input;
            // when user enter "yes" 
            if (input == 'y' || input == 'Y') {
                displayCredits();
                exit(0); // terminate the program
            }
            // when user enter "no"
            // if user enter no, go back to main menu
            else if (input == 'n' || input == 'N') {
                cout << "Return to the main menu" << endl;
                return; // return to main menu
            }
            else {
                cout << "Invalid input, please try again" << endl; // tell user to enter again
            }
        } while (input != 'Y' && input != 'y' && input != 'N' && input != 'n'); // keep ask user to enter yes or no if user enter other character
    }
};
