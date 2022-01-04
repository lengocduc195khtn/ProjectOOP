#pragma once
#include "LIB.h"

class Time
{
private:
    char _h;
    char _m;
    // _y1 chứa thế kỉ
    // _y2 chứa năm
    // Ví dụ: 1905
    // _y1 = 19, _y2 = 5
    char _s;

public:
    Time();
    Time(string time);
    ~Time();

public:
    string stringTime();
    bool operator==(const Time &time);
    Time &operator=(const Time &time);
};