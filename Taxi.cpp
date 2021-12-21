#include "Taxi.h"

Taxi::Taxi(string ID, string locationStart, string locationEnd, string time, int type, double cost) : Transport(ID, locationStart, locationEnd, time, type, cost)
{
    this->_current = false;
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
void Taxi::showAvailable(vector<Tranport *> &transport, Time time)
{
    if (this->_current == false && time == this->_time)
        transport.push_back(this);
}
void Taxi::showAvailable(vector<Tranport *> &transport, string locationStart, string locationEnd)
{
    if (this->_current == false && locationStart == this->_locationStart && locationEnd == this->_locationEnd)
        transport.push_back(this);
}
void Taxi::showAvailable(vector<Tranport *> &transport, Time time, string locationStart, string locationEnd)
{
    if (this->_current == false && time == this->_time && locationStart == this->_locationStart && locationEnd == this->_locationEnd)
        transport.push_back(this);
}