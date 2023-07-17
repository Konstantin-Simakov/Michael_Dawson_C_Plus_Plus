// swap.cpp
// Demonstrates passing references to change argument variables
#include <iostream>
using namespace std;

void bad_swap(int x, int y);
void good_swap(int & x, int & y);

int main(void)
{
	int my_score = 150;
	int your_score = 1000;

	cout << "Original values\n";
	cout << "my_score: " << my_score << endl;
	cout << "your_score: " << your_score << "\n\n";

	cout << "Calling bad_swap()\n";
	bad_swap(my_score, your_score);
	cout << "my_score: " << my_score << endl;
	cout << "your_score: " << your_score << "\n\n";

	cout << "Calling good_swap()\n";
	good_swap(my_score, your_score);
	cout << "my_score: " << my_score << endl;
	cout << "your_score: " << your_score << endl;

	return 0;
}

void bad_swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

void good_swap(int & x, int & y)
{
	int temp = x;
	x = y;
	y = temp;
}
