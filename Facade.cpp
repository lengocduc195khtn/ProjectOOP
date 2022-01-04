#include"Facade.h"

Facade::Facade(vector<Flight*> flt, vector<Hotel*> htl, vector<Transport*> trs)
{
	for (auto item : flt)
		_avaFlt.push_back(item);
	for(auto item : htl)
		_avaHtl.push_back(item);
	for (auto item : trs)
		_avaTrs.push_back(item);	
}

vector<Ticket*> Facade::bookTicket(string dep, string arr, string depTime, string arrTime, bool isTwoWay)
{
	vector<Ticket*> res;
	string buffer;
	buffer = depTime.substr(0, 8); Date depD(buffer);
	buffer = depTime.substr(8); Time depT(buffer + "00");
	buffer = arrTime.substr(0, 8); Date arrD(buffer);
	buffer = arrTime.substr(8); Time arrT(buffer + "00");
	vector<Flight> filtered = Flight::showAvailable(_avaFlt, dep, arr, depT, depD, arrT, arrD);// showAvailable the flights
	for (auto flight : filtered)// show the general info of each
		cout << flight.info() << endl;
	int choice = 0;
	cin >> choice;//let the user choose the flight to see further detail	
	Flight* choseFlt = _avaFlt[choice];	
	cout << "Seat info:\n" << choseFlt->seatInfo();
	bool order = 0;// confirm order
	cin >> order;
	if (order) {
		Ticket* choseSeat = choseFlt->book();
		if (choseSeat) {
			_bkdTck.push_back(choseSeat);
			res.push_back(choseSeat);
			updateJson();// dummy function
		}
	}	
	if(isTwoWay){
		string temp;
		cout << "return departure date and time: ";
		getline(cin, temp);		
		buffer = temp.substr(0, 8); Date RdepD(buffer);
		buffer = temp.substr(8); Time RdepT(buffer + "00");
		cout << "return arrival date and time: ";
		getline(cin, temp);
		buffer = temp.substr(0, 8); Date RarrD(buffer);
		buffer = temp.substr(8); Time RarrT(buffer + "00");
		vector<Flight> filtered = Flight::showAvailable(_avaFlt, arr, dep, RdepT, RdepD, RarrT, RarrD);// showAvailable the flights
		for (auto flight : filtered)// show the general info of each
			cout << flight.info() << endl;
		int choice = 0;
		cin >> choice;//let the user choose the flight to see further detail	
		Flight* choseFlt = _avaFlt[choice];

		cout << "Seat info:\n" << choseFlt->seatInfo();
		bool order = 0;// confirm order
		cin >> order;
		if (order) {
			Ticket* choseSeat = choseFlt->book();
			if (choseSeat) {
				_bkdTck.push_back(choseSeat);
				res.push_back(choseSeat);
				updateJson();// dummy function
			}
		}
	}
	return res;
}

vector<Transport*> Facade::bookTransport(string src, string des, Time time)
{
	vector<Transport*> res;
	vector<Transport*> filtered = Transport::showAvailable(_avaTrs, time, src, des);
	for (auto item : filtered)// show the general info of each
		cout << item->info() << endl;
	int choice = 0;
	cin >> choice;//let the user choose the item to see further detail	
	Transport* chosetrs = _avaTrs[choice];
	bool order = 0;// confirm order
	cin >> order;
	if (order) {
		bool buffer = chosetrs->book();
		if (buffer) {
			_bkdTrs.push_back(chosetrs);
			res.push_back(chosetrs);
			updateJson();// dummy function
		}
	}
	return res;
}

vector<Hotel*> Facade::bookHotel(Date date, string location)// hỏi Thiên xem htl db có sẵn ngày chưa
{
	vector<Hotel*> res;
	vector<Hotel> filtered = Hotel::showAvailable(_avaHtl, location);
	for (auto item : filtered)// show the general info of each
		cout << item.info() << endl;
	int choice = 0, amount = 0;
	cin >> choice;//let the user choose the item to see further detail	
	Hotel* choseHtl = _avaHtl[choice];
	cout << "amount of room book:";
	cin >> amount;
	bool order = 0;// confirm order
	cin >> order;
	if (order) {
		bool buffer = choseHtl->book(amount);
		if (buffer) {
			_bkdHtl.push_back(choseHtl);
			res.push_back(choseHtl);
			updateJson();// dummy function
		}
	}
	return res;
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
	_bkdTrs[index]->cancel();
	_bkdTrs.erase(next(_bkdTrs.begin(), index));
}

void Facade::cancelHtl(int index)
{
	if (index >= _bkdHtl.size())
		return;
	_bkdHtl[index]->cancel();
	_bkdHtl.erase(next(_bkdHtl.begin(), index));
}

void Facade::cancelTck(int index)
{
	if (index >= _bkdTck.size())
		return;
	_bkdTck.erase(next(_bkdTck.begin(), index));
}

Facade::~Facade()
{
	for (auto item : _avaFlt)
		delete item;
	_avaFlt.clear();
	for (auto item : _avaHtl)
		delete item;
	_avaHtl.clear();
	for (auto item : _avaTrs)
		delete item;
	_avaTrs.clear();
}