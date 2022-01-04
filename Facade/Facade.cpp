#include"Facade.h"

Facade::Facade()
{
	_avaFlt.push_back(new Flight("SGN", "HAN", Date("04012022"), Time("060000"), Date("04122022"), Time("073000")));
}

void Facade::bookTicket(string dep, string arr, Date depD, Time depT, Date arrD, Time arrT, bool isTwoWay)
{
	vector<Flight> filtered = Flight::showAvailable(_avaFlt, dep, arr, depT, depD, arrT, arrD);// showAvailable the flights
	for (auto flight : filtered)// show the general info of each
		cout << flight.info() << endl;
	int choice, pos = 0;
	cin >> choice;//let the user choose the flight to see further detail	
	Flight* choseFlt = _avaFlt[choice];
	choseFlt->showEmptySeat(isTwoWay);
	cout << "Choose position index: ";
	cin >> pos;
	cout << "Seat info:\n" << choseFlt->seatInfo(pos);
	bool order = 0;// confirm order
	cin >> order;
	if (order) {
		Ticket* choseSeat = choseFlt->book(pos);
		if (choseSeat) {
			_bkdTck.push_back(choseSeat);
			updateJson();// dummy function
		}
	}
}

void Facade::bookTransport(string src, string des, Time time)
{
	vector<Transport> filtered = Transport::showAvailable(_avaTrs, src, des, time);
	for (auto item : filtered)// show the general info of each
		cout << item.info() << endl;
	int choice, pos = 0;
	cin >> choice;//let the user choose the item to see further detail	
	Transport* chosetrs = _avaTrs[choice];
	bool order = 0;// confirm order
	cin >> order;
	if (order) {
		bool buffer = chosetrs->book();
		if (buffer) {
			_bkdTrs.push_back(chosetrs);
			updateJson();// dummy function
		}
	}
}

void Facade::bookHotel(Date date, string location)// hỏi Thiên xem htl db có sẵn ngày chưa
{
	vector<Hotel> filtered = Hotel::showAvailable(_avaHtl, location);
	for (auto item : filtered)// show the general info of each
		cout << item.info() << endl;
	int choice, pos = 0;
	cin >> choice;//let the user choose the item to see further detail	
	Transport* choseTrs = _avaTrs[choice];
	bool order = 0;// confirm order
	cin >> order;
	if (order) {
		bool buffer = choseTrs->book();
		if (buffer) {
			_bkdTrs.push_back(choseTrs);
			updateJson();// dummy function
		}
	}
}

void Facade::showBookedTrs()
{
	for (auto item : _bkdTrs)
		cout << item->info() << endl;
	cout << "select one:";
	int selection = 0;
	cin >> selection;
	auto selected = _bkdTrs[selection];
	cout << selected->receipt();			
}

void Facade::showBookedHtl()
{
	for (auto item : _bkdHtl)
		cout << item->info() << endl;
	cout << "select one:";
	int selection = 0;
	cin >> selection;
	auto selected = _bkdHtl[selection];
	cout << selected->receipt();
}

void Facade::showBookedTck()
{
	for (auto item : _bkdTck)
		cout << item->info() << endl;
	cout << "select one:";
	int selection = 0;
	cin >> selection;
	auto selected = _bkdTck[selection];
	cout << selected->receipt();
}

void Facade::cancelTrs(int index)
{	
	if (index >= _bkdTrs.size())
		return;
	_bkdTrs.erase(next(_bkdTrs.begin(), index));
}

void Facade::cancelHtl(int index)
{
	if (index >= _bkdHtl.size())
		return;
	_bkdHtl.erase(next(_bkdHtl.begin(), index));
}

void Facade::cancelTck(int index)
{
	if (index >= _bkdTck.size())
		return;
	_bkdTck.erase(next(_bkdTck.begin(), index));
}
