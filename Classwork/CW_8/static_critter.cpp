// static_critter.cpp
// Demonstrates working with static data members and methods.
#include <iostream>
using namespace std;

class Critter {
public:
	// Declaration of a static varible member. 
	// Total number of existed Critter objects.
	static int s_total;
	Critter(int hunger = 0);
	// Prototype of a static method.
	static int get_total(void);
private:
	int m_hunger;
};

// Initialization of the static variable member.
int Critter::s_total = 0;

Critter::Critter(int hunger):
m_hunger(hunger)
{
	cout << "A critter has been born!\n";
	++s_total;
}

int Critter::get_total(void)
{
	return s_total;
}

int main(void)
{
	cout << "The total number of critters is: "
		 << Critter::s_total << "\n\n";

	Critter crit_1, crit_2, crit_3;
	cout << "\nThe total number of critters is: "
		 << Critter::get_total() << endl;

	return 0;
}
