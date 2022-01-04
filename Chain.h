#pragma once
#include "Account.h"

class AccountNode
{
public:
    Account *_key;
    AccountNode *_next;

public:
    AccountNode();
    AccountNode(Account *key);
    ~AccountNode();
    // ! mới nè
public:
    AccountNode &operator==(AccountNode *accountNode);

public:
    void getInfo(json &j);
    bool checkUsername(Account *account);
    bool checkPassword(Account *account);
    bool delNode(AccountNode *accountNode);
};

class Chain
{
public:
    // Khởi tạo
    // Truyền địa chỉ file lưu thông tin đăng nhập.
    Chain();
    ~Chain();

public:
    // Thực hiện kiểm tra từng thành phần
    virtual void setChecker(Chain *nextChain) = 0;
    virtual bool check(AccountNode *accountNode, Account *account, char &cases) = 0;
};
