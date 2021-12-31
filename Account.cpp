#include "Account.h"

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
}
Account *createAccount()
{
    string nameUser;
    string password;
    cout << "Input Username: ";
    cin >> nameUser;
    cout << "Input password: ";
    inputPassword(password);
    return new Account(nameUser, password);
}
Account *createDetailAccount()
{
    string nameUser;
    string password;
    string ID;
    string name;
    string birth;
    bool sex;
    string phone;

    cout << "Input Username: ";
    cin >> nameUser;
    cout << "Input password: ";
    inputPassword(password);
    cout << "Input ID: ";
    cin >> ID;
    cin.ignore();
    cout << "Input your name: ";
    getline(cin, name);
    cout << "Input your birth: ";
    cin >> birth;
    cout << "Input your sex: ";
    cin >> sex;
    cout << "Input your phone: ";
    cin >> phone;
    return new Account(nameUser, password, ID, name, birth, sex, phone);
}

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