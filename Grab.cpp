#include "Grab.h"

Grab::Grab(string ID, string locationStart, string locationEnd, string time, string type, double cost, string driver, string licensePlate, bool current) : Transport(ID, locationStart, locationEnd, time, type, cost, driver, licensePlate)
{
    this->_current = current;
}

bool Grab::book()
{
    if (this->_current == true)
        return 0;

    this->_current = true;
    return 1;
}
bool Grab::cancel()
{
    this->_current = false;
    return 1;
}
bool Grab::checkAvailable()
{
    // ** Nếu Grab chưa được đặt, ta return 1
    if (this->_current == true)
        return 1;
    return 0;
}
bool Grab::isFull()
{
    return this->_current;
}
void Grab::getInfo(json &j)
{
    json k;
    this->getBasicInfo(k);
    k["Current"] = this->_current;
    j.push_back(k);
}