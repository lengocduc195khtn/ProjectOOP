#include "LIB.h"

int main() {
    json j;
    json k;
    j["id"] = 1;
    j["location"] = "Da nang";
    j["name"] = "Muong Thanh Luxury";
    j["nRoomTypes"] = 5;
    j["capacity"] = 100;
    j["cost"] = {100, 200, 300, 400, 500};
    j["current"] = 0;
    k.push_back(j);
    for (auto items : j.items()) {
        cout << items.key() << " " << items.value() << "\n";
    }
    ofstream o;
    o.open("hotels.json");
    o << setw(4) << k;
    o.close();
    
    // json j, k;
    // j["id"] = 1;
    // j["name"] = "BAV";
    // j["capacity"] = 120;
    // j["current"] = 0;
    // j["ArrivalAirport"] = "HAN";
    // j["DepartureAirport"] = "SGN";
    // j["ArrivalTime"] = "241120212115";
    // j["DepartureTime"] = "241120211725";
    // k.push_back(j);
    // ofstream o;
    // o.open("flights.json");
    // o << setw(4) << k;
    // o.close();
    // json j;
    // ifstream in;
    // in.open("flights.json");
    // in >> j;
    // cout << j << "\n";
    // cout << j[0]["ArrivalAirport"] << " " << j[0]["name"] << "\n";
    // in.close();
}