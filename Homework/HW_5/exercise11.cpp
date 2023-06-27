// exercise11.cpp
// Counts all characters, spaces,
// alphabetic ones and words.

#include <iostream>
#include <cctype>		// For isspace()
using namespace std;

int count_words(string);

int main(void)
{
	string text;

	cout << "Enter a text: ";
	getline(cin, text);

	int words = count_words(text);
	cout << "The number of words is " << words << endl;

	return 0;
}

int count_words(string text)
{
	const char SPACE = ' ';
	int words = 0;
	int spaces = 0;
	int alphabetics = 0;
	int punctuations = 0;

	bool in_word = false;
	for (unsigned i = 0; i < text.size(); i++)
	{
		// Words
		if (!isspace(text[i]) && !in_word)
		{
			++words;
			in_word = true;
		}
		else if (isspace(text[i]) && in_word)
		{
			in_word = false;
		}

		// Spaces
		if (SPACE == text[i])
		{
			++spaces;
		}
		// Alphabetics
		if (isalpha(text[i]))
		{
			++alphabetics;
		}
		// Punctuations
		if (ispunct(text[i]))
		{
			++punctuations;
		}
	}

	// Additional output.
	cout << "The number of all characters is " << text.size() << endl;
	cout << "The number of spaces is " << spaces << endl;
	cout << "The number of alphabetics is " << alphabetics << endl;
	cout << "The number of punctuations is " << punctuations << endl;

	return words;
}
