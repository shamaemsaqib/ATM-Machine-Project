#pragma once
#include"ATM.h"
#include"Functions.h"

class BasicATM : public ATM
{
private:
	int displayMenu();
public:
	BasicATM();
	BasicATM(User);

	void performTask();
};

