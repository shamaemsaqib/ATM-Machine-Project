#include "BasicATM.h"

BasicATM::BasicATM() {
	
}
BasicATM::BasicATM(User u)
	:ATM(u)
{

}

int BasicATM::displayMenu() {
	cout << "Select your transaction" << endl;
	cout << "1. Press 1 to withdrawal" << endl;
	cout << "2. Press 2 to display information" << endl;
	int choice;
	cin >> choice;
	return choice;
}
void BasicATM::performTask() {
	int choice = displayMenu();
	switch (choice)
	{
	case 1:
		U - U;
		break;
	case 2:
		cout << U;
		break;
	default:
		cout << "Wrong Input!" << endl;
	}
}
