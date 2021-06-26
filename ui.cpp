#include <iostream>
#include "ui.h"

//default constructor
UI::UI() {
}

//Prints out the prompt and choices
int UI::promt() {
    //loops until a valid function is picked
    int choice = 0;
    while(choice == 0) {
        cout << "1) Login\n2) Register\n3) Exit\nYour Choice: ";
        cin >> choice;
        cout << endl;

        //makes sure entered number is a valid option
        if(choice > 3 || choice < 1) {
            cout << "Invalid Choice!" << endl;
            choice = 0;
        }
    }
    return choice;
}

//Checks to see if the username is already taken
bool UI::checkName(string line) {
    ifstream check("Users//" + line + ".txt");
    return check.good();
}

//Registers a new account
void UI::createAcc() { 
    string username, password, info;
    string test;

    //loops until a unique username is entered
    bool validName = false;
    while(!validName) {
        cout << "Enter a Username: " << endl;
        cin >> username;

        //calls checkName to see if name is avaliable
        bool check = checkName(username);
        if(check) {
            cout << "Sorry this username is already taken, try another one" << endl << endl;
        } else {
            validName = true;
        }
    }
    
    //gets the rest of the info
    cout << "Enter a Password: " << endl;
    cin >> password;
    cout << "Enter any info you want stored" << endl;
    getline(cin, info); //get the '\n' at the end of the string
    getline(cin, info);

    //creates a file with username
    ofstream file;
    file.open("Users//" + username + ".txt");
    file << username << endl << password << endl << info << endl << endl;
    file.close();
}

//Login to an account
bool UI::accessAcc() {
    string username, password, un, pw, info;
    cout << "Enter Your Username: " << endl;
    cin >> username;
    cout << "Enter Your Password: " << endl;
    cin >> password;

    //reads from file
    ifstream read ("Users//" + username + ".txt");
    getline(read, un);
    getline(read, pw);
    getline(read, info);

    //checks to see if the info entered is correct
    if(username == un && password == pw) {
        cout << "Successful Login!" << endl;
        cout << "Info: " + info << endl << endl;
        return false;
    } else {
        cout << "Failed Login, Try again!" << endl << endl;
        return true;
    }
}

//runs the process
void UI::start() {
    //loops until told to exit by user
    bool run = true;
    while(run) {
        int choice = promt();

        switch(choice) {
            case 1:
                run = accessAcc();
                break;
            case 2:
                createAcc();
                break;
            default:
                cout << "Exiting" << endl << endl;
                run = false;
        }
    }
}