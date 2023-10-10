// CMake(REGISTRATION FORM).cpp : Defines the entry point for the application.
//

#include "CMake(REGISTRATION FORM).h"

using namespace std;

int main(){
	int choise;
	cout << "\t\t----------------------------------------\n\n\n";
	cout << "\t\t----Welcome to the registation page-----\n\n\n";
	cout << "\t\t------------------MENU------------------\n\n\n"<< endl;
	cout << "\t\t|Press 1 to LOGIN                      |"<< endl;
	cout << "\t\t|Press 2 to REGISTER                   |"<< endl;
	cout << "\t\t|Press 3 to IF YOU FORGOT YOUR PASSWORD|"<< endl; 
	cout << "\t\t|Press 4 to EXIT                       | " << endl;
	cout << "\n\t\t PLEASE ENTER YOUR CHOISE : ";
	cin >> choise;
	cout << endl;

	switch (choise ) {
		case 1: 
			login();
			break;
		case 2 :
			registration();
			break;
		case 3:
			forgot();
			break;
		case 4 :
			cout << "\t\t THANK YOU!!! \n\n\n";
			break;
		default:
			system("cls");
			cout << "\t\t PLEASE SELECT YOUR OPTION \n\n\n" << endl;
			main();
	}
}

void login() {
	int count = 1;
	string UserId, Password, Id, Pass;
	system("cls");
	cout << "\t\t Please enter the username and password : " <<endl;
	cout << "\t\t USERNAME : ";
	cin >> UserId;
	cout << "\t\t PASSWORD : ";
	cin >> Password;

	ifstream input("records.txt");
	while (input >> Id >> Pass) {
		if (Id == UserId && Pass == Password) {
			count = 1;
			system("cls");
		}
	}
	input.close();

	if (count) {
		cout << "\n\t\t " << UserId << " : Successful login "  << " \n\t\t Thanks for logging in \n " << endl;
		cout << "\n ";
		
		main();
	}
	else {
		cout << "\n LOGIN ERROR!!!\n Check your Username and Password \n";
		main();
	}
};


void registration() {
	string rUserId, rPassword, rId, rPass;
	system("cls");
	cout << "\t\t Enter the username : ";
	cin >> rUserId;
	cout << "\t\t Enter the password : ";
	cin >> rPassword;
	ofstream f1("records.txt", ios::app);
	f1 << rUserId << ' ' << rPassword << endl;
	system("cls");
	cout << "\n \t\t Registration is Successful \n";
	main();
};


void forgot() {
	int option;
	system("cls");
	cout << "\t\t YOU FORGOT YOUR PASSWORD ?\n";
	cout << "\t\t -Press 1 to search your id by username " << endl;
	cout << "\t\t -Press 2 to go back to the main menu " << endl;
	cout << "\t\t Enter your choise : ";
	cin >> option;

	switch (option){
		case 1: {
			int count = 0;
			string sUserId, sId, sPass;
			cout << "\n \t\t Enter the username which you remembered : ";
			cin >> sUserId;

			ifstream f2("records.txt");
			while (f2>> sId >> sPass) {
				if (sId == sUserId) {
					count += 1;
				}
			}
			f2.close();

			if (count == 1) {
				cout << "\n\n\t\t Your account is found \n";
				cout << "\n\n\t\t Your account is : " << sPass;
				main();
			}
			else {
				cout << "\n\t\t Your account is not found \n";
				main();
			}
			break;
		}
		case 2: {
			main();
		}default:
			cout << "\n\t\t Wrong choise. Please try again \n" << endl;
			forgot();
	}
};