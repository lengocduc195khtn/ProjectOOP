#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include"Transport.h"
#include"Hotel.h"
#include"Flight.h"
#include"Time.h"

using namespace std;
typedef Flight::Ticket Ticket;

class Facade
{	
	// database
	vector<Flight* > _avaFlt;// available flight
	vector<Hotel*> _avaHtl;// available hotels
	vector<Transport*> _avaTrs;// available transports
	// account
	vector<Ticket*> _bkdTck;// booked tickets
	vector<Hotel*> _bkdHtl;// booked hotels
	vector<Transport*> _bkdTrs;// booked transport
	
public:	
	Facade(vector<Flight*> ,vector<Hotel*> , vector<Transport*>);
	void updateJson() {}	
	vector<Ticket*> bookTicket(string dep, string arr, string depTime, string arrTime, bool isTwoWay);
	vector<Transport*> bookTransport(string src, string des, Time time);
	vector<Hotel*> bookHotel(Date date, string location);
	void showBookedTrs();
	void showBookedHtl();
	void showBookedTck();	
	void cancelTrs(int index);
	void cancelHtl(int index);
	void cancelTck(int index);
	~Facade();
};