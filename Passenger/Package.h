#include "Passenger/Baggage.h"

// ** Bưu kiện gửi bằng đường hàng không
// ** Khách hàng không cần mua vé ghế
// ** Do đó phải có thông tin khách hàng của gói hàng
class Package : public Baggage
{
private:
    Passenger _passengerGui;
    Passenger _passengerNhan;
    double _ThanhTien;
}