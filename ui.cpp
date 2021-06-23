#include <iostream>
#include "ui.h"

using namespace std;

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

void UI::createAcc() { 
    string username, password, info;

    cout << "Enter a Username: " << endl;
    cin >> username;
    cout << "Enter a Password: " << endl;
    cin >> password;
    cout << "Enter any info you want stored in file" << endl;
    cin >> info;

    ofstream file;
    file.open("Users//" + username + ".txt");
    file << username << endl << password << endl << info << endl;
    cout << endl;
    file.close();
}

bool UI::accessAcc() {
    string username, password, un, pw, info;

    cout << "Enter Username: " << endl;
    cin >> username;
    cout << "Enter Password: " << endl;
    cin >> password;

    ifstream read ("Users//" + username + ".txt");

    getline(read, un);
    getline(read, pw);
    getline(read, info);

    if(username == un && password == pw) {
        cout << "Successful Login" << endl;
        cout << info << endl;
        return false;
    } else {
        cout << "Failed Login, Try again!" << endl;
        cout << endl;
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
                cout << "Exiting" << endl;
                run = false;
        }
    }
}