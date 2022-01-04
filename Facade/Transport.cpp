#include"Transport.h"

bool Transport::book()
{
	return true;
}

vector<Transport> Transport::showAvailable(vector<Transport*> list, string start, string end, Time time)
{
	vector<Transport> res;
	for (auto item : list)
		if (item->_locationStart == start && item->_time == time)
			if (item->_locationEnd == end)
				res.insert(res.begin(), *item);
			else
				res.push_back(*item);
	return res;
}
