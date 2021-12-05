#pragma once
//#include "Login.h"
#include "Account.h"

class AccountList
{
private:
    int _size;
    vector<Account *> _list;

public:
    AccountList()
    {
        this->_size = 0;
    }
    ~AccountList()
    {
        // insert the account list to a user database 
        for (int i = 0; i < this->_size; i++)
            delete this->_list[i];

        this->_list.clear();
    }

public:
    void pushBack(Account *newAccount)
    {
        this->_size++;
        this->_list.push_back(newAccount);
    }

    Account *find(int position) const
    {
        return this->_list[position];
    }

    int check(string nameUser, bool &checkName, string password, bool &checkPassword) const
    {
        checkName = 0;

        for (int i = 0; i < this->_size; i++)
        {
            if (this->_list[i]->checkNameUser(nameUser))
            {
                checkName = 1;
                if (this->_list[i]->checkPassword(password))
                {
                    checkPassword = 1;
                    return i;
                }
                else
                {
                    checkPassword = 0;
                    return -1;
                }
            }
        }
        return -1;
    }
    bool erase(Account *account)
    {
        for (int i = 0; i < this->_size; i++)
            if (this->_list[i] == account)
            {
                this->_list.erase(this->_list.begin() + i);
                return 1;
            }
        return 0;
    }
    /*    friend bool Account::deleteAccount(AccountList &accountList)
        {
            for (int i = 0; i < accountList._size; i++)
                if (accountList._list[i] == this)
                {
                    accountList._list.erase(accountList._list.begin() + i);
                    return 1;
                }
            return 0;
        }*/
};