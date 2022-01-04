#include "Transport.h"

Transport::Transport(string ID, string locationStart, string locationEnd, string time, string type, double cost, string driver, string licensePlate)
{
    this->_ID = ID;
    this->_locationStart = locationStart;
    this->_locationEnd = locationEnd;
    Time* temp = new Time(time);
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
vector<Transport*> Transport::showAvailable(vector<Transport*> transport, Time time, string locationStart, string locationEnd)
{
    vector<Transport*> res;
    for (auto item : transport) {
        if (item->isFull())
            continue;
        if (locationStart == item->_locationStart && locationEnd == item->_locationEnd)
            if (time == item->_time)// prioritize base on time
                res.insert(res.begin(), item);
            else
                res.push_back(item);
    }
    return res;
}
void Transport::getBasicInfo(json& j)
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