// word_jumble.cpp
// A classic puzzle game in which 
// the user guesses the words, with or without hints.

#include <iostream>
#include <string>		// For std::string
#include <cstdlib>
#include <ctime>

int main(void)
{
	using namespace std;
	enum Fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] = {
		{"wall", "Do you feel you\'re banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "it\'s what the game is all about."}
	};

	// Choice of word to jumble it
	srand(static_cast<unsigned>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string the_word = WORDS[choice][WORD];		// Word to be guessing
	string the_hint = WORDS[choice][HINT];		// Hint for the word

	// Jumbling the word
	string jumble = the_word;					// Jumbled version of the word
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		int index_1 = rand() % length;
		int index_2 = rand() % length;
		char temp = jumble[index_1];
		jumble[index_1] = jumble[index_2];
		jumble[index_2] = temp;
	}

	// Plyaer invitation
	cout << "\t\t\tWelcome to \'Word Jumble\'!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter \'hint\' for a hint.\n";
	cout << "Enter \'quit\' to quit the game.\n\n";
	
	// Main part of the game
	cout << "The jumble is: " << jumble << endl;
	string guess;
	cout << "\nYour guess: ";
	cin >> guess;
	while (guess != the_word && guess != "quit")
	{
		if ("hint" == guess)
			cout << "\"" << the_hint << "\"";
		else
			cout << "Sorry, that\'s not it.";

		cout << "\n\nYour guess: ";
		cin >> guess;
	}
	
	// Farewell to the player
	if (guess == the_word)
		cout << "\nThat\'s it! You guessed it!\n";
	cout << "\nThanks for playing.\n";

	return 0;
}
