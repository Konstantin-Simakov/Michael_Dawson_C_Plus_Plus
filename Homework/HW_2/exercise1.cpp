// exercise1.cpp
// 'Difficulty levels' program 
#include <iostream>

int main(void)
{
	using namespace std;
	cout << "Defficulty levels:\n\n";
	cout << "1 -- Easy\n";
	cout << "2 -- Normal\n";
	cout << "3 -- Hard\n\n";

	cout << "Choice: ";
	int choice;
	cin >> choice;
	enum {EASY = 1, NORMAL, HARD};
	switch (choice)
	{
		case EASY:
			cout << "You picked Easy.\n";
			break;
		case NORMAL:
			cout << "You picked Normal.\n";
			break;
		case HARD:
			cout << "You picked Hard.\n";
			break;
		default: 
			cout << "You picked an invalid choice.\n";
	}
	cout << "Bye!\n";

	return 0;
}
