#include"Functions.h"
#include"CheckingAccount.h"
#include"SavingAccount.h"
#include<fstream>


void Menu() {
	cout << "\n\nPlease Select one of the options below!\n\n";
	cout << "Press 1 to create a New Bank Account\n";
	cout << "Press 2 to login to an Existing Account\n";
	cout << "Press 3 to Exit this Program\n";
}
void Opening() {
	cout << "\t\t\t\t---------------------------------------------------------\n";
	cout << "\t\t\t\t|\t\tWelcome to Bank Account System          |\n";
	cout << "\t\t\t\t---------------------------------------------------------\n";
}
void NewUser() {
	cout << "\t\t\t\t----------------------------------------------\n";
	cout << "\t\t\t\t|\t\tCreate A New User            |\n";
	cout << "\t\t\t\t----------------------------------------------\n";
}
void ATMChoice() {
	cout << "\n\n\n----------------------------------------------\n";
	cout << "Select which type of ATM u want to Use : \n\n";
	cout << "Press 1 to use Basic ATM (For Withdrawl or User Info)\n";
	cout << "Press 2 to use Complex ATM (For Withdrawal, Transfer, Inquiry or Change PIN)\n";
	cout << "Press 3 to go to Main Menu\n";
	cout << "Press 4 to Exit this Program\n";
}
void LogIn() {
	cout << "\t\t\t\t----------------------------------------------\n";
	cout << "\t\t\t\t|\t\tLog In to Your Account          |\n";
	cout << "\t\t\t\t----------------------------------------------\n";
}
void exitProgram() {
	cout << "\nThankYou for Using this Program!\n";
	cout << "Good Bye!\n";
	exit(0);
}

istream& operator >>(istream& in, User& U) {
	ofstream file;
	file.open("User.txt", ios::out | ios::app);
	if (!file.is_open()) {
		cout << "ERROR : Could not Open File!\n";
		return in;
	}

	
	cout << "Enter Full Name : ";
	char Name[30];
	in.ignore();
	in.getline(Name, 30);
	U.setName(Name);
	file << Name << ",";
	U.setName(Name);

	cout << "Enter Phone Number : ";
	double PhoneNumber;
	in >> PhoneNumber;
	file << PhoneNumber << ",";
	U.setPhoneNumber(PhoneNumber);

	cout << "Enter Address : ";
	char Address[30];
	in.ignore();
	in.getline(Address, 30);
	file << Address << ",";
	U.setAddress(Address);

Choice:
	int choice;
	cout << "Select Type of Account U want to Create\n";
	cout << "Press 1 to Create a Checking Account\n";
	cout << "Press 2 to Create a Saving Account\n";
	in >> choice;

	switch (choice) {
	case 1:
	{
		file << "Checking,";

		cout << "Enter Bank Name : ";
		char BankName[30];
		cin.ignore();
		in.getline(BankName, 30);
		file << BankName << ",";

		cout << "Enter Branch Name : ";
		char BranchName[30];
		in.getline(BranchName, 30);
		file << BranchName << ",";

		cout << "Enter Total Cash : ";
		float totalCash;
		in >> totalCash;
		file << totalCash << ",";

		cout << "Enter Fee Per Transaction : ";
		float fee;
		in >> fee;
		file << fee << ",";

		CheckingAccount CAccount(BankName, BranchName, totalCash, fee);
		U.setBankAccount(&CAccount);
		break;
	}
	case 2:
	{
		file << "Saving,";

		cout << "Enter Bank Name : ";
		char BankName[30];
		cin.ignore();
		in.getline(BankName, 30);
		file << BankName << ",";

		cout << "Enter Branch Name : ";
		char BranchName[30];
		in.getline(BranchName, 30);
		file << BranchName << ",";

		cout << "Enter Total Cash : ";
		float totalCash;
		in >> totalCash;
		file << totalCash << ",";

		cout << "Enter Interest Rate : ";
		float interest;
		in >> interest;
		file << interest << ",";

		SavingAccount SAccount(BankName, BranchName, totalCash, interest);
		U.setBankAccount(&SAccount);
		break;
	}
	default:
	{
		cout << "Wrong Input!\n\n";
		goto Choice;
	}
	}

	cout << "\nCongratulations! Your Account Has Been Created Successfully \n";
	U.C1.setRanCardNum();
	cout << "Your ATM Card Number is " << U.C1.getCardNum() << endl;
	file << U.C1.getCardNum() << ",";

	cout << "Set PIN for your Card : ";
	int pin;
	in >> pin;
	U.C1.setPIN(pin);
	file << pin << "\n";

	file.close();

	cout << "\nAccount Created Successfully!\n\n";
	return in;
}

ostream& operator <<(ostream& out, User& U) {
	out << "\n\nAccount Info : \n";
	out << "Full Name : " << U.getName() << endl;
	out << "Phone Number : " << U.getPhoneNumber() << endl;
	out << "Address : " << U.getAddress() << endl;
	
	out << "Bank Name : " << U.Bank->getBankName() << endl;
	out << "Branch : " << U.Bank->getBranch() << endl;
	out << "Total Cash : " << U.Bank->getTotalCash() << endl;

	out << "Card Number : " << U.C1.getCardNum() << endl;
	out << "PIN : " << U.C1.getPIN() << endl;

	return out;
}

User fetchUserData(ifstream& file) {
	User U;

	char Name[30];
	file.getline(Name, 30, ',');
	U.setName(Name);

	double PhoneNumber;
	file >> PhoneNumber;
	U.setPhoneNumber(PhoneNumber);

	char Address[30];
	file.ignore();
	file.getline(Address, 30, ',');
	U.setAddress(Address);

	char type[10];
	file.getline(type, 10, ',');

	char BankName[30];
	file.getline(BankName, 30, ',');

	char BranchName[30];
	file.getline(BranchName, 30, ',');

	float totalCash;
	file >> totalCash;

	if (type == "Checking") {
		float fee;
		file.ignore();
		file >> fee;

		CheckingAccount CAccount(BankName, BranchName, totalCash, fee);
		U.setBankAccount(&CAccount);
	}
	else {
		float interest;
		file.ignore();
		file >> interest;

		SavingAccount SAccount(BankName, BranchName, totalCash, interest);
		U.setBankAccount(&SAccount);
	}

	/*U.Bank->setBankName(BankName);
	U.Bank->setBranch(BranchName);
	U.Bank->setTotalCash(totalCash);*/

	int CardNumber;
	file.ignore();
	file >> CardNumber;
	U.C1.setCardNum(CardNumber);

	int pin;
	file.ignore();
	file >> pin;
	U.C1.setPIN(pin);

	
	return U;
}
