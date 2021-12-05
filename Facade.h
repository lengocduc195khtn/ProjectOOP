#include<iostream>
#include<string>
#include<vector>
using namespace std;
// class Transport;
class Flight;
class Hotel;
class Ticket;
// class Account;

// Thien added
#include "Account.h"
#include "Transport.h"

class Facade
{
	//all the available flight, hotel, transport
	vector<Flight> _flight;
	vector<Hotel> _hotel;
	// vector<Transport> _transport;
	vector<Transport*> _transport;
public:
	void showTransports(string location);
	void showHotels(string location);
	void showTickets(string location);
	bool bookHotel(string location, string name, int amount);
	bool bookTicket(string name, int amount, int type);	//name = ID
	bool bookTransport(string ID);
	void cancelTransports(/*ticket*/);//we need something to valid check
	void cancelHotel(/*ticket*/);
	void cancelFlight(/*ticket*/);
	friend class Account;
};

// class Account {
// 	/*vector<bill> _hotels;
// 	vector<bill> _flights;
// 	vector<bill> _transports;*/
// };

class Transport
{
	string _time;
	string _location;
	int _type;
	string _ID;
public:
	bool book();
	friend class Facade;
};

class Flight
{
	string _arrivalAirport;
	string _departureAirport;
	string _arrivalTime;
	string _departureTime;
	string _name;
	vector<Ticket> _ticket;
	int _seatLeft;
public:
	friend class Ticket;
	friend class Facade;
	bool book(int amount, int type);
	Flight(const Flight& ip);
};

class Ticket//not sure what to do with the class now
{
	int _fare;
	bool _isBooked;
	string _ID;
public:
	friend class Facade;
	friend class Flight;
	bool book(int amount, const Flight& ip);// book <amount> tickets in flight <ip>
	//void showAvailable(string time, string destination);
	//void cancel();
};

class Hotel
{
public:
	string _name;
	string _location;
	int _roomLeft;
	int _cost;

	bool book(int amount);
	int showAvailable();
	void cancel();//update later
	friend class Facade;
};
