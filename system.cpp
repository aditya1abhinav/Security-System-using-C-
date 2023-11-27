#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	int a, i{0};
	string text, place, old, password1, password2, pass, name, password0, age, user, word, word1;
	string creds[2], cp[2];

	cout << "      Security System " << endl << endl;

	cout << "-----------------------------" << endl;
	cout << "|     1. Register           |" << endl;
	cout << "|     2. Log in             |" << endl;
	cout << "|     3. Change password    |" << endl;
	cout << "|     4. End program        |" << endl;
	cout << "-----------------------------" << endl << endl;

	do {
		cout << endl << endl;
		cout << "Enter your choice: ";
		cin >> a;
		switch (a) {
		case 1: {
			cout << "-----------------------------" << endl;
			cout << "|          Register         |" << endl;
			cout << "-----------------------------" << endl << endl;
			cout << "Enter username: ";
			cin >> name;
			cout << "Enter password: ";
			cin >> password0;
			cout << "Enter your age: ";
			cin >> age;
			cout << "Which place do you belong to? ";
			cin >> place;

			ofstream of1;
			of1.open("file.txt");
			if (of1.is_open()) {
				of1 << name << "\n";
				of1 << password0 ;
				cout << "Registration successfull" << endl;
			}
			break;
		}

		case 2: {
			i = 0;

			cout << "-----------------------------" << endl;
			cout << "|           Login           |" << endl;
			cout << "-----------------------------" << endl << endl;

			ifstream of2;
			of2.open("file.txt");
			cout << "Enter the username: ";
			cin >> user;
			cout << "Enter the password: ";
			cin >> pass;

			if (of2.is_open()) {
				while (!of2.eof()) {
					while (getline(of2, text)) {
						istringstream iss(text);
						iss >> word;
						creds[i] = word;
						i++;
					}

					if (user == creds[0] && pass == creds[1]) {
						cout << "-----------------------------" << endl;
						cout << "|    Login successfull      |" << endl;
						cout << "-----------------------------" << endl << endl;

						cout << " Details: " << endl << endl;

						cout << "Username: " + name << endl;
						cout << "Passsword: " + pass << endl;
						cout << "Age: " + age << endl;
						cout << "Place: " + place << endl;
					}
					else {
						cout << endl << endl;
						cout << "Incorrect credentials!" << endl;
						cout << "------------------------------------------" << endl;
						cout << "|       1. Press 2 to login              |" << endl;
						cout << "|       2. Press 3 to change password    |" << endl;
						cout << "------------------------------------------" << endl << endl;
						break;
					}
				}
			}

			break;
		}
		case 3: {
			i = 0;

			cout << "-----------------------------" << endl;
			cout << "|      Change password      |" << endl;
			cout << "-----------------------------" << endl << endl;

			ifstream of0;
			of0.open("file.txt");
			cout << "Enter the old password: ";
			cin >> old;
			if (of0.is_open()) {
				while (of0.eof()) {
					while (getline(of0, text)) {
						istringstream iss(text);
						iss >> word1;
						cp[i] = word1;
						i++;
					}

					if (old == cp[1]) {
						of0.close();

						ofstream of1;
						if (of1.is_open()) {
							cout << "Enter your new password: ";
							cin >> password1;
							cout << "Enter your password again: ";
							cin >> password2;

							if (password1 == password2) {
								of1 << cp[0] << "\n";
								of1 << password1;
								cout << "Password changed successfully" << endl;
							}
							else {
								of1 << cp[0] << "\n";
								of1 << old;
								cout << "Password do not match!" << endl;
							}
						}
					}
					else {
						cout << "Please enter a valid password" << endl;
						break;
					}
				}
			}

			break;
		}
		case 4: {
			cout << endl << endl;
			cout << "-----------------------------" << endl;
			cout << "|         Thank you         |" << endl;
			cout << "-----------------------------" << endl << endl;
			break;
		}

		default:
			cout << "Enter a valid choice";
		}
	}
	while (a != 4);
	return 0;
}