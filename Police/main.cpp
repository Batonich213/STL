#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<list>
#include<time.h>
using namespace std;
#define delimiter

const std::map<int, std::string> crime =
{
	{0, "Offense not defined(it's bag"},
	{1, "Over Speed"},
	{2, "Go on red"},
	{3, "Safety belt"},
	{4, "Departure to the opposite lane "},
	{5, "Insulting an officer"},
	{6, "Drunk driving"},
	{7, "Drift at trafic lights"},
	{8, "Bad Parking"}

};

#define TAKE_TIME int min, int hour, int day, int mouth, int year
#define GIVE_TIME  min,  hour,  day,  mouth,  year

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
	const char* get_time()const
	{
		//time_t t_time = mktime(&time);
		return asctime(&time);
	}
	void set_id(int id)
	{
		if (id >= crime.size()) id = 0;
		this->id = id;
	}
	void set_place(const std::string& place)
	{
		this->place = place;
	}
	void set_time(TAKE_TIME)
	{
		time = tm();
		time.tm_min = min;
		time.tm_hour = hour;
		time.tm_mday = day;
		time.tm_mon = mouth-1;
		time.tm_year = year-1900;
		time_t t_time = mktime(&time);
		tm*new_time = localtime(&t_time);
		time = *new_time;
		
	}


	// Contructor:
	Crime(int id, const std::string& place, TAKE_TIME)
	{
		set_id(id);
		set_place(place);
		set_time(GIVE_TIME);
	}
	~Crime(){}
};


std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	//return os << obj.get_id() << " " << obj.get_place() << " " << obj.get_time();
	/*os << obj.get_id() << " ";
	os << obj.get_place() << " ";
	os << obj.get_time() << " ";
	return os;*/
	return os << crime.at(obj.get_id()) << ", " << obj.get_place() << obj.get_time();
}


#define CRIME_CHEACK
#define TIME_CHECK
void main()
{
#ifdef CRIME_CHEACK
	Crime crime(10, "Lenin street ", 23, 22, 1, 5, 2023);
	cout << crime << endl;
#endif
	std::map<std::string, std::list<Crime>> base =
	{
		{"m777aa", {Crime(1,"Lenin Street 2", 22, 11, 29, 4, 2023), Crime(2, "Lenin Street", 23, 11, 29, 4, 2023), Crime(4, "Lenin Street", 24, 11, 29, 4, 2023) }},
		{"m001aa", {Crime(1,"Pushkin Street", 30, 18, 30, 4, 2023)}},
		{"b123cc", {Crime(8,"October Street", 10, 8, 8, 03, 2022),Crime(3,"October Street", 22, 18, 11, 04, 2022)}}

	};
	for (std::map<std::string,std::list<Crime>>::iterator it = base.begin(); it != base.end(); ++it)

	{
		cout << it->first << ":\n";
		for (std::list < Crime>::iterator c_it = it->second.begin(); c_it != it->second.end(); ++c_it)
		{
			cout << "\t" << *c_it << endl;
		}
		cout << "\n-------------------------------\n" << endl;
	}
}