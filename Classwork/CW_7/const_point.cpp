// const_point.cpp
// Demonstrates working with constant pointers,
// pointers to constant and constant pointers to constant.
#include <iostream>

int main(void)
{
	using namespace std;
	int score = 100;
	int * const p_score = &score;

	cout << "score = " << score << endl;
	cout << "*p_score = " << *p_score << endl;
	cout << "&score = " << &score << endl;
	cout << "p_score = " << p_score << endl;

	*p_score = 500;
	cout << "\n*p_score = " << *p_score << endl;
	cout << "score = " << score << endl;

	const int * p_number;
	int lives = 3;
	p_number = &lives;
	
	cout << "\nlives = " << lives << endl;
	cout << "*p_number = " << *p_number << endl;
	cout << "&lives = " << &lives << endl;
	cout << "p_number = " << p_number << endl;

	const int MAX_LIVES = 5;
	p_number = &MAX_LIVES;
	cout << "\nMAX_LIVES = " << MAX_LIVES << endl;
	cout << "&MAX_LIVES = " << &MAX_LIVES << endl;
	cout << "*p_number = " << *p_number << endl;
	cout << "p_number = " << p_number << endl;

	int bonus = 30;
	const int * const P_BONUS = &bonus;
	cout << "\nbonus = " << bonus << endl;
	cout << "*P_BONUS = " << *P_BONUS << endl;
	cout << "&bonus = " << &bonus << endl;
	cout << "P_BONUS = " << P_BONUS << endl;

	return 0;
}
