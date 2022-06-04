#include "Card.h"
#include<time.h>

Card::Card() {
	CardNumber = 0;
	PIN = 0;
}
Card::Card(int p) {
	setRanCardNum();
	PIN = p;
}
void Card::setRanCardNum() {
	int num;
	srand(time(NULL));
	num = rand() % 9000 + 1000;
	setCardNum(num);
}
void Card::setCardNum(int num) {
	CardNumber = num;
}
void Card::setPIN(int n) {
	PIN = n;
}
int Card::getCardNum() const {
	return CardNumber;
}
int Card::getPIN() const {
	return PIN;
}
