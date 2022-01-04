#pragma once
#include "Transport.h"

class Bus : public Transport
{
    // ** Tại đây có một biến current, kiểm tra Grab đã được đặt chỗ hay chưa
    int _size;
    int _current;

public:
    Bus(string ID, string locationStart, string locationEnd, string time, string type, double cost, string driver, string licensePlate, int current);

private:
    bool isFull();

public:
    // ** Tại đây, hàm cancel có kiểu trả về bool vì: một số trường hợp, chúng ta không thể hủy vé (giới hạn thời gian hủy vé).
    // ?? Nhưng hiện tại chúng ta xem như nó không có cơ chế giới hạn thời gian hủy vé.

    bool book();
    bool cancel();
    bool checkAvailable();
     void getInfo(json& j);
};