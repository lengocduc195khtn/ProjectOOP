#include "Time.h"

Time::Time()
{
}
Time::Time(string time)
{
    this->_h = 'a' + (10 * (time[0] - '0') + (time[1] - '0'));
    this->_m = 'a' + (10 * (time[2] - '0') + (time[3] - '0'));
    this->_s = 'a' + (10 * (time[4] - '0') + (time[5] - '0'));
}
Time::~Time()
{
}

string Time::stringTime()
{
    string res = to_string(this->_h - 'a');
    res = res + to_string(this->_m - 'a');
    res = res + to_string(this->_s - 'a');
    return res;
}
bool Time::operator==(const Time &time)
{
    if (this->_h == time._h && this->_m == time._m && this->_s == time._s)
        return true;
    return false;
}
Time &Time::operator=(const Time &time)
{
    this->_h = time._h;
    this->_m = time._m;
    this->_s = time._s;
    return *this;
}