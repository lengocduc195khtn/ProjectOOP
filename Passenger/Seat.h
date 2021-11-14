#include "LIB.h"
#include "Passenger/Passenger.h"
class Seat
{

private:
    // ** A120 Ghế thứ 120, vị trí A
    char _ID[4];

    // ** Kiểm tra ghế đã được đặt chỗ chưa
    bool _exist;

    // ** Thông tin khách hàng
    Passenger _passenger;
};