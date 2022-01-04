#define _CRT_SECURE_NO_WARNINGS
#include"Flight.h"
#include<iostream>

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
}

Flight::Flight(const Flight& ip)
{
	_depApr = ip._depApr;
	_arrApr = ip._arrApr;
	_depTim = ip._depTim;
	_name = ip._name;
	_seatLeft = ip._seatLeft;	
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

Flight::Ticket* Flight::book()
{
	Flight::Ticket* res = nullptr;
	if (_seatLeft > 0) {
		res = new Ticket(this);
		_seatLeft--;
	}		
	return res;
}

string Flight::seatInfo()
{	
	return Ticket(this).info();
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

Flight::Ticket::Ticket(Flight* flight)
{
	this->_fare = 1500000;
	this->_isBooked = false;
	this->_flight = flight;	
}

Flight::Ticket::Ticket(const Ticket& ip)
{
	_fare = ip._fare;
	_isBooked = ip._isBooked;
	_flight = ip._flight;	
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
	res += "fare: " + to_string(this->_fare);
	return res;
}

string Flight::Ticket::receipt()
{
	string res;
	res += "flight info: \n" + _flight->info() + "\n" + info();	
	return res;
}

void Flight::Ticket::cancel()
{
	_flight->_seatLeft++;	
}

void Flight::Ticket::operator=(Flight::Ticket& ip)
{
	_fare = ip._fare;
	_isBooked = ip._isBooked;
	_flight = ip._flight;	
}

Flight::Ticket::~Ticket()
{
	delete _flight;
}
