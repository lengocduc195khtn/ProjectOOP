#include "TransportList.h"

TransportList::TransportList()
{
}
TransportList::~TransportList()
{
    for (auto itr = this->_data.begin(); itr != this->_data.end(); itr++)
    {
        this->_data.erase(itr);
    }
    this->_data.clear();
}

void TransportList::readFile(string address)
{
    json j;
    fstream f;
    f.open(address, ios::in | ios::binary);
    if (f.fail())
        return;
    f >> j;
    cout << "Hi";
    // iterate the array
    if (address == "taxi.json")
        for (json::iterator it = j.begin(); it != j.end(); ++it)
        {
            this->_data.push_back(new Taxi(it->at("ID"), it->at("LocationStart"), it->at("LocationEnd"), it->at("Time"), it->at("Type"), it->at("Cost"), it->at("Driver"), it->at("LicensePlate"), it->at("Current")));
        }
    else if (address == "bus.json")
        for (json::iterator it = j.begin(); it != j.end(); ++it)
        {
            this->_data.push_back(new Bus(it->at("ID"), it->at("LocationStart"), it->at("LocationEnd"), it->at("Time"), it->at("Type"), it->at("Cost"), it->at("Driver"), it->at("LicensePlate"), it->at("Current")));
        }
    else if (address == "grab.json")
        for (json::iterator it = j.begin(); it != j.end(); ++it)
        {
            this->_data.push_back(new Grab(it->at("ID"), it->at("LocationStart"), it->at("LocationEnd"), it->at("Time"), it->at("Type"), it->at("Cost"), it->at("Driver"), it->at("LicensePlate"), it->at("Current")));
        }
    f.close();
}
void TransportList::writeFile(string address)
{
    json j;
    fstream f;
    f.open(address, ios::out | ios::binary);
    if (f.fail())
        return;
    for (auto itr = this->_data.begin(); itr != this->_data.end(); itr++)
    {
        (*itr)->getInfo(j);
    }

    f << setw(4) << j;
    f.close();
}

void TransportList::showAvailable(list<Transport *> &transport, Time time)
{
    for (auto itr = this->_data.begin(); itr != this->_data.end(); itr++)
    {
        (*itr)->showAvailable(transport, time);
    }
}
void TransportList::showAvailable(list<Transport *> &transport, string locationStart, string locationEnd)
{
    for (auto itr = this->_data.begin(); itr != this->_data.end(); itr++)
    {
        (*itr)->showAvailable(transport, locationStart, locationEnd);
    }
}
void TransportList::showAvailable(list<Transport *> &transport, Time time, string locationStart, string locationEnd)
{
    for (auto itr = this->_data.begin(); itr != this->_data.end(); itr++)
    {
        (*itr)->showAvailable(transport, time, locationStart, locationEnd);
    }
}
