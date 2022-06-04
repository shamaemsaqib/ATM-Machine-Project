#pragma once
#include<iostream>

class Card
{
private:
	int CardNumber;
	int PIN;
public:
	Card();
	Card(int);

	void setRanCardNum();
	void setCardNum(int);
	void setPIN(int);

	int getCardNum() const;
	int getPIN() const;
};

