#include "LIB.h"

bool checkConditionUsername(string username)
{
    int n = username.length();
    int i = 0;
    while (i < n)
    {
        if (!((username[i] <= 'Z' && username[i] >= 'A') || (username[i] <= 'z' && username[i] >= 'a') || (username[i] <= '9' && username[i] >= '0')))
            return false;
        i++;
    }
    return true;
}
bool checkConditionPassword(string password)
{
    int n = password.length();
    int i = 0;
    while (i < n)
    {
        if (!((password[i] <= 'Z' && password[i] >= 'A') || (password[i] <= 'z' && password[i] >= 'a') || (password[i] <= '9' && password[i] >= '0')))
            return false;
        i++;
    }
    return true;
}
