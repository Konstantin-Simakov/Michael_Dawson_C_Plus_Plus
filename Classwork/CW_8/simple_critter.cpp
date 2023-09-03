// simple_critter.cpp
// Demonstrates creating a new type.
#include <iostream>
using namespace std;

// Definition of a new class Critter.
class Critter {
public:
	// Data member
	int hunger;
	// Function member
	void greet(void);
};

// Definition of the function member.
void Critter::greet(void)
{
	cout << "Hi, I\'m a critter. My hunger level is " << hunger << ".\n";
}

int main(void)
{
	Critter crit_1;
	Critter crit_2;

	crit_1.hunger = 9;
	cout << "crit_1\'s hunger level is " << crit_1.hunger << ".\n";

	crit_2.hunger = 3;
	cout << "crit_2\'s hunger level is " << crit_2.hunger << ".\n\n";

	crit_1.greet();
	crit_2.greet();

	return 0;
}
