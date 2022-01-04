#pragma once
#include "LIBLogin.h"

void inputPassword(string &password);
bool signUp(LinkedListAccount *linkedList);
Account *logIn(LinkedListAccount *linkedList);
bool changeInfo(Account *account);
bool changePass(Account *account);
bool logOut(Account **account);
