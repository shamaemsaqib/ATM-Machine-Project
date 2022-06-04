#include "BankAccount.h"

BankAccount::BankAccount() {
	BankName = nullptr;
	Branch = nullptr;
	TotalCash = 0;
}
BankAccount::BankAccount(char* name, char* branch, float cash) {
	setBankName(name);
	setBranch(branch);
	setTotalCash(cash);
}
void BankAccount::setBankName(char* name){
	char* temp = new char[30];
	int i;
	for (i = 0; name[i] != '\0'; i++)
	{
		temp[i] = name[i];
	}
	temp[i] = '\0';
	BankName = temp;
}
void BankAccount::setBranch(char* branch) {
	char* temp = new char[30];
	int i;
	for (i = 0; branch[i] != '\0'; i++)
	{
		temp[i] = branch[i];
	}
	temp[i] = '\0';
	Branch = temp;
}
void BankAccount::setTotalCash(float cash) {
	TotalCash = cash;
}
char* BankAccount::getBankName() const {
	char* temp = new char[30];
	int i;
	for (i = 0; BankName[i] != '\0'; i++)
	{
		temp[i] = BankName[i];
	}
	temp[i] = '\0';
	return temp;
}
char* BankAccount::getBranch() const {
	char* temp = new char[30];
	int i;
	for (i = 0; Branch[i] != '\0'; i++)
	{
		temp[i] = Branch[i];
	}
	temp[i] = '\0';
	return temp;
}
float BankAccount::getTotalCash() const {
	return TotalCash;
}