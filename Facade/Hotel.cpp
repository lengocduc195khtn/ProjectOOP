#include"Hotel.h"

string Hotel::info()
{
	string res;
	res += "Hotel' name: " + _name + "\n";
	res += "Room left: " + to_string(_roomLeft)+ "\n";
	res += "Price: " + to_string(_cost);
	return res;
}

string Hotel::receipt()
{
	string res;
	res += "Hotel' name: " + _name + "\n";
	res += "Hotel' location: " + _location + "\n";
	res += "Price: " + to_string(_cost);
	return res;
}

bool Hotel::book(int amount)
{
	if (amount > _roomLeft)
		return false;
	_roomLeft -= amount;
	return true;
}

vector<Hotel> Hotel::showAvailable(vector<Hotel*> list, string location)
{
	vector<Hotel> res;
	for (auto item : list)
		if (item->_location == location)
			res.push_back(*item);
	return res;
}

void Hotel::cancel()
{
	this->_roomLeft++;
}
