#pragma once
#include "BankAccount.h"
class SavingAccount : public BankAccount
{
private:
	float InterestRate;
public:
	SavingAccount();
	SavingAccount(char*, char*, float, float);

	void calcInterest() const;
	void setInterestRate(float);
	float getInterestRate() const;
};