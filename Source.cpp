#include"ComplexATM.h"
#include"BasicATM.h"
#include"User.h"
#include"CheckingAccount.h"
#include"SavingAccount.h"
#include"Functions.h"

int main() {
	Opening();
	MENU:
	Menu();
	int choice;
	cin >> choice;

	User U;
	int choice2;

	switch (choice) {
	case 1:
		NewUser();
		cin >> U;
		break;
	case 2:
	{
	Login:
		LogIn();
		ATM temp;
		if (temp.validateData(U)) {
			cout << "\n\nLogged In Successfully!\n";
		}
		else
		{
			cout << "Invalid Card Number or Password!\n";
			goto Login;
		}
		break;
	}
	case 3:
		exitProgram();
		break;
	default:
		cout << "Wrong Input!";
		cout << "\n----------------------------------------";
		goto MENU;
	}
A:
	ATMChoice();
	cin >> choice2;
	switch (choice2)
	{
	case 1:
	{
		cout << "a";
		BasicATM BAtm(U);
		cout << "b";
		BAtm.performTask();
		goto A;
		break;
	}
	case 2:
	{
		ComplexATM CAtm(U);
		CAtm.performTask();
		goto A;
		break;
	}
	case 3:
		goto MENU;
	case 4:
		exitProgram();
		break;
	default:
		cout << "Wrong Input!";
		cout << "\n----------------------------------------";
		goto A;
	}

	goto MENU;

	return 0;
}