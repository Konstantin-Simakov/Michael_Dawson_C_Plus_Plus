// polymoriphci_bad_guy.cpp
// Demonstrate the dynamic calling of methods.
#include <iostream>
using namespace std;

class Enemy {
public:
	Enemy(int damage = 10);
	virtual ~Enemy();
	void virtual attack() const;
protected:
	int * m_p_damage;
};

Enemy::Enemy(int damage)
{
	m_p_damage = new int(damage);
}

Enemy::~Enemy()
{
	cout << "In Enemy destructor, deleting m_p_damage.\n";
	delete m_p_damage;
	m_p_damage = NULL;
}

void Enemy::attack() const
{
	cout << "An enemy attacks and inflicts " << *m_p_damage << " damage points.";
}


class Boss: public Enemy {
public:
	Boss(int multiplier = 3);
	virtual ~Boss();
	void virtual attack() const;
protected:
	int * m_p_multiplier;
};

Boss::Boss(int multiplier)
{
	m_p_multiplier = new int(multiplier);
}

Boss::~Boss()
{
	cout << "In Boss destructor, deleting m_p_multiplier.\n";
	delete m_p_multiplier;
	m_p_multiplier = NULL;
}

void Boss::attack() const
{
	cout << "A boss attacks and inflicts " 
		 << (*m_p_damage) * (*m_p_multiplier) << " damage points.";
}

int main(void)
{
	cout << "Calling attack() on Boss object through pointer to Enemy:\n";
	Enemy * p_bad_guy = new Boss();
	p_bad_guy->attack();

	cout << "\n\nDeleting the object pointed by the Enemy pointer:\n";
	delete p_bad_guy;
	p_bad_guy = NULL;

	return 0;
}
