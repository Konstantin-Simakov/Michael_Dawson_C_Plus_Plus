// exercise1.cpp
/* Asks the number in the range between low and high
 * with parameters by default. 
 */

#include <iostream>
using namespace std;

int ask_number(int low = 1, int high = 100);

int main(void)
{
	int num = ask_number();

	cout << "\nThe number is " << num << endl;

	return 0;
}

int ask_number(int low, int high)
{
	int num;

	do
	{
		cout << "Enter a number between " << low << " and " << high << ": ";
		cin >> num;
	} while (num < low || num > high);

	return num;
}
