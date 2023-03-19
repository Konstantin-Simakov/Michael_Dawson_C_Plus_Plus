// game_stats.cpp -- declarations and initializaion for variables
#include <iostream>

int main(void)
{
	using namespace std;
	int score; 
	double distance;
	char play_again;
	bool shield_up;
	short lives, aliens_killed;

	score = 0;
	distance = 1200.76;
	play_again = 'y';
	shield_up = false;
	lives = 3;
	aliens_killed = 10;
	double engine_temp = 6572.89;

	cout << "\nscore: " << score << endl;
	cout << "shield_up: " << shield_up << endl;
	cout << "distance: " << distance << endl;
	cout << "play_again: " << play_again << endl;
	cout << "lives: " << lives << endl;
	cout << "aliens_killed: " << aliens_killed << endl;
	cout << "engine_temp: " << engine_temp << endl;

	int fuel;
	cout << "\nHow much fuel? ";
	cin >> fuel;
	cout << "fuel: " << fuel << endl;

	typedef unsigned short u_sh;
	u_sh bonus = 10;
	cout << "\nbonus: " << bonus << endl;

	return 0;
}
