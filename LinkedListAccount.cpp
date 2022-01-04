#include "LinkedListAccount.h"

LinkedListAccount::LinkedListAccount()
{
    this->_head = NULL;
}
LinkedListAccount::~LinkedListAccount()
{
    if (this->_head == NULL)
        return;

    while (this->_head != NULL)
    {
        AccountNode *p = this->_head;
        this->_head = this->_head->_next;
        p->_next = NULL;
        delete p;
        p = NULL;
    }
}
void LinkedListAccount::readFileJson(string address)
{
    json j;
    fstream f;
    f.open(address, ios::in | ios::binary);
    f >> j;
    // iterate the array
    for (json::iterator it = j.begin(); it != j.end(); ++it)
    {
        Account *account = new Account(it->at("Username"), it->at("Password"), it->at("ID"), it->at("Name"), it->at("Birth"), it->at("Sex"), it->at("Phone"));
        this->addNode(new AccountNode(account));
    }

    f.close();
}
void LinkedListAccount::updateDatabase(string address)
{
    json j;
    AccountNode *p = this->_head;
    while (p != NULL)
    {
        p->getInfo(j);
        p = p->_next;
    }

    fstream f;
    f.open(address, ios::out | ios::binary);
    f << setw(4) << j;
    f.close();
}
/*
bool LinkedListAccount::findNodeWithName(AccountNode *accountNode, const Account &nameUser)
{
    return accountNode->_key->checkUsername(nameUser);
}
bool LinkedListAccount::findNodeWithPassword(AccountNode *accountNode, const Account &password)
{
    return accountNode->_key->checkPassword(password);
}
*/
void LinkedListAccount::addNode(AccountNode *accountNode)
{
    if (this->_head == NULL)
    {
        this->_head = accountNode;
        return;
    }
    AccountNode *p = this->_head;
    while (p->_next != NULL)
        p = p->_next;
    p->_next = accountNode;
}
void LinkedListAccount::delNode(AccountNode *accountNode)
{
    if (this->_head == NULL)
    {
        this->_head = accountNode;
        return;
    }
    AccountNode *p = this->_head;
    AccountNode *prev;
    while (p != NULL && p->_key != accountNode->_key)
    {
        prev = p;
        p = p->_next;
    }
    if (p != NULL)
        prev->delNode(accountNode);
}
void LinkedListAccount::getInfo(json &j)
{
    AccountNode *p = this->_head;
    while (p != NULL)
    {
        p->getInfo(j);
        p = p->_next;
    }
}
bool LinkedListAccount::isExistUsername(Account *account)
{
    if (this->_head == NULL)
        return false;
    AccountNode *p = this->_head;
    while (p != NULL && !p->checkUsername(account))
        p = p->_next;
    if (p == NULL)
        return false;
    return true;
}
bool LinkedListAccount::isExistAccount(Account *&account, char &cases)
{
    if (this->_head == NULL)
        return false;

    Chain *chain = new UserChecker();
    AccountNode *p = this->_head;
    while (p != NULL && !chain->check(p, account, cases) && cases == 'u')
        p = p->_next;
    if (p == NULL || cases == 'l' || cases == 'p')
        return false;
    delete account;
    account = p->_key;
    return true;
}
void LinkedListAccount::printList()
{
    if (this->_head == NULL)
        return;
    AccountNode *p = this->_head;
    while (p != NULL)
    {
        p->_key->print();
        p = p->_next;
    }
}
bool LinkedListAccount::cancelAccount(Account *account)
{
    string pass;
    Account *temp = new Account("", pass);
    if (!account->checkPassword(*temp))
        return false;
    AccountNode *p = new AccountNode(account);
    this->delNode(p);
    delete p;
    delete temp;
    return true;
}