// exercise2.cpp
// 
// Improve the abstract_creatrue.cpp program.
// Add to it an additional Orc_Boss class to be inherited from the Orc class.
// Every created object must have a health 1.5 times more than one for the base class.
// Also the greet() pure virtual method must be redefined in order to display a next message:
// "The orc boss growls hello.".
// 
#include <iostream>
using namespace std;

// Abstract class.
class Creature {
public:
	Creature(int health = 100);
	// Pure virtual method.
	virtual void greet() const = 0;
	virtual void display_health() const;
	virtual ~Creature();
protected:
	int m_health;
};

Creature::Creature(int health):
m_health(health)
{}

void Creature::display_health() const
{
	cout << "Health: " << m_health << endl;
}

Creature::~Creature()
{}

class Orc: public Creature {
public:
	Orc(int health = 120);
	virtual void greet() const;
	virtual ~Orc();
};

Orc::Orc(int health):
Creature(health)
{}

void Orc::greet() const
{
	cout << "The orc grunts hello.\n";
}

Orc::~Orc()
{}


class Orc_Boss: public Orc {
public:
	Orc_Boss();
	virtual void greet() const;
	virtual ~Orc_Boss();
private:
	double m_boss_factor;
};

Orc_Boss::Orc_Boss():
m_boss_factor(1.5)
{
	m_health *= m_boss_factor;
}

void Orc_Boss::greet() const
{
	cout << "The orc boss growls hello.\n";
}

Orc_Boss::~Orc_Boss()
{}


int main(void)
{
	// Create an orc.
	Creature * p_creature = new Orc();
	p_creature->greet();
	p_creature->display_health();
	delete p_creature;

	// Create an orc boss.
	p_creature = new Orc_Boss();
	p_creature->greet();
	p_creature->display_health();
	delete p_creature;

	return 0;
}
