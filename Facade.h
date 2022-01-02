#pragma once
#include<iostream>
#include <string>
#include <vector>
#include"Transport.h"
#include"Hotel.h"
#include"Flight.h"
#define MAX_ROW 30// plane size
#define MAX_COL 6// plane size
using namespace std;

class Facade
{	
	vector<Flight*> _avaFlt;// available flight
	vector<Hotel*> _avaHtl;// available hotels
	vector<Transport*> _avaTrs;// available transports
	vector<Ticket*> _bkdTck;// booked tickets
	vector<Hotel*> _bkdHtl;// booked hotels
	vector<Transport*> _bkdTrs;// booked transport
public:
	void updateJson() {}
	void showAvaTck(string time, string src, string des, bool isTwoWay);
	void showAvaTrs(string time, string src, string des);
	void showAvaHtl(string location);
	void showBookedTrs();
	void showBookedHtl();
	void showBookedTck();
	bool bookHotel(string location, string name, int amount);
	bool bookTicket(Ticket* ip);	//name = ID
	bool bookTransport(string ID);
	void cancelTrs(/*ticket*/);//we need something to valid check
	void cancelHtl(/*ticket*/);
	void cancelTck(/*ticket*/);
};