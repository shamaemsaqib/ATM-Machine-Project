#include "CheckingAccount.h"

CheckingAccount::CheckingAccount() {
	feePerTransaction = 0;
}
CheckingAccount::CheckingAccount(char* BN, char* Branch, float C, float F)
	:BankAccount(BN, Branch, C)
{
	setFee(F);
}
void CheckingAccount::setFee(float F) {
	feePerTransaction = F;
}
float CheckingAccount::getFee() const {
	return feePerTransaction;
}