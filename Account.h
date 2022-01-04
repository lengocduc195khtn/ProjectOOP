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
    string print();

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
    bool changeInfo(string password);
    bool changePassword(string password);
};

Account *createAccount(string username, string password);
Account *createDetailAccount(string username, string password, string ID, string name, string birth, bool sex, string phone);
// void inputPassword(string &password);

//** bool checkConditionUsername(string username);
//**  bool checkConditionPassword(string password);