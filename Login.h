#include "AccountList.h"
#include <conio.h>

void inputPassword(string &password)
{
    fflush(stdin);

    password = "";
    int temp;
    while (temp = getch())
    {
        if (temp == 13)
        {
            break;
        }
        else if (temp == 8)
        {
            if (password.length() > 8)
            {
                cout << "\b\b";
                password.erase(password.length() - 1);
            }
        }
        else
        {
            cout << "*";
            password += temp;
        }
    }
    cout << endl;
}

bool signUp(AccountList *accountList)
{
    string nameUser;
    string password;
    cout << "\n<<< SIGN UP SCREEN >>>\n";
    cout << "Enter your name user: ";
    cin >> nameUser;
    while (accountList->checkExist(nameUser))
    {
        cout << "Name user has existed. " << endl;
        cout << "Enter your name user: ";
        cin >> nameUser;
    }
    cout << "Enter your password: ";
    inputPassword(password);
    cout << "signUp success." << endl;
    Account *temp = new Account(nameUser, password);
    accountList->pushBack(temp);


    return 1;
}
Account *logIn(const AccountList *accountList)
{
    cout << "\n<<< LOG IN SCREEN >>>\n";
    string nameUser;
    string password;
    bool checkNameUser = false;
    bool checkPassword = false;
    bool func;
    int posAccount;
    int checkAgain = 3;
    cout << "Enter your name user: ";
    cin >> nameUser;
    cout << "Enter your password: ";
    // cin >> password;
    inputPassword(password);

    while (!accountList->check(nameUser, checkNameUser, password, checkPassword))
    {
        if (checkNameUser == 0)
        {
            cout << "Error: name user is not found." << endl;
            ////
            /*
            cout << "Do you want to exit? Press 0. To continue press 1" << endl;
            cin >> func;
            if (func == 0)
                return 0;
                */
            ////
            checkAgain = 3;
            cout << "Enter your name user: ";
            cin >> nameUser;
            cout << "Enter your password: ";
            // cin >> password;
            inputPassword(password);
        }
        else
        {
            cout << "Error: password is incorrect." << endl;
            ////
            /*
            cout << "Do you want to exit? Press 0. To continue press 1" << endl;
            cin >> func;
            if (func == 0)
                return 0;
                */
            ////
            if (--checkAgain)
            {
                cout << "Enter your password: ";
                // cin >> password;
                inputPassword(password);
            }
            else
            {
                cout << "You lost too much. Please wait 5 minutes to login again..." << endl;
                ////
                /*
                cout << "Do you want to exit? Press 0. To continue press 1" << endl;
                cin >> func;
                if (func == 0)
                    return 0;
                    */
                ////
                checkAgain = 3;
                Sleep(15000);
                cout << "Enter your name user: ";
                cin >> nameUser;
                cout << "Enter your password: ";
                // cin >> password;
                inputPassword(password);
            }
        }
    }

    return accountList->find(posAccount);
    // return nullptr;
}
bool logOut(Account **account)
{
    *account = NULL;
    account = NULL;
    return 1;
}