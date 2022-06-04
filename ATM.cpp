#include "ATM.h"
#include<fstream>

ATM::ATM() {

}
ATM::ATM(User u) {
	U = u;
}

bool ATM::validateData(User& u) {
	int Num, PIN;
	cout << "Enter Card Number : ";
	cin >> Num;
	cout << "Enter PIN : ";
	cin >> PIN;
	
	ifstream file;
	file.open("User.txt", ios::in);
	if (!file.is_open()) {
		cout << "ERROR : Could not Open File!\n";
	}

	while (!file.eof()) {
		User temp = fetchUserData(file);
		if (temp.C1.getCardNum() == Num) {
			if (temp.C1.getPIN() == PIN) {
				u = temp;
				return 1;
			}
		}
		file.ignore();
	}

	file.close();

	return 0;
	
}