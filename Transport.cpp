#include "Transport.h"

Transport::Transport(string ID, string locationStart, string locationEnd, string time, string type, double cost, string driver, string licensePlate)
{
    this->_ID = ID;
    this->_locationStart = locationStart;
    this->_locationEnd = locationEnd;
    Time *temp = new Time(time);
    this->_time = *temp;
    this->_type = type;
    this->_cost = cost;
    this->_driver = driver;
    this->_licensePlate = licensePlate;
    delete temp;
}
string Transport::info()
{
    string res = this->_ID;
    res = res + '|';
    res = res + this->_type;
    res = res + '|';
    res = res + this->_locationStart;
    res = res + '|';
    res = res + this->_locationEnd;
    res = res + '|';
    res = res + to_string(this->_cost);
    return res;
}
string Transport::receipt()
{
    string res = this->info();
    res = res + '|';
    res = res + this->_driver;
    res = res + '|';
    res = res + this->_licensePlate;
    return res;
}
void Transport::showAvailable(list<Transport *> &transport, Time time)
{
    if (!this->isFull() && time == this->_time)
        transport.push_back(this);
}
void Transport::showAvailable(list<Transport *> &transport, string locationStart, string locationEnd)
{
    if (!this->isFull() && locationStart == this->_locationStart)
    {
        if (locationEnd == this->_locationEnd)
            transport.push_front(this);
        else
            transport.push_back(this);
    }
}
void Transport::showAvailable(list<Transport *> &transport, Time time, string locationStart, string locationEnd)
{
    if (!this->isFull())
    {
        if (time == this->_time && locationStart == this->_locationStart && locationEnd == this->_locationEnd)
            transport.push_front(this);
        if (time == this->_time)
            transport.push_back(this);
        if (locationStart == this->_locationStart && locationEnd == this->_locationEnd)
            transport.push_back(this);
    }
}
void Transport::getBasicInfo(json &j)
{
    j["ID"] = this->_ID;
    j["LocationStart"] = this->_locationStart;
    j["LocationEnd"] = this->_locationEnd;
    j["Time"] = this->_time.stringTime();
    j["Type"] = this->_type;
    j["Cost"] = this->_cost;
    j["Driver"] = this->_driver;
    j["LicensePlate"] = this->_licensePlate;
}
int calculate(string type)
{
    if (type[0] == 'B')
    {
        if (type[1] == '1')
            return 20;
        else if (type[1] == '2')
            return 30;
        else
            return 50;
    }
    else if (type[0] == 'G')
    {
        return 1;
    }
    else if (type[0] == 'T')
    {

        if (type[1] == '1')
            return 4;
        else if (type[1] == '2')
            return 5;
        else
            return 7;
    }
}