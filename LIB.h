#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <iomanip>
#include "json/json.hpp"
#include <fstream>
#include <conio.h>
#include <ctime>

#include <deque>
#include <list>
#include <unordered_set>

using namespace std;
using json = nlohmann::json;

bool checkConditionUsername(string username);
bool checkConditionPassword(string password);