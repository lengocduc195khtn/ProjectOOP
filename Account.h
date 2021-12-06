#pragma once
// #include "AccountList.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <iomanip>
#include "json/json.hpp"
#include <fstream>

#include <deque>
#include <list>
#include <unordered_set>

using namespace std;
using json = nlohmann::json;

class Account
{
private:
    string _nameUser;
    string _password;
    /*
        string _ID;
        string _name;
        string _birthdate;
        string _phone;*/
    // vector<Hotel*> _hotel;
    // vector<Tranport*> _tranport;
    // vector<Flight*> _flight;
public:
    void getInfo(json &j)
    {
        json k;
        k["NameUser"] = this->_nameUser;
        k["Password"] = this->_password;

        j.push_back(k);
    }
    /*
        bool updateInfoUser(string ID, string name, string date, string phone)
        {
            this->_ID = ID;
            this->_name = name;
            this->_birthdate = date;
            this->_phone = phone;
            return 1;
        }
        void printinfo()
        {
            cout << setw(10) << "Full name:" << this->_name << endl;
            cout << setw(10) << "Birthdate:" << this->_birthdate << endl;
            cout << setw(10) << "Phone:" << this->_phone << endl;
        }*/

public:
    Account(string nameUser, string password)
    {
        this->_nameUser = nameUser;
        this->_password = password;
    }
    ~Account()
    {
    }
    /*
    bool updateInfoTranport(vector<Tranport*> tranport)
    {
    }
    */
    bool operator==(const Account *account)
    {
        if (account->_nameUser != this->_nameUser || account->_password != this->_password)
            return 0;
        return 1;
    }

public:
    bool checkNameUser(string nameUser)
    {
        return this->_nameUser == nameUser;
    }
    bool checkPassword(string password)
    {
        return this->_password == password;
    }
    void print()
    {
        cout << "User:" << this->_nameUser << endl;
        cout << "Pass:" << this->_password << endl;
    }

protected:
    template <class T>
    bool deleteAccount(T &accountList);
};
