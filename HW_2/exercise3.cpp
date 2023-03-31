// exercise3.cpp
#include <iostream>

int main(void)
{
	using namespace std;
	const int LOW = 1;		// Global lower side
	const int HIGH = 100;	// Global higher side
	int low = LOW;			// Current lower side
	int high = HIGH;		// Current higher side
	int guess;				// User guess
	string answer;			// User answer
	int tries = 0;

	cout << "\tWelcome to Guess My Number!\n";
	cout << "Computer guesses a number which user guessed in the range from 1 to 100.\n\n";

	do
	{
		guess = (low + high) / 2;
		cout << "Is " << guess << " your number? [Higher/Lower] ";
		++tries;

		cin >> answer;
		if ("Lower" == answer)
			high = guess;
		else
			low = guess;
	} while (answer != "Yes");
	cout << "\nI (computer) got it in " << tries << " tries!\n";
	cout << "Bye!\n";

	return 0;
}
