// exercise2.cpp
// Finding and fixing bugs

#include <iostream>

int main(void)
{
	using namespace std;
	const int ROWS = 2;
	const int COLS = 3;
	char map[ROWS][COLS] = {
		{'0', 'X', '0'},
		{' ', 'X', '0'}
	};

	// Output
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
