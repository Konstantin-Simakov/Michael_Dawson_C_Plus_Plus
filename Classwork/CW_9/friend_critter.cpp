// friend.critter.cpp
// Demonstrates using friend functions.
#include <iostream>
#include <string>
using namespace std;

class Critter {
	// Specify next global functions as friend
	// in relation to the Critter class.
	friend void peek(const Critter & a_critter);
public:
	Critter(const string & name = "");
	// ostream & operator<<(ostream & os, const Critter & a_critter);
	string m_name;
private:
};

Critter::Critter(const string & name):
m_name(name)
{}

void peek(const Critter & a_critter);
ostream & operator<<(ostream & os, const Critter & a_critter);

int main(void)
{
	Critter crit("Poochie");
	
	cout << "Calling peek() function to access crit\'s prvate data member, m_name:\n";
	peek(crit);

	cout << "\nSending crit object to cout with the << operator:\n";
	cout << crit;

	return 0;
}

// A global friend function that could access
// to all member of a Critter class object.
void peek(const Critter & a_critter)
{
	cout << a_critter.m_name << endl;
}

// A global friend function that could access
// to all member of a Critter class object.
// An overloaded operator << letting to send
// a Critter class object to cout stream.
ostream & operator<<(ostream & os, const Critter & a_critter)
{
	os << "Critter object - "
	   << "m_name: " << a_critter.m_name << endl;

	return os;
}
