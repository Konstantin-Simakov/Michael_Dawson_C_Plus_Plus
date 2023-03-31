// score_rater.cpp
// Demonstrates work with 'if' construction
#include <iostream>

int main(void)
{
	using namespace std;
	if (true)
		cout << "This is always displayed.\n\n";
	if (false)
		cout << "This is never displayed.\n\n";

	int score = 1000;
	if (score)
		cout << "At least you didn\'t score zero.\n\n";
	if (score >= 250)
		cout << "You scored 250 or more. Decent.\n\n";
	if (score >= 500)
	{
		cout << "You scored 500 or more. Nice.\n\n";
		if (score >= 1000)
			cout << "You scored 1000 or more. Impressive!\n";
	}

	return 0;
}
