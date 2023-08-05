// swap.cpp
// Demonstrates swapping constant pointers 
// for changing argument variables.
#include <iostream>

void bad_swap(int x, int y);
void good_swap(int * const p_x, int * const p_y);

int main(void)
{
	using namespace std;
	int my_score = 150;
	int your_score = 1000;

	cout << "Original values\n";
	cout << "my_score: " << my_score << endl;
	cout << "your_score: " << your_score << endl;

	cout << "\nCalling bad_swap()\n";
	bad_swap(my_score, your_score);
	cout << "my_score: " << my_score << endl;
	cout << "your_score: " << your_score << endl;

	cout << "\nCalling good_swap()\n";
	good_swap(&my_score, &your_score);
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

void good_swap(int * const p_x, int * const p_y)
{
	int temp = *p_x;
	*p_x = *p_y;
	*p_y = temp;
}
