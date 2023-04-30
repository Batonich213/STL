#include<iostream>
#include<map>
#include<list>
using namespace std;

const std::map<int, std::string> crime =
{
	{1, "Over Speed"},
	{2, "Go on red"},
	{3, "Safety belt"},
	{4, "Departure to the opposite lane "},
	{5, "Insulting an officer"},
	{6, "Drunk driving"},
	{7, "Drift at trafic lights"},

};

class Crime
{
	int id; // Article
	std::string place; // Place crime
	tm time; // Date, time 
public:
	int get_id()const
	{
		return id;
   }
	const std::string& get_place()const
	{
		return place;
	}
	const tm& get_time()const
	{
		return time;
	}
	void set_id(int id)
	{
		this->id = id;
	}
	void set_place(const std::string& place)
	{
		this->place = place;
	}
	void set_time(int min, int hour, int day, int mouth, int year)
	{
		time = tm();
		time.tm_min = min;
		time.tm_hour = hour;
		time.tm_mday = day;
		time.tm_mon = mouth;
		time.tm_year = year;
	}
};

void main()
{

}