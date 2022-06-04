#include "User.h"

User::User() {
	name = nullptr;
	address = nullptr;
	phoneNumber = 0;
	Bank = nullptr;
	C1.setPIN(0);
	C1.setRanCardNum();
}
User::User(char* N, double P, char* A, char* BN, char* Branch, float C, int PIN) {
	name = N;
	address = A;
	phoneNumber = P;
	Bank = new BankAccount;
	Bank->setBankName(BN);
	Bank->setBranch(Branch);
	Bank->setTotalCash(C);
	C1.setPIN(PIN);
	C1.setRanCardNum();
}

void User::setName(char* Name) {
	char* temp = new char[30];
	int i;
	for (i = 0; Name[i] != '\0'; i++)
	{
		temp[i] = Name[i];
	}
	temp[i] = '\0';
	name = temp;
}
void User::setAddress(char* Address) {
	char* temp = new char[30];
	int i;
	for (i = 0; Address[i] != '\0'; i++)
	{
		temp[i] = Address[i];
	}
	temp[i] = '\0';
	address = temp;
}
void User::setPhoneNumber(double PhoneNumber) {
	phoneNumber = PhoneNumber;
}
void User::setBankAccount(BankAccount* b) {
	BankAccount* temp = new BankAccount;
	temp->setBankName(b->getBankName());
	temp->setBranch(b->getBranch());
	temp->setTotalCash(b->getTotalCash());
	Bank = temp;
}

char* User::getName() const {
	char* temp = new char[30];
	int i;
	for (i = 0; name[i] != '\0'; i++)
	{
		temp[i] = name[i];
	}
	temp[i] = '\0';
	return temp;
}
char* User::getAddress() const {
	char* temp = new char[30];
	int i;
	for (i = 0; address[i] != '\0'; i++)
	{
		temp[i] = address[i];
	}
	temp[i] = '\0';
	return temp;
}
double User::getPhoneNumber() const {
	return phoneNumber;
}
BankAccount* User::getBankAccount() const {
	BankAccount* temp = new BankAccount;
	temp->setBankName(Bank->getBankName());
	temp->setBranch(Bank->getBranch());
	temp->setTotalCash(Bank->getTotalCash());
	return temp;
}


User& User::operator=(const User& u) {
	this->setName((u.name));
	this->setAddress(u.address);
	this->setPhoneNumber(u.phoneNumber);

	this->setBankAccount(u.getBankAccount());
	/*this->Bank->setBankName((u.Bank->getBankName()));
	this->Bank->setBranch(u.Bank->getBranch());
	this->Bank->setTotalCash(u.Bank->getTotalCash());*/

	this->C1.setCardNum(u.C1.getCardNum());
	this->C1.setPIN(u.C1.getPIN());

	return *this;
}

User& User::operator - (User& U) {
	cout << "Enter Amount of Cash to Withdraw : ";
	float cash;
	cin >> cash;


	float total = U.Bank->getTotalCash();
	this->Bank->setTotalCash((total - cash));

	cout << "\nAmount Withdrawn Successfully!\n";
	cout << "Total Balance Now : " << this->Bank->getTotalCash() << endl;
	return U;
}
User& User::operator * (User& U) {
	cout << "Total Balance : " << U.Bank->getTotalCash() << endl;
	return U;
}
User& User::operator % (User& U) {
	cout << "Enter Amount of Cash to Transfer : ";
	float cash;
	cin >> cash;

	cout << "Enter Card Number to Transfer to : ";
	int num;
	cin >> num;

	float total = U.Bank->getTotalCash();
	this->Bank->setTotalCash((total - cash));

	cout << "\nAmount Transfered to " << num << " Successfully!\n";
	cout << "Total Balance Now : " << this->Bank->getTotalCash() << endl;
	return U;
}
User& User::operator ^ (User& U) {
	A:
	cout << "\nEnter Your Old PIN to continue : ";
	int old;
	cin >> old;

	if (old == U.C1.getPIN()) {
		B:
		cout << "\nEnter New PIN : ";
		int new1;
		cin >> new1;
		cout << "\nConfirm Your New PIN : ";
		int new2;
		cin >> new2;
		if (new1 == new2) {
			cout << "\nPIN Changed Successfully!\n";
			U.C1.setPIN(new1);
		}
		else {
			cout << "\nNew Passwords Do Not Match!\n";
			goto B;
		}
	}
	else {
		cout << "\nWrong Old PIN!\n";
		goto A;
	}
	return U;
}