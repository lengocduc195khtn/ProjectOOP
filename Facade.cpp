#include "Facade.h"

void Facade::showTransports(string location)
{
	cout << "List of transports available in" << location << " : \n";
	for (int i = 0; i < this->_transport.size(); i++)
		if (this->_transport[i]->_location == location) {
			cout << "Transport type: " << this->_transport[i]->_type << endl;//uprade later
			cout << "ID: " << this->_transport[i]->_ID << endl;
			cout << "Service time: " << this->_transport[i]->_time << endl;
			cout << "------------------------------------------------\n";//seperator
		}			
}

void Facade::showHotels(string location)
{
	cout << "List of rooms available: \n";
	for (int i = 0; i < this->_hotel.size(); i++)
		if (this->_hotel[i]._location == location) {
			cout << "Hotel: " << this->_hotel[i]._name << "\tRoom left: " << this->_hotel[i].showAvailable() << endl;
			cout << "------------------------------------------------\n";//seperator
		}
			
}

void Facade::showTickets(string destination)
{	
	cout << "List of tickets available: \n";
	for (int i = 0; i < this->_flight.size(); i++)
		if (this->_flight[i]._arrivalAirport == destination) {
			cout << "Flight name: " << this->_flight[i]._name << endl;
			cout << "Departure airport: " << this->_flight[i]._departureAirport << ": \n";
			cout << "Number of tickets left: " << this->_flight[i]._seatLeft << endl;;
			cout << "------------------------------------------------\n";//seperator
		}			
}

bool Facade::bookHotel(string location, string name, int amount)
{
	for (int i = 0; i < this->_hotel.size(); i++)
		if (this->_hotel[i]._name == name && this->_hotel[i]._location == location)
			return this->_hotel[i].book(amount);
	return false;
}

bool Facade::bookTicket(string name, int amount, int type)
{
	for (int i = 0; i < this->_flight.size(); i++)
		if (this->_flight[i]._name == name) 
			return this->_flight[i].book(amount, type);		
	return false;
}

bool Facade::bookTransport(string ID)
{
	for (int i = 0; i < this->_transport.size(); i++)
		if (this->_transport[i]->_ID == ID)			
			return this->_transport[i]->book();					
	return false;
}

bool Flight::book(int amount, int type)
{
	if (this->_seatLeft >= amount) {
		this->_seatLeft -= amount;
		//create bill
		return true;
	}
	return false;
}

Flight::Flight(const Flight& ip)
{
	this->_arrivalAirport = ip._arrivalAirport;
	this->_departureAirport = ip._departureAirport;
	this->_arrivalTime = ip._arrivalAirport;
	this->_departureTime = ip._departureTime;
	this->_name = ip._name;
	this->_seatLeft = ip._seatLeft;
}


bool Ticket::book(int amount, const Flight& ip)
{
	if (amount > ip._seatLeft)
		return false;
	return true;
}

bool Hotel::book(int amount)
{
	if (this->_roomLeft > amount) {
		this->_roomLeft -= amount;
		//create bill
		return true;
	}
	else
		return false;
}

int Hotel::showAvailable()
{
	return this->_roomLeft;
}

void Hotel::cancel()
{
	this->_roomLeft++;
}