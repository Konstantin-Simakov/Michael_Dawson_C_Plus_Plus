// private_critter.cpp
// Demonstrates setting access levels to members.
#include <iostream>
using namespace std;

class Critter {
// The beginning of a public section.
public:
	Critter(int hunger = 0);
	inline int get_hunger(void) const;
	void set_hunger(int hunger);
// The beginning of a private section.
private:
	int m_hunger;
};

Critter::Critter(int hunger):
m_hunger(hunger)
{
	cout << "A new critter has been born!" << endl;
}

inline int Critter::get_hunger(void) const
{
	return m_hunger;
}

void Critter::set_hunger(int hunger)
{
	if (hunger < 0)
	{
		cout << "You can\'t set a critter\'s hunger to a negative number.\n\n";
	}
	else
	{
		m_hunger = hunger;
	}
}

int main(void)
{
	Critter crit(5);
	// cout << crit.m_hunger; // Unallowed, m_hunger member is private!
	cout << "Calling get_hunger() method: " << crit.get_hunger() << "\n\n";
	
	cout << "Calling set_hunger method with -1.\n";
	crit.set_hunger(-1);

	cout << "Calling set_hunger() method with 9.\n";
	crit.set_hunger(9);
	cout << "Calling get_hunger() method: " << crit.get_hunger() << endl;

	return 0;
}
