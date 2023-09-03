// constructor_critter.cpp
// Demonstrates working with constructors.
#include <iostream>
using namespace std;

class Critter {
public:
	int m_hunger;
	int m_boredom;
	
	// Constructor prototype.
	Critter(int hunger = 0, int boredom = 0);
	void greet(void);
};

// Constructor definition.
Critter::Critter(int hunger, int boredom):
m_hunger(hunger),
m_boredom(boredom)
{
	cout << "A new critter has been born!\n\n";
}

void Critter::greet(void)
{
	cout << "Hi, I\'m a critter.\n";
	cout << "My hunger level is " << m_hunger << ".\n";
	cout << "And my boredom level is " << m_boredom << ".\n";
}

int main(void)
{
	Critter crit(5, 7);

	crit.greet();

	return 0;
}
