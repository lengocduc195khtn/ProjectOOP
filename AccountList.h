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

    Account *find(string nameUser) const
    {
        for (int i = 0; i < this->_size; i++)
            if (this->_list[i]->checkNameUser(nameUser))
                return this->_list[i];
        return NULL;
    }
    bool checkExist(string nameUser)
    {
        for (int i = 0; i < this->_size; i++)
            if (this->_list[i]->checkNameUser(nameUser))
                return 1;
        return 0;
    }
    bool check(string nameUser, bool &checkName, string password, bool &checkPassword) const
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
                    return 1;
                }
                else
                {
                    checkPassword = 0;
                    return 0;
                }
            }
        }
        return 0;
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
private:
    void readFileJson(string address)
    {
        json j;

        fstream f;
        f.open(address, ios::in | ios::binary);
        f >> j;
        // iterate the array
        for (json::iterator it = j.begin(); it != j.end(); ++it)
        {
            Account *account = new Account(it->at("NameUser"), it->at("Password"));
            this->pushBack(account);
        }

        f.close();
    }
    void updateDatabase(string address)
    {
        json j;
        for (int i = 0; i < this->_size; i++)
        {
            this->_list[i]->getInfo(j);
        }

        fstream f;
        f.open(address, ios::out | ios::binary);
        f << setw(4) << j;
        f.close();
    }

public:
    void readFile()
    {
        this->readFileJson("list.json");
    }

    // ** Hàm này được sử dụng để cập nhật dữ liệu trong ngày, có thể bao gồm việc thêm, xóa bất kì.
    // ** Trên thực tế nó không thực tế trong quá trình truy cập thời gian thực (thông tin thay đổi liên tục).
    // ?? Hàm này tối ưu cho việc xóa dữ liệu từ database
    void update()
    {
        this->updateDatabase("list.json");
    }
};