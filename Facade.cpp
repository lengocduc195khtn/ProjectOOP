#include"Facade.h"

void Facade::showAvaTck(string time, string src, string des, bool isTwoWay)
{
	vector<Flight> filtered = Flight::find(_avaFlt, src, des, time);// filter the flights
	for (auto flight : filtered)// show the general info of each
		cout << flight.info() << endl;
	int choice, rch, cch, numOfTck = 0;
	cin >> choice;//let the user choose the flight to see further detail	
	Flight* choseFlt = _avaFlt[choice];
	choseFlt->showEmptySeat(isTwoWay);
	cout << "How many ticket: ";
	cin >> numOfTck;
	for (int i = 0; i < numOfTck; i++) {
		cout << "Choose row index: ";
		cin >> rch;//let the user choose the row of the tck
		cout << "Choose column index: ";
		cin >> cch;//let the user choose the col of the tck
		cout << "Seat info:\n" << choseFlt->seatInfo(rch, cch);
		bool order = 0;// confirm order
		cin >> order;
		if (order) {
			Ticket* choseSeat = choseFlt->book(rch, cch);
			if (choseSeat) {
				_bkdTck.push_back(choseSeat);
				updateJson();// dummy function
			}				
		}					
	}	
}