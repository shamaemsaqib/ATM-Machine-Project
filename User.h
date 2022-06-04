#pragma once
#include"BankAccount.h"
#include"Card.h"
#include"SavingAccount.h"
#include"CheckingAccount.h"

class User
{
protected:
	char* name;
	double phoneNumber;
	char* address;
	BankAccount* Bank;
	Card C1;
public:
	User();
	User(char*, double, char*, char*, char*, float, int);

	friend class ATM;
	friend istream& operator>>(istream&, User&);
	friend ostream& operator<<(ostream&, User&);
	friend User fetchUserData(ifstream&);
	User& operator=(const User&);
	User& operator - (User&);
	User& operator * (User&);
	User& operator % (User&);
	User& operator ^ (User&);

	void setName(char*);
	void setPhoneNumber(double);
	void setAddress(char*);
	void setBankAccount(BankAccount*);

	char* getName() const;
	double getPhoneNumber() const;
	char* getAddress() const;
	BankAccount* getBankAccount() const;

};

