// play_again2.cpp
// Demonstrates working with 'do-while' loop
#include <iostream>

int main(void)
{
	using namespace std;
	char again;

	do
	{
		cout << "\n**Played an exciting game**\n";
		cout << "Do you want to plya again? (y/n): ";
		cin >> again;
	} while ('y' == again);
	cout << "\nOkay, bye!\n";

	return 0;
}
