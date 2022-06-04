#include "SavingAccount.h"

SavingAccount::SavingAccount() {
	InterestRate = 0;
}
SavingAccount::SavingAccount(char* BN, char* Branch, float C, float R)
	:BankAccount(BN, Branch, C)
{
	setInterestRate(R);
}
void SavingAccount::setInterestRate(float R) {
	InterestRate = R;
}
float SavingAccount::getInterestRate() const {
	return InterestRate;
}
void SavingAccount::calcInterest() const {
	int cash = getTotalCash();
	cash *= (getInterestRate() / 100);
	cout << "Total Cash with Interest : " << cash << endl;
}