// score_rater2.cpp
// Demonstrates work with 'else' construction
#include <iostream>

int main(void)
{
	using namespace std;
	int score;
	
	cout << "Enter your score: ";
	cin >> score;
	if (score >= 1000)
		cout << "You scored 1000 or more. Impressive!\n";
	else
		cout << "You scored less than 1000.\n";

	return 0;
}
