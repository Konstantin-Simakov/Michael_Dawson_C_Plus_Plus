// exercise3.cpp
// Asks a number from a user and displays it.
// Using with ask_number() user function and default parameters.

#include <iostream>
using namespace std;

int ask_number(string question = "Your number: ");

int main(void)
{
	// Testing the function ask_number().
	int num = ask_number("What number do you want to enter? ");
	cout << "Your number is " << num << "\n\n";

	num = ask_number();
	cout << "Your number is " << num << endl;

	return 0;
}

int ask_number(string question)
{
	int num;

	cout << question;
	(cin >> num).get();

	return num;
}
