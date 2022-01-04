#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <time.h>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Time
{
private:
    char _h;
    char _m;
    // _y1 2 first digits
    // _y2 2 last digits
    // Ví dụ: 1905
    // _y1 = 19, _y2 = 5
    char _s;

public:
    Time();
    Time(string time);
    ~Time();

public:
    string stringTime();
    bool operator==(const Time& time);
    Time& operator=(const Time& time);
};