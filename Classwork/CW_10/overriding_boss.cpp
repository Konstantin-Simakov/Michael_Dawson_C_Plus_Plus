// overriding_boss.cpp
// Demonstrate calling and overriding of inherited methods 
// from the base class in the derived one.
#include <iostream>
using namespace std;

class Enemy {
public:
	Enemy(int damage = 10);
	// Method is created as a virtual one for later overriding.
	void virtual taunt() const;
	// Method is created as a virtual one for later overriding.
	void virtual attack() const;
private:
	int m_damage;
};

Enemy::Enemy(int damage):
m_damage(damage)
{}

void Enemy::taunt() const
{
	cout << "The enemy says he will fight you.\n";
}

void Enemy::attack() const
{
	cout << "Attack inflicts " << m_damage << " damage points.";
}


class Boss: public Enemy {
public:
	Boss(int damage = 30);
	// Using the virtual keyword is optional.
	void virtual taunt() const;
	// Using the virtual keyword is optional.
	void virtual attack() const;
	Boss(const Boss & a_boss);
	Boss & operator=(const Boss & a_boss);
};

Boss::Boss(int damage):
// Calling the base class constructor with an argument.
Enemy(damage)
{}

// Overriding the operator=() in the derivative class.
Boss & Boss::operator=(const Boss & a_boss)
{
	if (this != &a_boss)
	{
		Enemy::operator=(a_boss);
		// Some code...		
	}

	return *this;
}

// Copy constructor in the derivative class.
Boss::Boss(const Boss & a_boss):
Enemy(a_boss)
{
	// Some code...
}

// Overriding the method of the base class.
void Boss::taunt() const
{
	cout << "The boss says he will end your pitiful existence.\n";
}

// Overriding the method of the base class.
void Boss::attack() const
{
	// Calling the method of the base class.
	Enemy::attack();
	cout << " And boss laughs heartily at you.\n";
}


int main(void)
{
	cout << "Enemy object:\n";
	Enemy an_enemy;
	an_enemy.taunt();
	an_enemy.attack();

	cout << "\n\nBoss object:\n";
	Boss a_boss;
	a_boss.taunt();
	a_boss.attack();

	return 0;
}
