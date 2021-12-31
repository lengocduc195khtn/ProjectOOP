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
