#pragma once
#include"ATM.h"
#include"Functions.h"

class ComplexATM :public ATM
{
private:
	int displayMenu();
public:
	ComplexATM();
	ComplexATM(User);

	void performTask();
};

