// exercise4.cpp
// 'Generous visitor' program
#include <iostream>

int main(void)
{
	using namespace std;
	// Player invitation
	cout << "\t\tWelcome to the \'Generous visitor\' program!\n\n";

	// Data input
	cout << "Enter the cost of the lunch: $";
	float lunch_sum;
	cin >> lunch_sum;

	// Data calculating
	float tips_1, tips_2;
	tips_1 = 0.15 * lunch_sum;
	tips_2 = 0.20 * lunch_sum;

	// Data output
	cout << "Tips 1: $" << tips_1 << endl;
	cout << "Tips 2: $" << tips_2 << endl;

	return 0;
}
