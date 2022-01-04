#include<string>
using namespace std;
class Date
{
private:
    char _d;
    char _m;
    // _y1 2 first digits
    // _y2 2 last digits
    // Ví dụ: 1905
    // _y1 = 19, _y2 = 5
    char _y1;
    char _y2;

public:
    Date();
    Date(string time);
    ~Date();

public:
    string stringDate();
    bool operator==(const Date& time);
    Date& operator=(const Date& time);
};