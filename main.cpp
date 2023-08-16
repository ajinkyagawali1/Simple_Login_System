#include<iostream>
#include<fstream>
#include<string.h>
#include <unistd.h>

using namespace std;


void registration();  //function for user registration
void login();         //function for user login  
void forget();        //function to change password  
void exit();          //function to exit the program  


int main(){

    // Main Menu Screen

    cout << "\t\t\t__________________________________________________\n\n\n";
    cout << "\t\t\t________________________WELCOME___________________\n\n\n";
    cout << "\t\t\t_________________________MENU_____________________\n\n\n";
    cout << "\t\tPRESS 1 to REGISTER \n";
    cout << "\t\tPRESS 2 to LOGIN\n";
    cout << "\t\tPRESS 3 to CHANGE PASSWORD \n";
    cout << "\t\tPRESS 4 to EXIT \n ";
    cout << "\t\tEnter your choice: ";
    int choice;
    cin >> choice;

    switch(choice){

        case 1 :
            registration();
            break;

        case 2:
            login();
            break;

        case 3:
            forget();
            break;

        case 4:
            exit();
            break;

        default:
            system("cls");
            main();
        }

  

}

void registration(){

    system("cls");

    string userId, Pass;

    cout << "Enter a User Id: ";
    cin >> userId;

    cout << "Enter a password: ";
    cin >> Pass;

    ofstream write;
    write.open("records.txt", ios::app) ;

    write << userId << " "<<  Pass << endl;
    write.close();

    cout << userId << "\nYou are successfullly registered\n";

    sleep(1);
    main();

}

void login(){

    system("cls");

    int count;
    string rId, rPass, sId, sPass;

    cout << "Enter your User Id: ";
    cin >> rId;

    cout << "Enter your password: ";
    cin >> rPass;

    ifstream read("records.txt");

    while(read >> sId >> sPass){
        if(rId==sId && rPass==sPass){
            count=1;
        }
    }
    read.close();

    if (count==1)
    {
        cout << "You are logged in successfully.\n";
    }else{cout << "Enter valid credentials\n";}

    sleep(1);

    main();

}


void forget(){

    system("cls");

    int count;
    string rId, sId, rPass;

    cout << "Enter your username: ";
    cin >> rId;

    ifstream f1("records.txt");

    while(f1 >> sId){
        if (rId == sId)
        {
            count = 1;
        }
    }
    f1.close();

    if (count == 1)
    {
        cout << "We found the username associated with the account \n Please enter a new password: ";
        cin >> rPass;
    }else{cout << "Please enter valid credentials\n";

        forget();        
        }

    sleep(1);
    main();    
}



void exit(){

system("cls");
cout << "\n\n\n\n\t\t\t_____________Thank You_______________\n";
sleep(2);
system("exit");

}


                



