// exercise7.cpp
// Sequential search
#include <iostream>

int main(void)
{
	using namespace std;
	const int LOW = 1;		// Global lower side
	const int HIGH = 100;	// Global higher side
	int guess = LOW;		// Computer guess
	string answer;			// User answer
	int tries = 0;

	// Player invitation
	cout << "\tWelcome to Guess My Number!\n";
	cout << "Computer guesses a number which user guessed in the range from " 
		 << LOW << " to " << HIGH << ".\n\n";

	// Main loop
	do
	{
		cout << "Is " << guess << " your guess? [Yes/no] ";
		cin >> answer;
		++guess;
		++tries;
	} while (answer != "Yes" && guess < HIGH);
	
	// Output of results and player farewell
	if (HIGH == guess)
		cout << "Your guess is " << guess << endl;
	cout << "\nI (computer) got it in " << tries << " tries!\n";
	cout << "Bye!\n";

	return 0;
}
