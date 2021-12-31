#include "Login.h"

bool signUp(LinkedListAccount *accountList)
{
    Account *account = createAccount();
    while (accountList->isExistUsername(account))
    {
        cout << "Username is available." << endl;
        delete account;
        account = createAccount();
        /*
        cout << "___List___" << endl;
        accountList->printList();
        cout << endl;
        */
    }
    delete account;
    account = createDetailAccount();
    accountList->addNode(new AccountNode(account));
    cout << "Register is successful." << endl;
    /*
    cout << "___List___" << endl;
    accountList->printList();
    cout << endl;
    cout << "__________" << endl;
    */
    return 1;
}
Account *logIn(LinkedListAccount *linkedList)
{
    Account *account = createAccount();
    char cases;
    while (!linkedList->isExistAccount(account, cases))
    {
        if (cases == 'u')
            cout << "Username is incorrect." << endl;
        else
        {
            cout << "Password is incorrect." << endl;
            if (cases == 'l')
            {
                cout << "Lose too much. Please wait for 1 minute." << endl;
                Sleep(15000);
            }
        }
        account = createAccount();
        /*
        cout << "___List___" << endl;
        linkedList->printList();
        cout << endl;
        */
    }
    cout << "Log in is successful." << endl;
    return account;
}
bool logOut(Account **account)
{
    *account = NULL;
    account = NULL;
    return 1;
}