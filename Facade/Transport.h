#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<vector>
#include"Time.h"
using namespace std;

class Transport
{
	string _ID;
	string _locationStart;
	string _locationEnd;
	int _type;
	double _cost;
	Time _time;
public:
	string info() { return ""; }//general information
	string receipt() { return ""; }//receipt information
	bool book();
	void cancel() {}
	static vector<Transport> showAvailable(vector<Transport*> list, string start, string end, Time time);
};