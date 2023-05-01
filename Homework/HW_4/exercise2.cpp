// exercise2.cpp
// Displays the list of words in random order
#include <iostream>
#include <vector>		// For std::vector
#include <string>		// For std::string
#include <algorithm>	// For random_shuffle()
#include <cstdlib>		// For srand()
#include <ctime>		// For time()

int main(void)
{
	using namespace std;
	vector<string> words = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};
	vector<string>::const_iterator word;

	// Output of the vector
	cout << "Source vector:\n";
	for (word = words.begin(); word != words.end(); ++word)
	{
		cout << *word << endl;
	}

	// Randomization of vector elements
	srand(static_cast<unsigned>(time(0)));
	random_shuffle(words.begin(), words.end());

	// Output of the vector
	cout << "\nChanged vector:\n";
	for (word = words.begin(); word != words.end(); ++word)
	{
		cout << *word << endl;
	}

	return 0;
}
