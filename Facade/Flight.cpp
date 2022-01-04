#define _CRT_SECURE_NO_WARNINGS
#include"Flight.h"
#include<iostream>
#define MAX_COL 30

Flight::Flight(string _depApr, string _arrApr, Date depD, Time depT, Date arrD, Time arrT)
{
	this->_depApr = _depApr;
	this->_arrApr = _arrApr;
	this->_depTim = depT;
	this->_depDat = depD;
	this->_arrDat = arrD;
	this->_arrTim = arrT;
	this->_name = "dummy plane";
	this->_seatLeft = 180;
	for (int i = 0; i < 180; i++)
		this->_ticket.push_back(new Ticket(this, i));
}

Flight::Flight(const Flight& ip)
{
	_depApr = ip._depApr;
	_arrApr = ip._arrApr;
	_depTim = ip._depTim;
	_name = ip._name;
	_seatLeft = ip._seatLeft;
	_ticket = ip._ticket;
	_depDat = ip._depDat;
	_arrDat = ip._arrDat;
	_arrTim = ip._arrTim;
}

string Flight::info()
{
	string res = "";
	res += "Flight ID: " + this->_name + "\n";
	res += "Desination: " + this->_arrApr + "\n";
	res += "Take off time: " + _depTim.stringTime() + "\n";
	res += "Seat left: " + to_string(this->_seatLeft);
	return res;
}

Flight::Ticket* Flight::book(int pos)
{
	Ticket* res = nullptr;
	if (!_ticket[pos]->_isBooked) {
		_ticket[pos]->_isBooked = true;
		_seatLeft--;
		res = _ticket[pos];
	}
	return res;
}

string Flight::showEmptySeat(bool isTwoWay)
{
	string res;
	for (unsigned int i = 0; i < _ticket.size(); i++) {
		if ((i + 1) % MAX_COL == 0)
			res += "\n";
		if (_ticket[i]->_isBooked)
			res += "X\t";
		else
			res += "O\t";
	}
	return res;
}

string Flight::seatInfo(int pos)
{
	return _ticket[pos]->info();
}

vector<Flight> Flight::showAvailable(vector<Flight*> list, string dep, string arr, Time depT, Date depD, Time arrT, Date arrD)
{
	vector<Flight> res;
	for (auto item : list)
		if (item->_depApr == dep && item->_arrApr == arr && item->_depDat == depD && item->_arrDat == arrD)
			if (item->_depTim == depT || item->_arrTim == arrT)// prioritze time
				res.insert(res.begin(), *item);
			else
				res.push_back(*item);
	return res;
}

Flight::Ticket::Ticket(Flight* flight, int pos)
{
	this->_fare = 1000000;
	this->_isBooked = false;
	this->_flight = flight;
	this->_pos = pos;
}

Flight::Ticket::Ticket(const Ticket& ip)
{
	_fare = ip._fare;
	_isBooked = ip._isBooked;
	_flight = ip._flight;
	_pos = ip._pos;
}

bool Flight::Ticket::book()
{
	if (!_isBooked)
		return true;
	return false;
}

string Flight::Ticket::info()
{
	string res;
	//res += "type: " + this->type + "\n"; economy/ business/ first class
	res += "seat: " + to_string(this->_pos) + "\n";
	res += "fare: " + to_string(this->_fare);
	return res;
}

string Flight::Ticket::receipt()
{
	string res;
	res += "flight info: \n" + _flight->info() + "\n" + info();
	//res += "type: " + this->type + "\n"; economy/ business/ first class	
	return res;
}

void Flight::Ticket::operator=(Flight::Ticket& ip)
{
	_fare = ip._fare;
	_isBooked = ip._isBooked;
	_flight = ip._flight;
	_pos = ip._pos;
}