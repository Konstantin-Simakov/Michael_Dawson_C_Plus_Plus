// game_stats2.cpp
// Demonstrates arithmetical operations with variables
#include <iostream>

int main(void)
{
	using namespace std;
	unsigned int score = 5000;
	cout << "score: " << score << endl;

	score = score + 100;
	cout << "score: " << score << endl;

	score += 100;
	cout << "score: " << score << endl;

	int lives = 3;
	++lives;		// lives = lives + 1; lives += 1;
	cout << "lives: " << lives << endl;

	lives = 3;
	lives++;		// lives = lives + 1; lives += 1;
	cout << "lives: " << lives << endl;

	int bonus = ++lives * 10;
	cout << "lives = " << lives << ", bonus = " << bonus << endl;

	lives = 4;
	bonus = lives++ * 10;
	cout << "lives = " << lives << ", bonus = " << bonus << endl;

	// Integer overflow
	score = 4294967295; // Max unsigned int value
	cout << "\nscore: " << score << endl;
	++score;			// 0
	cout << "score: " << score << endl;

	return 0;
}
