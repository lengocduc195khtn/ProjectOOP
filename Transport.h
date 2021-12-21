#include "LIB.h"

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
    int _type;
    double _cost;

public:
    Transport(string ID, string locationStart, string locationEnd, string time, int type, double cost);

public:
    virtual void readFile() = 0;

public:
    virtual bool book() = 0;
    virtual cancel() = 0;
    virtual bool checkAvailable() = 0;
    virtual void showAvailable(Time time, string locationStart, string locationEnd) = 0;
};

int calculate(int type);
