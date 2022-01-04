#include "Taxi.h"

Taxi::Taxi(string ID, string locationStart, string locationEnd, string time, string type, double cost, string driver, string licensePlate, bool current) : Transport(ID, locationStart, locationEnd, time, type, cost, driver, licensePlate)
{
    this->_current = current;
}

bool Taxi::book()
{
    if (this->_current == true)
        return 0;

    this->_current = true;
    return 1;
}
bool Taxi::cancel()
{
    this->_current = false;
    return 1;
}
bool Taxi::checkAvailable()
{
    // ** Nếu Grab chưa được đặt, ta return 1
    if (this->_current == true)
        return 1;
    return 0;
}
bool Taxi::isFull()
{
    return this->_current;
}
void Taxi::getInfo(json &j)
{
    json k;
    this->getBasicInfo(k);
    k["Current"] = this->_current;
    j.push_back(k);
}