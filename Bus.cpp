#include "Bus.h"

Bus::Bus(string ID, string locationStart, string locationEnd, string time, int type, double cost) : Transport(ID, locationStart, locationEnd, time, type, cost)
{
    this->_size = calculate(type);
    this->_current = new bool[this->_size]{false};
}
bool Bus::isFull()
{
    for (int i = 0; i < this->_size; i++)
        if (this->_current[i] == false)
            return 0;
    return 1;
}

// ** Tại đây, hàm cancel có kiểu trả về bool vì: một số trường hợp, chúng ta không thể hủy vé (giới hạn thời gian hủy vé).
// ?? Nhưng hiện tại chúng ta xem như nó không có cơ chế giới hạn thời gian hủy vé.

bool Bus::book(int position)
{
    if (this->_current[position] == true)
        return 0;
    this->_current[position] = true;
    return 1;
}
bool Bus::cancel(int position)
{
    if (this->_current[position] == false)
        return 0;
    this->_current[position] = false;
    return 1;
}
bool Bus::checkAvailable(int position)
{
    if (this->_current[position] == true)
        return 1;
    return 0
}
void Bus::readFile()
{
    fstream
}
// ** Sau đây là các hàm in dữ liệu
// ?? Để đảm bảo tính đống gói
// ?? Đầu tiên, hàm sẽ nhận dữ liệu đầu vào để kiểm tra, nếu bằng thì nó mới chuyển vào vector.
// ?? Việc sử dụng vector sẽ có lợi cho việc tổ chức dữ liệu sau này

void Bus::showAvailable(vector<Tranport *> &transport, Time time)
{
    if (!this->isFull() && time == this->_time)
        transport.push_back(this);
}
void Bus::showAvailable(vector<Tranport *> &transport, string locationStart, string locationEnd)
{
    if (!this->isFull() && locationStart == this->_locationStart && locationEnd == this->_locationEnd)
        transport.push_back(this);
}
void Bus::showAvailable(vector<Tranport *> &transport, Time time, string locationStart, string locationEnd)
{
    if (!this->isFull() && time == this->_time && locationStart == this->_locationStart && locationEnd == this->_locationEnd)
        transport.push_back(this);
}
