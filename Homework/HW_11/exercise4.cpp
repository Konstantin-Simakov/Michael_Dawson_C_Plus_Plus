// exercise4.cpp
// 
// Create the class 'Subscriber' with the next data members:
// 1) Last name;
// 2) First name;
// 3) Middle name;
// 4) Address;
// 5) Credit card number;
// 6) Time of long-distance calls;
// 7) Time of city calls.
// 
// And with next methods:
// 1) Constructor;
// 2) Getters;
// 3) Setters;
// 5) Overloaded >> operator;
// 4) Overloaded << operator.
// 
// Tasks:
// 1. Read an array of this class objects.
// 2. Display information regarding subscribers
// whose time of city calls exceeds the specified one.
// 3. Display infromation regarding subscribers who used long-distance calls.
// 4. List of subscribers in alphabetical order.
// 
// Use file I/O only.
// 
#include <iostream>
// For std::ifstream, std::ofstream classes.
#include <fstream>
// For exit(), EXIT_FAILURE.
#include <cstdlib>
using namespace std;

// The size of the target array.
const int SIZE = 20;
// Limit time on city calls.
const int TIME_CITY = 22500000;

class Subscriber {
	friend istream & operator>>(istream & in, Subscriber & sub);
	friend ostream & operator<<(ostream & os, const Subscriber & s);
public:
	Subscriber(
			const string & last_name = "",
			const string & first_name = "",
			const string & middle_name = "",
			const string & address = "",
			int credit_card_num = 0,
			int time_long_dist = 0,
			int time_city_calls = 0);
	// Inline methods.
	// Getters:
	string get_last_name() const {return m_last_name;}
	string get_first_name() const {return m_first_name;}
	string get_middle_name() const {return m_middle_name;}
	string get_address() const {return m_address;}
	int get_credit_card_num() const {return m_credit_card_num;}
	int get_time_long_dist() const {return m_time_long_dist;}
	int get_time_city_calls() const {return m_time_city_calls;}
	// Setters:
	void set_last_name(string last_name) {m_last_name = last_name;}
	void set_first_name(string first_name) {m_first_name = first_name;}
	void set_middle_name(string middle_name) {m_middle_name = middle_name;}
	void set_address(string address) {m_address = address;}
	void set_credit_card_num(int credit_card_num) {m_credit_card_num = credit_card_num;}
	void set_time_long_dist(int time_long_dist) {m_time_long_dist = time_long_dist;}
	void set_time_city_calls(int time_city_calls) {m_time_city_calls = time_city_calls;}
private:
	string m_last_name;
	string m_first_name;
	string m_middle_name;
	string m_address;
	int m_credit_card_num;
	int m_time_long_dist;
	int m_time_city_calls;
};

Subscriber::Subscriber(
		const string & last_name,
		const string & first_name,
		const string & middle_name,
		const string & address,
		int credit_card_num,
		int time_long_dist,
		int time_city_calls):
m_last_name(last_name),
m_first_name(first_name),
m_middle_name(middle_name),
m_address(address),
m_credit_card_num(credit_card_num),
m_time_long_dist(time_long_dist),
m_time_city_calls(time_city_calls)
{}

istream & operator>>(istream & in, Subscriber & sub);
ostream & operator<<(ostream & os, const Subscriber & sub);
int init(std::istream & in, Subscriber subs[], int size);
// Display people whose time city calls exceeds the TIME_CITY value.
void display_time_city(std::ostream & out, const Subscriber subs[], int n);
// Display people who used long-distance calls.
void display_long_dist(std::ostream & out, const Subscriber subs[], int n);
// Sort the pointers to people array.
static void sort_alphabetical(std::ostream & out, Subscriber * p_subs[], int n);
// List people in alphabetical order.
void list_alphabetical(std::ostream & out, Subscriber * p_subs[], int n);
void init(Subscriber * p_subs[], Subscriber subs[], int n);

