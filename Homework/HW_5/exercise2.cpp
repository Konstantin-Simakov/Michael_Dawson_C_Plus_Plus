// exercise2.cpp
// It's a "Hangman" classic game but with functions.

#include <iostream>
#include <string>		// For std::string
#include <vector>		// For std::vector
#include <algorithm>	// For using STL algorithms
#include <ctime>		// For srand()
#include <cctype>		// For toupper()
using namespace std;

// Max permissible number of mistakes.
const int MAX_WRONG = 8;

void notification(int wrong, const string used, const string so_far);
char ask_letter(const string used);
bool check_guess(char guess, const string the_word);
void win_or_lose(int wrong, const string the_word);

int main(void)
{	
	// Preparing
	// Collection of words for guessing.
	vector<string> words = {
		"GUESS",
		"HANGMAN",
		"DIFFICULT"
	};

	srand(static_cast<unsigned>(time(0)));
	random_shuffle(words.begin(), words.end());
	// Guessed word.
	const string THE_WORD = words[0];

	// Current number wrong tries.
	int wrong = 0;
	// Opened part of the word.
	string so_far(THE_WORD.size(), '-');
	// Already guessed letters in the word.
	string used = "";

	cout << "Welcome to \'Hangman\'. Good luck!\n\n";

	// Main loop.
	while (wrong < MAX_WRONG && so_far != THE_WORD)
	{
		// Notification about remaining wrong attempts, 
		// already used letters, so far letters in the guessed word.
		notification(wrong, used, so_far);

		// Getting correct user input
		char guess = ask_letter(used);
		used += guess;

		// Checking if the suggested guess is in the word
		// and update 'so_far'.
		if (check_guess(guess, THE_WORD))
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

	// Game end.
	win_or_lose(wrong, THE_WORD);

	return 0;
}

void notification(int wrong, const string used, const string so_far)
{
	cout << "\nYou have " << MAX_WRONG - wrong 
		 << " incorrect guesses left.\n";
	cout << "\nYou\'ve used the following letters:\n" << used << endl;
	cout << "\nSo far, the words is: " << so_far << endl;
}

char ask_letter(const string used)
{
	char guess;

	cout << "\n\nEnter your guess: ";
	cin >> guess;
	// Conversion a letter to upper case because
	// the guessed word is written in upper case fully.
	guess = toupper(guess);

	// If the input letter has already been suggested by user
	while (used.find(guess) != string::npos)
	{
		cout << "\nYou\'ve already guessed " << guess << endl;

		cout << "Enter your guess: ";
		cin >> guess;
		guess = toupper(guess);
	}

	return guess;
}

bool check_guess(char guess, const string the_word)
{
	bool is_in = false;

	if (the_word.find(guess) != string::npos)
	{
		is_in = true;
	}

	return is_in;
}

void win_or_lose(int wrong, const string the_word)
{
	if (MAX_WRONG == wrong)
	{
		cout << "\nYou\'ve been hanged!\n";
	}
	else
	{
		cout << "\nYou guessed it!\n";
	}
	cout << "The word was " << the_word << endl;
}
