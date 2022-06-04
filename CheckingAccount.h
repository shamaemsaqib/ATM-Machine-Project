#pragma once
#include"BankAccount.h"
class CheckingAccount : public BankAccount
{
private:
	float feePerTransaction;
public:
	CheckingAccount();
	CheckingAccount(char*, char*, float, float);

	void setFee(float);
	float getFee() const;
};

