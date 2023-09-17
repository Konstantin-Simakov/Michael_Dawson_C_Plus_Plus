// critter_farm.cpp
// Demonstrates nested objects.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Critter {
public:
	Critter(const string & name = "");
	string get_name() const;
private:
	string m_name;
};

Critter::Critter(const string & name):
m_name(name)
{}

inline string Critter::get_name() const
{
	return m_name;
}

class Farm {
public:
	Farm(int spaces = 1);
	void add(const Critter & a_critter);
	void roll_call() const;
private:
	vector<Critter> m_critters;
};

Farm::Farm(int spaces)
{
	m_critters.reserve(spaces);
}

void Farm::add(const Critter & a_critter)
{
	m_critters.push_back(a_critter);
}

void Farm::roll_call() const
{
	for (auto iter = m_critters.begin(); iter != m_critters.end(); ++iter)
	{
		cout << iter->get_name() << " here.\n";
	}
}

int main(void)
{
	Critter crit("Poochie");
	cout << "My critter\'s name is " << crit.get_name() << endl;

	cout << "\nCreating critter farm.\n";
	Farm my_farm(3);

	cout << "\nAdding three critters to the farm.\n";
	my_farm.add(Critter("Moe"));
	my_farm.add(Critter("Larry"));
	my_farm.add(Critter("Curly"));

	cout << "\nCalling Roll...\n";
	my_farm.roll_call();

	return 0;
}
