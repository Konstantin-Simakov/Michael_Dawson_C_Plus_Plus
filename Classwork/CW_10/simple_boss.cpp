// simple_boss.cpp
// Demonstrate inheritance.
#include <iostream>
using namespace std;

class Enemy {
public:
	Enemy();
	void attack() const;
	int m_damage;
};

Enemy::Enemy():
m_damage(10)
{}

void Enemy::attack() const
{
	cout << "Attack inflicts " << m_damage << " damage points!\n";
}


class Boss: public Enemy {
public:
	Boss();
	void special_atack() const;
private:
	int m_damage_multiplier;
};

Boss::Boss():
m_damage_multiplier(3)
{}

void Boss::special_atack() const
{
	cout << "Special attack inflicts " << (m_damage_multiplier * m_damage)
		 << " damage points!\n";
}

int main(void)
{
	cout << "Creating an enemy.\n";
	Enemy enemy_1;
	enemy_1.attack();

	cout << "\nCreating a boss.\n";
	Boss boss_1;
	boss_1.attack();
	boss_1.special_atack();

	return 0;
}
