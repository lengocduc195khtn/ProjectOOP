#include "Date.h"

Date::Date()
{
}
Date::Date(string time)
{
    this->_d = 'a' + (10 * (time[0] - '0') + (time[1] - '0'));
    this->_m = 'a' + (10 * (time[2] - '0') + (time[3] - '0'));
    this->_y1 = 'a' + (10 * (time[4] - '0') + (time[5] - '0'));
    this->_y2 = 'a' + (10 * (time[6] - '0') + (time[7] - '0'));
}
Date::~Date()
{
}

string Date::stringDate()
{
    string res = to_string(this->_d - 'a');
    res = res + to_string(this->_m - 'a');
    res = res + to_string(this->_y1 - 'a');
    res = res + to_string(this->_y2 - 'a');
    return res;
}
bool Date::operator==(const Date &time)
{
    if (this->_d == time._d && this->_m == time._m && this->_y1 == time._y1 && this->_y2 == time._y2)
        return true;
    return false;
}
Date &Date::operator=(const Date &time)
{
    this->_d = time._d;
    this->_m = time._m;
    this->_y1 = time._y1;
    this->_y2 = time._y2;
    return *this;
}