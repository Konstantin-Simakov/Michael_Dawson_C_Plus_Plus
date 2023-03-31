// play_again.cpp
// Demonstrates working with 'while' loop
#include <iostream>

int main(void)
{
	using namespace std;
	char again = 'y';

	while ('y' == again)
	{
		cout << "\n**Played an exciting game**\n";
		cout << "Do you want to play again? (y/n): ";
		cin >> again;
	}
	cout << "\nOkay, bye!\n";

	return 0;
}
