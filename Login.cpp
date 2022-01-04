#include "Login.h"

bool signUp(LinkedListAccount *accountList)
{
    string username, password;
    cin >> username;
    cin >> password;
    Account *account = createAccount(username, password);
    while (accountList->isExistUsername(account))
    {
        cout << "Username is available." << endl;
        delete account;
        cin >> username;
        cin >> password;
        account = createAccount(username, password);
        /*
        cout << "___List___" << endl;
        accountList->printList();
        cout << endl;
        */
    }
    delete account;
    string ID, name, phone, birth;
    bool sex;
    cout << "ID: ";
    cin >> ID;
    cout << "Name: ";
    cin.ignore();
    getline(std::cin, name);
    cout << "birth: ";
    cin >> birth;
    cout << "sex";
    cin >> sex;
    cout << "phone:";
    cin >> phone;
    account = createDetailAccount(username, password, ID, name, birth, sex, phone);
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
    string username = "lengocduc";
    string pass = "123";
    Account *account = createAccount(username, pass);
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
        account = createAccount(username, pass);
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
bool changeInfo(Account *account)
{
    string pass;
    return account->changeInfo(pass);
}
bool changePass(Account *account)
{
    string pass;
    return account->changePassword(pass);
}
