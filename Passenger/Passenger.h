#include "LIB.h"
#include "Flight.h"
#include "Passenger/Package.h"

class Passenger
{
private:
    // ** Chưa biết nên đặt tên thế nào để bảo mật.
    // ** Mấy ông đến đây thì góp ý giúp tôi nha
    char _ID[8];

    char _name[50];

    // ** 25112002 : sinh ngày 25 tháng 11 năm 2002
    char _birthday[8];

    // ** 84378871736 : số điện thoại có 11 số
    char _phone[11];

    // ** Danh sách các bưu kiện được gửi 
    int nPackage;
    Package *_package;

    // ** Chúng ta phải tạo một thứ gì đó để lưu lịch sử bay của khách hàng
    // ** Khách hàng có thể xem lịch sử bay của mình (thông tin chuyến bay
    // ** không bao gồm danh sách tiếp viên, phi công, các hành khách khác)
    // ** Tôi tạo như sau
    int _nFlight;
    Flight *_flight;
};