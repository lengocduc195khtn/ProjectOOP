#include "Login.h"
#include "TransportList.h"
int Account::_num = 0;
int PasswordChecker::_count = 0;
int main()
{

  LinkedListAccount *linkedList = new LinkedListAccount;
  linkedList->readFileJson("loginInfo.json");
  //      signUp(linkedList);
  Account *currentAccount = logIn(linkedList);
  //      cout << currentAccount->print();
  //      logOut(&currentAccount);
  //     linkedList->updateDatabase("loginInfo.json");
  system("pause");
  return 0;
}