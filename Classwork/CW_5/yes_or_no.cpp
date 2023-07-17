// yes_or_no.cpp
// Demonstrates working with return values and parameters.

#include <iostream>
#include <string>		// For std::string class 
using namespace std;

char ask_yes_no_1(void);
char ask_yes_no_2(string question);

int main(void)
{
	char answer_1 = ask_yes_no_1();
	cout << "Thanks for answering: " << answer_1 << "\n\n";

	char answer_2 = ask_yes_no_2("Do you wish to save the game?");
	cout << "Thanks for answering: " << answer_2 << endl;

	return 0;
}

char ask_yes_no_1(void)
{
	char response_1;

	do
	{
		cout << "Please enter \'y\' or \'n\': ";
		cin >> response_1;
	} while (response_1 != 'y' && response_1 != 'n');

	return response_1;
}

char ask_yes_no_2(string question)
{
	char response_2;

	do
	{
		cout << question << " (y/n): ";
		cin >> response_2;
	} while (response_2 != 'y' && response_2 != 'n');

	return response_2;
}