int main(void)
{
	// Open the file for reading.
	const string INPUT_FILENAME = "input4.txt";
	std::ifstream fin(INPUT_FILENAME);
	if (!fin.is_open())
	{
		cerr << "Couldn\'t open the file " << INPUT_FILENAME << endl;
		exit(EXIT_FAILURE);
	}

	// Read the data.
	Subscriber people[SIZE];
	int cur = init(fin, people, SIZE);
	fin.close();

	// Open the file for writing.
	const string OUTPUT_FILENAME = "output4.txt";
	std::ofstream fout(OUTPUT_FILENAME);
	if (!fout.is_open())
	{
		cerr << "Couldn\'t open the file " << OUTPUT_FILENAME << endl;
		exit(EXIT_FAILURE);
	}

	// Processing the data.
	// 2.
	fout << "Subscribers whose time city calls exceeds " << TIME_CITY << " seconds:\n";
	display_time_city(fout, people, cur);
	fout << endl;
	// 3. 
	fout << "Subscribers who used long-distance calls:\n";
	display_long_dist(fout, people, cur);
	fout << endl;
	
	// 4. 
	Subscriber ** p_people = new Subscriber * [cur];
	init(p_people, people, cur);

	fout << "The list of subscribers in alphabetical order:\n";
	list_alphabetical(fout, p_people, cur);
	
	delete [] p_people;
	fout.close();

	return 0;
}

void init(Subscriber * p_subs[], Subscriber subs[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		p_subs[i] = &subs[i];
	}
}

// Sort with insertion algorithm.
static void sort_alphabetical(std::ostream & out, Subscriber * p_subs[], int n)
{
	Subscriber * temp = NULL;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			if (p_subs[i]->get_last_name() > p_subs[j]->get_last_name() || 
				p_subs[i]->get_first_name() > p_subs[j]->get_first_name() ||
				p_subs[i]->get_middle_name() > p_subs[j]->get_middle_name())
			{
				temp = p_subs[i];
				p_subs[i] = p_subs[j];
				p_subs[j] = temp;
			}
		}
	}
}

void list_alphabetical(std::ostream & out, Subscriber * p_subs[], int n)
{
	sort_alphabetical(out, p_subs, n);
	for (int i = 0; i < n; ++i)
	{
		out << *p_subs[i] << endl;
	}
}

void display_long_dist(std::ostream & out, const Subscriber subs[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (subs[i].get_time_long_dist() > 0)
		{
			out << subs[i] << endl;
		}
	}
}

void display_time_city(std::ostream & out, const Subscriber subs[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (subs[i].get_time_city_calls() > TIME_CITY)
		{
			out << subs[i] << endl;
		}
	}
}

int init(std::istream & in, Subscriber subs[], int size)
{
	int i;

	for (i = 0; i < size; ++i)
	{
		if (!(in >> subs[i]))
		{
			break;
		}
	}

	// Check the stop reading reason.
	if (in.eof())
	{
		cerr << "End of file reached.";
	}
	else if (in.fail())
	{
		cerr << "Input was terminated by mismatch data.";
	}
	else
	{
		cerr << "Input was terminated by unknown reason.";
	}
	cerr << endl;

	return i;
}

istream & operator>>(istream & in, Subscriber & sub)
{
	string last_name, first_name, middle_name, address;
	int credit_card_num, time_long_dist, time_city_calls;

	in >> last_name >> first_name >> middle_name >> address
	   >> credit_card_num >> time_long_dist >> time_city_calls;
	if (in)
	{
		sub.set_last_name(last_name);
		sub.set_first_name(first_name);
		sub.set_middle_name(middle_name);
		sub.set_address(address);
		sub.set_credit_card_num(credit_card_num);
		sub.set_time_long_dist(time_long_dist);
		sub.set_time_city_calls(time_city_calls);
	}

	return in;
}

ostream & operator<<(ostream & os, const Subscriber & s)
{
	// Display all data member values.
	os << s.get_last_name() << " " << s.get_first_name() << " " << s.get_middle_name() << ": ";
	os << s.get_address() << ", " << s.get_credit_card_num() << ", "
	   << s.get_time_long_dist() << ", " << s.get_time_city_calls();

	return os;
}
