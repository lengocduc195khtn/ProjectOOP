#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<vector>
using namespace std;

class Hotel
{
	string _name;
	string _location;
	int _roomLeft;
	int _cost;	
public:
	string info();//general information
	string receipt();//receipt information
	bool book(int amount);
	static vector<Hotel> showAvailable(vector<Hotel*> list, string location);
	void cancel();
	friend class Facade;
};