// exercise1.cpp
// Finding and fixing bugs

#include <iostream>
#include <string>		// For std::string

int main(void)
{
	using namespace std;
	string phrase = "Game Over!!!";

	for (unsigned i = 0; i < phrase.size(); ++i)
	{
		cout << "Character at position " << i << " is " << phrase[i] << endl;
	}
	cout << "\nBye!\n";

	return 0;
}