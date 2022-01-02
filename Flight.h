#include"Facade.h"

class Ticket
{
	int _fare;
	Flight* _flight;// corespodent flight
	int _row;// seat's row
	int _col;// seat's column
public:
	bool _isBooked;
	Ticket();
	Ticket(const Ticket& ip);
	bool book();
	string info();//general information
	string receipt();//receipt information
	void operator=(Ticket& ip);	
};

class Flight
{
	string _arrivalAirport;
	string _departureAirport;
	string _arrivalTime;
	string _departureTime;
	string _name;
	vector<vector<Ticket*>> _ticket;
	int _seatLeft;
public:	
	Flight();
	Flight(const Flight& ip);
	string info();
	Ticket* book(int row, int col);
	string showEmptySeat(bool isTwoWay);
	string seatInfo(int row, int col);
	static vector<Flight> find(vector<Flight*> list, string dep, string arr, string time);
};