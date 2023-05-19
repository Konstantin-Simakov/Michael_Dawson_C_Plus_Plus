// exercise7.cpp
/*
Create a game in which the computer chooses a word and the player guesses it. 
The computer tells the player how many letters are in the word, 
and gives n attempts to guess the letter, 
and the program can only answer "Yes" and "no". 
Provide a player win or loss with an appropriate message.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main(void)
{
	using namespace std;
	enum {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 5;
	// The words and thier hints
	const string words[NUM_WORDS][NUM_FIELDS] = {
		{"wall", "Do you feel you\'re banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It\'s what the game is all about."}
	};
	// The number of attempts for guessing a letter in the word
	const int ATTEMPTS = 5;
	const char DUMMY = '-';
	const string QUIT = "quit";

	// Choice of the word and its hint
	srand(static_cast<unsigned>(time(0)));
	int choice = rand() % NUM_WORDS;
	const string THE_WORD = words[choice][WORD];
	string word = THE_WORD;
	string the_hint = words[choice][HINT];
	string so_far(word.size(), DUMMY);

	// Player invitation
	cout << "\t\t\tWelcome to \'Guess the word\'!\n\n";
	cout << "\t\t\tEnter \'quit\' to quit the game.\n\n";
	cout << the_hint << "\n\n";

	// Main part of the game
	string letter;
	int tries = 0;
	do
	{
		cout << "Your word: " << so_far << endl;

		cout << "Enter a letter: ";
		cin >> letter;

		size_t index;
		if ((index = word.find(letter)) != string::npos && letter.size() == 1)
		{
			so_far[index] = letter[0];
			word[index] = DUMMY;
			tries = 0;
		}
		else if (QUIT == letter)
		{
			break;
		}
		else if (string::npos == index)
		{
			tries++;
			if (ATTEMPTS == tries)
			{
				break;
			}
			cout << "You have not guessed. You have " << ATTEMPTS - tries 
				 << " attempts for guessing a letter.\n";
		}
	} while (so_far != THE_WORD);

	// Farewell to the player with an according message
	if (QUIT == letter)
	{
		cout << "You lose because you refuse to continue the game.\n";
	}
	else if (ATTEMPTS == tries)
	{
		cout << "You lose because you exceed the number of attempts for guessing a letter in the word.\n";
	}
	else if (THE_WORD == so_far)
	{
		cout << "You win! The word was \'" << so_far << "\'.\n";
	}
	else
	{
		cout << "Do-while error.\n";
	}
	cout << "\nBye!\n";

	return 0;
}
