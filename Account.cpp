#include "Account.h"

Account::Account()
{
}
Account::Account(string nameUser, string password)
{
    this->_username = nameUser;
    this->_password = password;
}
Account::Account(string nameUser, string password, string ID, string name, string birth, bool sex, string phone)
{
    this->_username = nameUser;
    this->_password = password;
    this->_ID = ID;
    this->_name = name;
    this->_birth = birth;
    this->_sex = sex;
    this->_phone = phone;
}
Account::~Account()
{
}
void Account::getInfo(json &j)
{
    json k;
    k["ID"] = this->_ID;
    k["Username"] = this->_username;
    k["Password"] = this->_password;
    k["Name"] = this->_name;
    k["Birth"] = this->_birth;
    k["Sex"] = this->_sex;
    k["Phone"] = this->_phone;

    j.push_back(k);
}
string Account::print()
{
    string res = this->_ID;
    res = res + '|';
    int i = 0;
    int n = this->_name.length();
    while (i < n)
    {
        res = res + this->_name[i];
        i++;
    }
    res = res + '|';
    i = 0;
    n = this->_birth.length();
    while (i < n)
    {
        res = res + this->_birth[i];
        i++;
    }
    res = res + '|';
    if (this->_sex == 0)
        res = res + '0';
    else
        res = res + '1';
    res = res + '|';
    i = 0;
    n = this->_phone.length();
    while (i < n)
    {
        res = res + this->_phone[i];
        i++;
    }
    return res;
}
bool Account::operator==(const Account &account)
{
    if (account._username != this->_username || account._password != this->_password)
        return 0;
    return 1;
}
Account &Account::operator=(const Account &account)
{
    this->_username = account._username;
    this->_password = account._password;
    this->_ID = account._ID;
    this->_name = account._name;
    this->_birth = account._birth;
    this->_sex = account._sex;
    this->_phone = account._phone;
}
bool Account::checkUsername(const Account &account)
{
    return this->_username == account._username;
}
bool Account::checkPassword(const Account &account)
{
    return this->_password == account._password;
}
bool Account::changeInfo(string password)
{
    if (password != this->_password)
        return false;
    string ID, name, birth, phone;
    bool sex;
    this->_ID = ID;
    this->_name = name;
    this->_birth = birth;
    this->_sex = sex;
    this->_phone = phone;
    return true;
}
bool Account::changePassword(string password)
{
    if (password != this->_password)
        return false;
    string newPass;
    string checkAgain;
    if (checkConditionPassword(newPass) && newPass != this->_password)
    {
        if (newPass == checkAgain)
        {
            this->_password = newPass;
        }
        else
            cout << "checkAgain is incorrect." << endl;
    }
}
/*
void Account::print()
{
    cout << "ID: " << this->_ID << endl;
    cout << "Username: " << this->_username << endl;
    cout << "Password: " << this->_password << endl;
    cout << "ID: " << this->_ID << endl;
    cout << "Name: " << this->_name << endl;
    cout << "Birth: " << this->_birth << endl;
    cout << "Sex: " << this->_sex << endl;
    cout << "Phone: " << this->_phone << endl;
}*/
Account *createAccount(string username, string password)
{
    if (checkConditionUsername(username) && checkConditionPassword(password))
        return new Account(username, password);
    return NULL;
}
Account *createDetailAccount(string username, string password, string ID, string name, string birth, bool sex, string phone)
{
    if (checkConditionUsername(username) && checkConditionPassword(password))
        return new Account(username, password, ID, name, birth, sex, phone);
    return NULL;
}
/*
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
*/