#pragma once
#include<iostream>

using namespace std;

class BankAccount
{
private:
	char* BankName;
	char* Branch;
	float TotalCash;
public:
	BankAccount();
	BankAccount(char*, char*, float);

	void setBankName(char*);
	void setBranch(char*);
	void setTotalCash(float);

	char* getBankName() const;
	char* getBranch() const;
	float getTotalCash() const;
};

