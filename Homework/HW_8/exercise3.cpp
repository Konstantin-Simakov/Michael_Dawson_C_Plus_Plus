// exercise3.cpp
// 
// Improvement of the critter_caretaker.cpp.
// List of virtual pets in the zoo farm 
// that the user cares about.
// 
#include <iostream>
#include <string>
#include <vector>
// For exit(), EXIT_SUCCESS, rand(), srand()
#include <cstdlib>
// For time()
#include <ctime>
using namespace std;

// Level of unhappiness named 'awful'.
const int AWFUL = 15;

class Critter {
public:
	Critter(const string & name = "", int hunger = 0, int boredom = 0);
	void talk();
	void eat(int food = 4);
	void play(int fun = 4);
	// Target method.
	void info();
private:
	string m_name;
	int m_hunger;
	int m_boredom;
	inline int get_mood() const;
	void pass_time(int time = 1);
};

int main()
{
	srand(static_cast<unsigned>(time(0)));
	vector<Critter> critters;
	cout << "Enter names of critters (empty line to finish input).\n\n";

	cout << "How will you name your critter? ";
	string name;
	getline(cin, name);
	int hunger, boredom;
	while (name != "")
	{
		// Random level of hunger and boredom for a critter.
		hunger = rand() % ((AWFUL + 1) / 2);
		boredom = rand() % ((AWFUL + 1) / 2);
		
		Critter crit(name, hunger, boredom);
		critters.push_back(crit);

		cout << "How will you name your critter? ";
		getline(cin, name);
	}

	unsigned num = critters.size();
	if (num != 0)
	{
		cout << "\nYou have " << num << " critters in your zoo farm.\n\n";
	}
	else
	{
		cout << "\nGood-bye.\n";
		exit(EXIT_SUCCESS);
	}

	string choice;
	do
	{
		cout << endl;
		cout << "\t\tCritter Caretaker\n\n";
		cout << "\t\t0 - Quit\n";
		cout << "\t\t1 - Listen to your critters\n";
		cout << "\t\t2 - Feed your critters\n";
		cout << "\t\t3 - Play with your critters\n\n";

		cout << "Choice: ";
		getline(cin, choice);
		// Quit.
		if ("0" == choice)
		{
			cout << "\nGood-bye.\n";
		}
		// Find out about critter's feeling.
		else if ("1" == choice)
		{
			for (auto i_crit = critters.begin(); i_crit != critters.end(); i_crit++)
			{
				i_crit->talk();
			}
		}
		// Feed the critter.
		else if ("2" == choice)
		{
			for (auto i_crit = critters.begin(); i_crit != critters.end(); i_crit++)
			{
				i_crit->eat();
			}
		}
		// Play with the critter.
		else if ("3" == choice)
		{
			for (auto i_crit = critters.begin(); i_crit != critters.end(); i_crit++)
			{
				i_crit->play();
			}
		}
		// Secret code to display the object content.
		else if ("status" == choice)
		{
			cout << "You entered the secret code!\n\n";
			for (auto i_crit = critters.begin(); i_crit != critters.end(); i_crit++)
			{
				i_crit->info();
			}
		}
		// Unknown user input.
		else
		{
			cout << "Sorry, there is no item " << choice << " in the menu.\n";
		}
	} while (choice != "0");

	return 0;
}

Critter::Critter(const string & name, int hunger, int boredom):
m_name(name),
m_hunger(hunger),
m_boredom(boredom)
{

}

void Critter::info()
{
	cout << "Critter\'s name: " << m_name << endl;
	cout << "Its hunger level: " << m_hunger << endl;
	cout << "Its boredom level: " << m_boredom << endl;
	cout << endl;
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
	if (unhappiness > AWFUL)
	{
		cout << "mad.";
	}
	else if (unhappiness > AWFUL - 5)
	{
		cout << "frustrated.";
	}
	else if (unhappiness > AWFUL - 10)
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
	m_hunger -= food;
	if (m_hunger < 0)
	{
		m_hunger = 0;
	}

	cout << "Brruppp.\n";
	pass_time();
}

void Critter::play(int fun)
{
	m_boredom -= fun;
	if (m_boredom < 0)
	{
		m_boredom = 0;
	}

	cout << "Wheee!\n";
	pass_time();
}
