// menu_chooser.cpp
// Demonstrates working with 'switch' operator
#include <iostream>

int main(void)
{
	using namespace std;
	cout << "Difficulty Levels\n\n";
	cout << "1 -- Easy\n";
	cout << "2 -- Normal\n";
	cout << "3 -- Hard\n\n";

	cout << "Choice: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
		case 1: 
			cout << "You picked Easy.\n";
			break;
		case 2:
			cout << "You picked Normal.\n";
			break;
		case 3:
			cout << "You picked Hard.\n";
			break;
		default:
			cout << "You picked an invalid choice.\n";
	}
	cout << "\nBye!\n";

	return 0;
}
