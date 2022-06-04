#pragma once
#include"User.h"
#include"Functions.h"
#include<iostream>

using namespace std;

class ATM
{
protected:
	User U;
public:
	ATM();
	ATM(User);

	friend ostream& operator<<(ostream&, User&);

	/*virtual int displayMenu() = 0;
	virtual void performTask() = 0;*/
	bool validateData(User&);
};

