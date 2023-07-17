// taking_damage.cpp
// Demonstrates inline functions

#include <iostream>
using namespace std;

inline int radiation(int health);

int main(void)
{
	int health = 80;
	cout << "Your health is " << health << "\n\n";

	health = radiation(health);
	cout << "After radiation exposure your health is " << health << "\n\n";

	health = radiation(health);
	cout << "After radiation exposure your health is " << health << "\n\n";

	health = radiation(health);
	cout << "After radiation exposure your health is " << health << "\n\n";

	return 0;
}

inline int radiation(int health)
{
	return health / 2;
}
