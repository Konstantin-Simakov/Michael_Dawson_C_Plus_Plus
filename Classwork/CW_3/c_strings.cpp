// c_strings.cpp
// Demonstrate c-strings in C++.
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
	string phrase_1 = "Game Over!!!";
	cout << "phrase_1 is " << phrase_1 << endl;

	char phrase_2[] = "Game Over!!!";
	cout << "phrase_2 is " << phrase_2 << endl;

	char phrase_3[] = {'G', 'a', 'm', 'e', ' ', 'O', 'v', 'e', 'r', '!', '!', '!', '\0'};
	cout << "phrase_3 is " << phrase_3 << endl;

	char phrase_4[81] = "Game Over!!!";
	cout << "phrase_4 is " << phrase_4 << endl;

	string word_1 = "Game";
	char word_2[] = " Over!!!";
	string phrase = word_1 + word_2;
	if (word_1 != word_2)
	{
		cout << "\nword_1 and word_2 are not equal.\n";
	}
	if (phrase.find(word_2) != string::npos)
	{
		cout << "word_2 is contained in phrase.\n";
	}

	return 0;
}
