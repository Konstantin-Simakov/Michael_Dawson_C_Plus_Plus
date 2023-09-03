// critter_caretaker.cpp
// Demonstrates the game of a virtual pet.
#include <iostream>
using namespace std;

class Critter {
public:
	Critter(int hunger = 0, int boredom = 0);
	void talk(void);
	void eat(int food = 4);
	void play(int fun = 4);
private:
	int m_hunger;
	int m_boredom;
	inline int get_mood(void) const;
	void pass_time(int time = 1);
};

Critter::Critter(int hunger, int boredom):
m_hunger(hunger),
m_boredom(boredom)
{

}

void Critter::pass_time(int time)
{
	m_hunger += time;
	m_boredom += time;
}

inline int Critter::get_mood(void) const
{
	return m_hunger + m_boredom;
}

void Critter::talk(void)
{
	cout << "I\'m a critter and I feel ";

	int unhappiness = get_mood();
	if (unhappiness > 15)
	{
		cout << "mad.";
	}
	else if (unhappiness > 10)
	{
		cout << "frustrated.";
	}
	else if (unhappiness > 5)
	{
		cout << "okay.";
	}
	else
	{
		cout << "happy.";
	}
	cout << endl;

	pass_time();
}

void Critter::eat(int food)
{
	cout << "Brruppp.\n";
	m_hunger -= food;
	if (m_hunger < 0)
	{
		m_hunger = 0;
	}

	pass_time();
}

void Critter::play(int fun)
{
	cout << "Wheee!\n";
	m_boredom -= fun;
	if (m_boredom < 0)
	{
		m_boredom = 0;
	}

	pass_time();
}

int main(void)
{
	Critter crit;
	crit.talk();

	int choice;
	do
	{
		cout << "\nCritter Caretaker\n\n";
		cout << "0 - Quit\n";
		cout << "1 - Listen to your critter\n";
		cout << "2 - Feed your critter\n";
		cout << "3 - Play with your critter\n\n";

		cout << "Choice: ";
		cin >> choice;
		switch (choice)
		{
			case 0: 
				cout << "\nGood-bye.\n";
				break;
			case 1: 
				crit.talk();
				break;
			case 2:
				crit.eat();
				break;
			case 3:
				crit.play();
				break;
			default:
				cout << "\nSorry, but " << choice << " isn\'t a valid choice.\n";
		}
	} while (choice != 0);

	return 0;
}
