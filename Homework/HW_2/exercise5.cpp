// exericse5.cpp
// Classic game of guessing numbers with limited number of tries.
#include <iostream>
#include <cstdlib>		// For rand(), srand()
#include <ctime>		// For time()

int main(void)
{
	using namespace std;
	const int MAX_TRIES = 5;
	srand(static_cast<unsigned>(time(0)));
	// Random number between 1 and 100
	int secret_num = rand() % 100 + 1;
	int tries = 0;
	int guess;

	// Player invitation
	cout << "\tWelcome to \'Guess My Number\'!\n\n";
	// Main loop
	do
	{
		cout << "Enter a guess: ";
		cin >> guess;
		++tries;
		if (MAX_TRIES == tries)
		{
			cout << "You loose!\n";
			break;
		}

		if (guess > secret_num)
			cout << "Lower...\n\n";
		else if (guess < secret_num)
			cout << "Hihger...\n\n";
		else
			cout << "That\'s it! You got it in " << tries << " tries!\n";
	} while (guess != secret_num);
	// Player farewell
	cout << "Bye!\n";

	return 0;
}
