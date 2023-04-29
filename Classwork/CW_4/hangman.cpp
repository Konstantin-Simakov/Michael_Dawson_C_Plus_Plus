// hangman.cpp
// It's a "Hangman" classic game.
#include <iostream>
#include <string>		// For std::string
#include <vector>		// For std::vector
#include <algorithm>	// For using STL algorithms
#include <ctime>		// For srand()
#include <cctype>		// For toupper()

int main(void)
{
	using namespace std;
	// Preparing
	const int MAX_WRONG = 8;					// Max permissible number of mistakes
	vector<string> words;						// Collection of words for guessing

	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");

	srand(static_cast<unsigned>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];			// Guessed word
	
	int wrong = 0;								// Number of wrong variants
	string so_far(THE_WORD.size(), '-');		// Opened part of the word
	string used = "";							// Already gussed letters in the word

	cout << "Welcome to \'Hangman\'. Good luck!\n\n";

	// Main loop
	while (wrong < MAX_WRONG && so_far != THE_WORD)
	{
		// Beginning
		cout << "\nYou have " << MAX_WRONG - wrong 
			 << " incorrect guesses left.\n";
		cout << "\nYou\'ve used the following letters:\n" << used << endl;
		cout << "\nSo far, the word is: " << so_far << endl;

		// Getting user input
		cout << "\n\nEnter your guess: ";
		char guess;
		cin >> guess;
		// Conversion a letter to upper case because
		// the guessed word is written in upper case fully.
		guess = toupper(guess);

		// If the input letter already suggested by user
		while (used.find(guess) != string::npos)
		{
			cout << "\nYou\'ve already guessed " << guess << endl;

			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}
		// Else
		used += guess;

		// Checking if the suggested guess is in the word
		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "That\'s right! " << guess << " is in the word.\n";
			// Update so_far including to it 
			// the new guessed letter at all positions where it is.
			for (unsigned i = 0; i < THE_WORD.length(); ++i)
				if (THE_WORD[i] == guess)
					so_far[i] = guess;
		}
		else
		{
			cout << "Sorry, " << guess << " isn\'t in the word.\n";
			++wrong;
		}
	}

	// Game end
	if (MAX_WRONG == wrong)
		cout << "\nYou\'ve been hanged!\n";
	else
		cout << "\nYou guessed it!\n";
	cout << "The word was " << THE_WORD << endl;

	return 0;
}
