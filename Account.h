#pragma once
#include "LIB.h"
class Account
{
public:
    static int _num;

private:
    string _ID;
    string _username;
    string _password;
    string _name;
    string _birth;
    bool _sex;
    string _phone;
    // vector<Hotel*> _hotel;
    // vector<Tranport*> _tranport;
    // vector<Flight*> _flight;
public:
    void getInfo(json &j);

public:
    Account();
    Account(string nameUser, string password);
    Account(string nameUser, string password, string ID, string name, string birth, bool sex, string phone);
    ~Account();
    bool operator==(const Account &account);
    Account &operator=(const Account &account);

public:
    bool checkUsername(const Account &account);
    bool checkPassword(const Account &account);
    void print();

protected:
    template <class T>
    bool deleteAccount(T &accountList);
};

Account *createAccount();
Account *createDetailAccount();
void inputPassword(string &password);