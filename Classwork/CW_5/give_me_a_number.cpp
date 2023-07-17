// give_me_a_number.cpp
// Demonstrates working with default arguments

#include <iostream>
using namespace std;

int ask_number(int high, int low = 1);

int main(void)
{
	int number = ask_number(5);
	cout << "Thanks for entering " << number << "\n\n";

	number = ask_number(10, 5);
	cout << "Thanks for entering " << number << "\n\n";

	return 0;
}

int ask_number(int high, int low)
{
	int num;

	do
	{
		cout << "Please enter a number (" << low << "-" << high << "): ";
		cin >> num;
	} while (num > high || num < low);

	return num;
}
