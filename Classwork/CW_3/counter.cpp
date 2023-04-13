// counter.cpp
// Demonstrates working with 'for' loop
#include <iostream>

int main(void)
{
	using namespace std;
	cout << "Counting forward:\n";
	for (int i = 0; i < 10; ++i)
		cout << i << " ";
	cout << endl;

	cout << "\nCounting backward:\n";
	for (int i = 9; i >= 0; --i)
		cout << i << " ";
	cout << endl;

	cout << "\nCounting by fives:\n";
	for (int i = 0; i <= 50; i += 5)
		cout << i << " ";
	cout << endl;

	cout << "\nCounting without \'initialization\' and "
		 << "\'update\' parts of \'for\' loop:\n";
	int count = 0;
	for ( ; count < 10; )
	{
		cout << count << " ";
		++count;
	}
	cout << endl;

	cout << "\nCounting with double \'for\' loop:\n";
	const int ROWS = 5;
	const int COLUMNS = 3;
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
			cout << i << ", " << j << "    ";
		cout << endl;
	}

	return 0;
}
