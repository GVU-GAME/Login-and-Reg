#include <iostream>
#include "ui.h"

UI::UI() {
}

int UI::promt() {
    int choice = 0;
    while(choice == 0) {
        cout << "1) Login\n2) Register\n3) Exit\nYour Choice: ";
        cin >> choice;
        cout << endl;

        if(choice > 3 || choice < 1) {
            cout << "Invalid Choice!" << endl;
            choice = 0;
        }
    }
    return choice;
}

bool UI::checkName(string line) {
    ifstream check("Users//" + line + ".txt");
    return check.good();
}

void UI::createAcc() { 
    string username, password, info;
    string test;

    bool validName = false;
    while(!validName) {
        cout << "Enter a Username: " << endl;
        cin >> username;

        bool check = checkName(username);
        if(check) {
            cout << "Sorry this username is already taken, try another one" << endl << endl;
        } else {
            validName = true;
        }
    }
    
    cout << "Enter a Password: " << endl;
    cin >> password;
    cout << "Enter any info you want stored" << endl;
    getline(cin, info); //get the '\n' at the end of the string
    getline(cin, info);

    ofstream file;
    file.open("Users//" + username + ".txt");
    file << username << endl << password << endl << info << endl << endl;
    file.close();
}

bool UI::accessAcc() {
    string username, password, un, pw, info;
    cout << "Enter Your Username: " << endl;
    cin >> username;
    cout << "Enter Your Password: " << endl;
    cin >> password;

    ifstream read ("Users//" + username + ".txt");
    getline(read, un);
    getline(read, pw);
    getline(read, info);

    if(username == un && password == pw) {
        cout << "Successful Login!" << endl;
        cout << "Info: " + info << endl << endl;
        return false;
    } else {
        cout << "Failed Login, Try again!" << endl << endl;
        return true;
    }
}

void UI::start() {
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