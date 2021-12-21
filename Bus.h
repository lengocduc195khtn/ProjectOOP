#include "Transport.h"

class Bus : public Transport
{
    // ** Tại đây có một biến current, kiểm tra Grab đã được đặt chỗ hay chưa
    int _size;
    bool *_current;

public:
    Bus(string ID, string locationStart, string locationEnd, string time, int type, double cost);

private:
    bool isFull();

public:
    // ** Tại đây, hàm cancel có kiểu trả về bool vì: một số trường hợp, chúng ta không thể hủy vé (giới hạn thời gian hủy vé).
    // ?? Nhưng hiện tại chúng ta xem như nó không có cơ chế giới hạn thời gian hủy vé.

    bool book(int position);
    bool cancel(int position);
    bool checkAvailable(int position);

public:
    void readFile();
    // ** Sau đây là các hàm in dữ liệu
    // ?? Để đảm bảo tính đống gói
    // ?? Đầu tiên, hàm sẽ nhận dữ liệu đầu vào để kiểm tra, nếu bằng thì nó mới chuyển vào vector.
    // ?? Việc sử dụng vector sẽ có lợi cho việc tổ chức dữ liệu sau này

    void showAvailable(vector<Tranport *> &transport, Time time);
    void showAvailable(vector<Tranport *> &transport, string locationStart, string locationEnd);
    void showAvailable(vector<Tranport *> &transport, Time time, string locationStart, string locationEnd);
};