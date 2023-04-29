// exercise7.cpp
// Binary search
#include <iostream>

int main(void)
{
	using namespace std;
	const int LOW = 1;		// Global lower side
	const int HIGH = 100;	// Global higher side
	int low = LOW - 1;		// Current lower side
	int high = HIGH;		// Current higher side
	int guess;				// Computer guess
	string answer;			// User answer
	int tries = 0;

	// Player invitation
	cout << "\tWelcome to Guess My Number!\n";
	cout << "Computer guesses a number which user guessed in the range from 1 to 100.\n\n";

	// Main loop
	do
	{
		// Low side processing
		if (guess - low == 1)
		{
			cout << "Case: Low side processing\n";
			cout << "Your guess is " << guess << endl;
			break;
		}
		// High side processing
		if (high - guess == 1)
		{
			cout << "Case: High side processing\n";
			guess = high;
			cout << "Your guess is " << guess << endl;
			break;
		}


		// Common working of the algorithm 
		guess = (low + high) / 2;
		if (guess - low == 1 && high - guess == 1)
		{
			cout << "Case: Common working of the algorithm\n";
			cout << "Your guess is " << guess << endl;
			break;
		}
		cout << "Is " << guess << " your number? [Yes/Higher/Lower] ";
		++tries;

		// Input processing
		cin >> answer;
		while (answer != "Lower" && answer != "Higher" && answer != "Yes")
		{
			cout << "Input error.\nYour answer again: ";
			cin >> answer;
		}
		if ("Lower" == answer)
			high = guess;
		else
			low = guess;
	} while (answer != "Yes");

	// Player farewell
	cout << "\nI (computer) got it in " << tries << " tries!\n";
	cout << "Bye!\n";

	return 0;
}
