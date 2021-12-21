#include "Transport.h"

Transport::Transport(string ID, string locationStart, string locationEnd, string time, int type, double cost)
{
    this->_ID = ID;
    this->_locationStart = locationStart;
    this->_locationEnd = locationEnd;
    this->_time = time;
    this->_type = type;
    this->_cost = cost;
}