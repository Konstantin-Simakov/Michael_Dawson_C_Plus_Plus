// guess_my_number.cpp
// Classic game of guessing numbers
#include <iostream>
#include <cstdlib>		// For rand()
#include <ctime>		// For time()

int main(void)
{
	using namespace std;
	srand(static_cast<unsigned>(time(0)));
	// Random number between 1 and 100
	int secret_num = rand() % 100 + 1;
	int tries = 0;
	int guess;

	cout << "\tWelcome to Guess My Number!\n\n";
	do
	{
		cout << "Enter a guess: ";
		cin >> guess;
		++tries;

		if (guess > secret_num)
			cout << "Lower...\n\n";
		else if (guess < secret_num)
			cout << "Hihger...\n\n";
		else
			cout << "That\'s it! You got it in " << tries << " tries!\n";
	} while (guess != secret_num);

	return 0;
}
