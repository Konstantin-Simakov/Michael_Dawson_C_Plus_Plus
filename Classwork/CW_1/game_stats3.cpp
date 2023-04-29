// game_stats3.cpp
// Demonstrates working with symbolic constants
#include <iostream>

int main(void)
{
	using namespace std;
	enum Difficulty {NOVICE, EASY, NORMAL, HARD, UNBEATABLE};
	enum Ship_cost {FIHGTER_COST = 25, BOMBER_COST, CRUISER_COST = 50};
	const int ALIEN_POINTS = 150;
	int aliens_killed = 10;
	int score = aliens_killed * ALIEN_POINTS;
	Difficulty my_difficulty = EASY;
	// Difficulty my_difficulty = (Difficulty) 4;	// Permissible by C/C++ standards
	// Difficulty my_difficulty = Difficulty(4);	// Permissible only by C++ standard
	Ship_cost my_ship_cost = BOMBER_COST;

	cout << "Score: " << score << endl;
	cout << "\nTo upgrade my ship to a \"Cruiser\" will cost " 
		 << (CRUISER_COST - my_ship_cost) << " resource points.\n";
	cout << "NOVICE = " << NOVICE << endl;
	cout << "EASY = " << EASY << endl;
	cout << "NORMAL = " << NORMAL << endl;
	cout << "HARD = " << HARD << endl;
	cout << "UNBEATABLE = " << UNBEATABLE << endl;
	cout << "my_difficulty = " << my_difficulty << endl;

	return 0;
}
