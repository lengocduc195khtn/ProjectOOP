#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include"Transport.h"
#include"Hotel.h"
#include"Flight.h"
#include"Time.h"
#define MAX_ROW 30// plane size
#define MAX_COL 6// plane size
using namespace std;
typedef Flight::Ticket Ticket;

class Facade
{	
	vector<Flight* > _avaFlt;// available flight
	vector<Hotel*> _avaHtl;// available hotels
	vector<Transport*> _avaTrs;// available transports

	vector<Ticket*> _bkdTck;// booked tickets
	vector<Hotel*> _bkdHtl;// booked hotels
	vector<Transport*> _bkdTrs;// booked transport
public:
	Facade();
	void updateJson() {}	
	void bookTicket(string dep, string arr, Date depD, Time depT, Date arrD, Time arrT, bool isTwoWay);
	void bookTransport(string src, string des, Time time);
	void bookHotel(Date date, string location);
	void showBookedTrs();
	void showBookedHtl();
	void showBookedTck();	
	void cancelTrs(int index);
	void cancelHtl(int index);
	void cancelTck(int index);
};