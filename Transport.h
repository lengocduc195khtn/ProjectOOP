#pragma once
#include "LIB.h"
#include "Time.h"

class Transport
{
private:
    // ** Tại đây:  _ID là mã số của phương tiện
    // **           _locationStart là điểm đi
    // **           _locationEnd là điểm đến
    // **           _type là loại cấp bậc của phương tiện (thường, cao cấp)
    // **           _cost là chi phí

    // ?? Ta có thể thấy, grab và taxi là hai phương tiện hoạt động độc lập, thời gian di chuyển phụ thuộc vào khách hàng
    // ?? Do đó, biến _time chỉ có ở phương tiện bus.
    string _ID;
    string _locationStart;
    string _locationEnd;
    Time _time;
    string _type;
    double _cost;

    // Một số thông tin đặc biệt riêng
    string _driver;
    string _licensePlate;

public:
    Transport(string ID, string locationStart, string locationEnd, string time, string type, double cost, string driver, string licensePlate);

public:
    virtual bool book() = 0;
    virtual bool cancel() = 0;
    virtual bool checkAvailable() = 0;

    virtual bool isFull() = 0;
    void showAvailable(list<Transport *> &transport, Time time);
    void showAvailable(list<Transport *> &transport, string locationStart, string locationEnd);
    void showAvailable(list<Transport *> &transport, Time time, string locationStart, string locationEnd);

    void getBasicInfo(json &j);
    virtual void getInfo(json &j) = 0;
    string info();
    string receipt();
};

int calculate(string type);
