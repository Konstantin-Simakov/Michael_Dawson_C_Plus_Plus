// exercise1.cpp
// 
// Improve the simple_boss_2.cpp program.
// Add a Final_Boss class to be inherited from the Boss class and 
// add to it an additional data member m_mega_factor with the private or protected access.
// Add to the Final_Boss class a mega_attack() method inflicting 
// the damage 10 times more than the special_attack() method. 
// 
#include <iostream>
using namespace std;

class Enemy {
public:
	Enemy();
	void attack() const;
protected:
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
	void special_attack() const;
protected:
	int m_damage_multiplier;
};

Boss::Boss():
m_damage_multiplier(3)
{}

void Boss::special_attack() const
{
	cout << "Special attack inflicts " << (m_damage_multiplier * m_damage)
		 << " damage points!\n";
}

class Final_Boss: public Boss {
public:
	Final_Boss();
	void mega_attack() const;
private:
	int m_mega_factor;
};

Final_Boss::Final_Boss(): 
Boss(),
m_mega_factor(10)
{}

void Final_Boss::mega_attack() const
{
	cout << "Mega attack inflicts " << m_mega_factor * (m_damage_multiplier * m_damage)
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
	boss_1.special_attack();

	cout << "\nCreating a final boss.\n";
	Final_Boss f_boss_1;
	f_boss_1.attack();
	f_boss_1.special_attack();
	f_boss_1.mega_attack();

	return 0;
}
