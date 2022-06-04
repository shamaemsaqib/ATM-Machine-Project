#pragma once
#include<istream>
#include"User.h"

using namespace std;

void Menu();
void Opening();
void NewUser();
void ATMChoice();
void LogIn();
void exitProgram();

User fetchUserData(ifstream&);

