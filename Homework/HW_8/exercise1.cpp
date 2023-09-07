// exercise1.cpp
// 
// Improvement of the critter_caretaker.cpp program.
// Virtual pet that user takes care about.
// Added name of a critter and the ability to enter
// the amount of food and time to play with the animal.
// 
#include <iostream>
#include <string>
using namespace std;

class Critter {
public:
	Critter(string name, int hunger = 0, int boredom = 0);
	void talk();
	void eat();
	void play();
private:
	string m_name;
	int m_hunger;
	int m_boredom;
	inline int get_mood() const;
	void pass_time(int time = 1);
};

int main()
{
	cout << "How will you name your critter? ";
	string name;
	getline(cin, name);
	Critter crit(name);

	int choice;
	do
	{
		cout << endl;
		cout << "\t\tCritter Caretaker\n\n";
		cout << "\t\t0 - Quit\n";
		cout << "\t\t1 - Listen to your critter\n";
		cout << "\t\t2 - Feed your critter\n";
		cout << "\t\t3 - Play with your critter\n\n";

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

Critter::Critter(string name, int hunger, int boredom):
m_name(name),
m_hunger(hunger),
m_boredom(boredom)
{

}

void Critter::pass_time(int time)
{
	m_hunger += time;
	m_boredom += time;
}

inline int Critter::get_mood() const
{
	return m_hunger + m_boredom;
}

void Critter::talk()
{
	cout << "My name is " << m_name << " and I feel ";

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

void Critter::eat()
{
	cout << "How many kg of food do you want to give your critter?\n";
	cout << "(The recommended amount is 3 kg or more.)\n";
	cout << "Your amount of food: ";
	int food;
	cin >> food;

	m_hunger -= food;
	if (m_hunger < 0)
	{
		m_hunger = 0;
	}

	cout << "Brruppp.\n";
	pass_time();
}

void Critter::play()
{
	cout << "How many hours do you want to play with your critter?\n";
	cout << "(The recommended amount is 3 hours or more.)\n";
	cout << "Your amount of time: ";
	int fun;
	cin >> fun;

	m_boredom -= fun;
	if (m_boredom < 0)
	{
		m_boredom = 0;
	}

	cout << "Wheee!\n";
	pass_time();
}
