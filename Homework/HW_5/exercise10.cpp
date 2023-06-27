// exercise10.cpp
// Counts input words to "done" word.
#include <iostream>
#include <string>
using namespace std;

int to_done(void);

int main(void)
{
	int words = to_done();
	cout << "\nYou entered " << words << " words.\n";

	return 0;
}

int to_done(void)
{
	string word;
	int count = 0;

	cout << "Enter words (to finish enter \"done\"):\n";
	cin >> word;
	while (word != "done")
	{
		++count;
		cin >> word;
	}

	return count;
}
