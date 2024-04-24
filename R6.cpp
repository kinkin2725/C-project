#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void R6(){
  char input;

  do{
  cout<<"Do you want to see the credits? (y/n) "; // ask user to enter yes or no
  cin>>input;

  {if(input == 'y', input == 'Y'){
  cout<<setw(10)<<"Name\t"<<"Student ID\t"<<"Tutorial group"<<endl; // show the credit (information of student)
  cout<<"Lui Hin Wang\t"<<"23127370A\t"<<setw(8)<<"B03D"<<endl; // student 1
  cout<<"So Yu Hin\t"<<"23181767A\t"<<setw(8)<<"B03B"<<endl; // student 2
  cout<<"Tan Konh Kin\t"<<"23146901A\t"<<setw(8)<<"B03A"<<endl; // student 3
  cout<<"Wan Ka Ho\t"<<"23069061A\t"<<setw(8)<<"B03B"<<endl; // student 4
  cout<<"Wong Tsz Fung\t"<<"23119333A\t"<<setw(8)<<"B03B"<<endl; // student 5
  
  exit(); // terminate the program
  }
  
  // if user enter no, go back to main menu
  else if(input=='n'||input=='N'){ 
    cout<<"Return to main menu"<<endl;
    return;
  }
  else{
    cout<<"Invalid input, please try again"<<endl; // wrong input, type again
  }
  }
  }while(input !='Y' && input !='y' && input !='N' && input !='n'); // keep ask user to enter yes or no if user enter other character

}
