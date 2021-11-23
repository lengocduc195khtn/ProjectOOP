#include "LIB.h"
#include "Staff/Stewardess.h"
#include "Staff/Pilot.h"
#include "Passenger/Seat.h"
#include "Passenger/Baggage.h"

class Flight
{
private:
    // ** HNSG241125 : là sân bay Hà Nội (HN) đến Sài Gòn (SG)
    // ** chuyến bay thứ 241.125
    char _IDFlight[8];

    // ** Mã máy bay được sử dụng
    char _IDPlane[8];

    // ** HN000000 : Hà Nội
    char _IDStartAirport[8];
    char _IDEndAirport[8];

    // ** 24112021 : ngay 24 thang 11 nam 2021
    char _startDate[8];
    char _endDate[8];

    // ** 1742 : 17h 42 phut
    char _startHour[4];
    char _endHour[4];

    int _nSeat;
    Seat *_seat;

    // ** Có lẽ các bạn sẽ đặt câu hỏi là : Tại sao không gộp nó với Seat,
    // ** Câu trả lời là có những món hàng được gửi bằng đường hàng không,
    // ** khách hàng lúc này không cần mua vé ghế.
    int _baggage;
    Baggage *_baggage;

    // ** Danh sách tiếp viên
    int _nStewardess;
    Stewardess *_stewardess;

    // ** Danh sách phi công
    int _nPilot;
    Pilot *_pilot;
};