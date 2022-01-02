#include"Flight.h"

Ticket::Ticket()
{
	_fare = 1000000;
	_isBooked = false;
	_flight = nullptr;
	_row = 1;
	_col = 1;
}

Ticket::Ticket(const Ticket& ip)
{
	_fare = ip._fare;
	_isBooked = ip._isBooked;
	_flight = ip._flight;
	_row = ip._row;
	_col = ip._col;
}

bool Ticket::book()
{
	if (!_isBooked)
		return true;
	return false;
}

string Ticket::info()
{
	string res;
	//res += "type: " + this->type + "\n"; economy/ business/ first class
	res += "row: " + to_string(this->_row) + "\n";
	res += "seat: " + to_string(this->_col) + "\n";
	res += "fare: " + to_string(this->_fare);
	return res;
}

string Ticket::receipt()
{
	string res;
	res += "flight info: \n" + _flight->info();
	//res += "type: " + this->type + "\n"; economy/ business/ first class
	res += "row: " + to_string(this->_row) + "\n";
	res += "seat: " + to_string(this->_col) + "\n";
	res += "fare: " + to_string(this->_fare);
	return res;
}

void Ticket::operator=(Ticket& ip)
{
	_fare = ip._fare;
	_isBooked = ip._isBooked;
	_flight = ip._flight;
	_row = ip._row;
	_col = ip._col;
}

Flight::Flight()
{
	_departureAirport = "";
	_arrivalAirport = "";
	_departureTime = "";
	_arrivalTime = "";
}

Flight::Flight(const Flight& ip)
{
	_departureAirport = ip._departureAirport;
	_arrivalAirport = ip._arrivalAirport;
	_departureTime = ip._departureTime;
	_arrivalTime = ip._arrivalTime;
	_name = ip._name;
	_seatLeft = ip._seatLeft;
	_ticket = ip._ticket;	
}

string Flight::info()
{
	string res = "";
	res += "Flight ID: " + this->_name + "\n";
	res += "Desination: " + this->_arrivalAirport + "\n";
	res += "Take off time: " + this->_departureTime + "\n";
	res += "Seat left: " + to_string(this->_seatLeft);	
	return res;
}

Ticket* Flight::book(int row, int col)
{
	Ticket* res = nullptr;
	if (!_ticket[row][col]->_isBooked) {
		_ticket[row][col]->_isBooked = true;
		res = _ticket[row][col];
	}			
	return res;
}

string Flight::showEmptySeat(bool isTwoWay)
{
	string res;
	for (auto row : _ticket)
		for (auto col : row) {
			if (!col->_isBooked)
				res+= "O\t";
			else
				res+= "X\t";
			res += "\n";
		}		
	return res;
}

string Flight::seatInfo(int row, int col)
{
	return _ticket[row][col]->info();
}

vector<Flight> Flight::filter(vector<Flight*> list, string dep, string arr, string time)
{
	vector<Flight> res;
	for (auto item : list)
		if (item->_departureAirport == dep && item->_arrivalAirport == arr)
			if (item->_departureTime == time)// prioritze time
				res.insert(res.begin(), *item);
			else
				res.push_back(*item);
	return res;
}

