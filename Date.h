#pragma once
#include "LIB.h"

class Date
{
private:
    char _d;
    char _m;
    // _y1 chứa thế kỉ
    // _y2 chứa năm
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
    bool operator==(const Date &time);
    Date &operator=(const Date &time);
};