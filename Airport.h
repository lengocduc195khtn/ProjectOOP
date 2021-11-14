#include "LIB.h"
#include "Flight.h"

class Airport
{
private:
    // ** Ví dụ : HNNB0000 là sân bay nội bài (NB) hà nội (HN)
    char _ID[8];
    char _name[50];

    // ** Danh sách các chuyến bay được thực hiện tại đây
    int _nFlight;
    Flight *_flight;
};