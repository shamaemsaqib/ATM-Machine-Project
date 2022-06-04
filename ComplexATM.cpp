#include "ComplexATM.h"

ComplexATM::ComplexATM() {

}
ComplexATM::ComplexATM(User u)
	:ATM(u)
{

}

int ComplexATM::displayMenu() {
	cout << "Select your transaction" << endl;
	cout << "1. Press 1 to withdrawal" << endl;
	cout << "2. Press 2 for balance inquiry" << endl;
	cout << "3. Press 3 to transfer money" << endl;
	cout << "4. Press 4 to change your PIN" << endl;
	cout << "2. Press 5 to display information" << endl;
	int choice;
	cin >> choice;
	return choice;
}
void ComplexATM::performTask() {
	int choice = displayMenu();
	switch (choice)
	{
	case 1:
		U = U - U;
		break;
	case 2:
		U = U * U;
		break;
	case 3:
		U = U % U;
		break;
	case 4:
		U = U ^ U;
		break;
	case 5:
		cout << U;
		break;
	default:
		cout << "Wrong Input!" << endl;
	}
}