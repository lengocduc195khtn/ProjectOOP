#define _CRT_SECURE_NO_WARNINGS
#include"Date.h"
#include"Time.h"
#include <vector>
#define MAX_SEAT 180// plane size
using namespace std;

class Flight
{
public:
	class Ticket
	{
	private:
		int _fare = 0;
		Flight* _flight = nullptr;// corespodent flight
		int _pos = 0;// seat position
	public:
		bool _isBooked;
		Ticket(Flight* flight, int pos);
		Ticket(const Ticket& ip);
		bool book();
		string info();//general information
		string receipt();//receipt information
		void operator=(Ticket& ip);
	};
	Flight(string _depApr, string _arrApr, Date depD, Time depT, Date arrD, Time arrT);
	Flight(const Flight& ip);
	string info();
	Ticket* book(int pos);
	string showEmptySeat(bool isTwoWay);
	string seatInfo(int pos);
	static vector<Flight> showAvailable(vector<Flight*> list, string dep, string arr, Time depT, Date depD, Time arrT, Date arrD);
private:
	string _arrApr;// arrival airport
	string _depApr;// departure airport
	Time _depTim;// departure time
	Time _arrTim;// arrival time
	Date _depDat;// departure date
	Date _arrDat;// arrival date
	string _name;	
	int _seatLeft;	
	vector<Ticket*> _ticket;
};