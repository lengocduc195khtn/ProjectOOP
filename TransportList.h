#include "Bus.h"
#include "Grab.h"
#include "Taxi.h"

class TransportList
{
private:
    list<Transport *> _data;

public:
    TransportList();
    ~TransportList();

public:
    void readFile(string address);
    void writeFile(string address);

public:
    void showAvailable(list<Transport *> &transport, Time time);
    void showAvailable(list<Transport *> &transport, string locationStart, string locationEnd);
    void showAvailable(list<Transport *> &transport, Time time, string locationStart, string locationEnd);
};