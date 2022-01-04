#include "Chain.h"

AccountNode::AccountNode()
{
    this->_key = NULL;
    this->_next = NULL;
}
AccountNode::AccountNode(Account *key)
{
    this->_key = key;
    this->_next = NULL;
}
AccountNode::~AccountNode()
{
    delete this->_key;
    this->_key = NULL;
}
AccountNode &AccountNode::operator==(AccountNode *accountNode)
{
    this->_key = accountNode->_key;
    this->_next = accountNode->_next;
    return *this;
}
bool AccountNode::delNode(AccountNode *accountNode)
{
    delete accountNode->_key;
    accountNode->_key = NULL;
    this->_next = accountNode->_next;
    delete accountNode;
    accountNode = NULL;
    return true;
}
void AccountNode::getInfo(json &j)
{
    this->_key->getInfo(j);
}
bool AccountNode::checkUsername(Account *account)
{
    return this->_key->checkUsername(*account);
}
bool AccountNode::checkPassword(Account *account)
{
    return this->_key->checkPassword(*account);
}
Chain::Chain()
{
}
Chain::~Chain()
{
}
