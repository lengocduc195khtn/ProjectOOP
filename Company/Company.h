#include "LIB.h"
#include "Staff/Pilot.h"
#include "Staff/Stewardess.h"
#include "Company/Salary.h"

class Company
{
    char _ID[6];
    char _name[50];

    int _nPilot;
    Pilot *_pilot;
    int _nStewardess;
    Stewardess *_stewardess;

    Salary _salary;
};