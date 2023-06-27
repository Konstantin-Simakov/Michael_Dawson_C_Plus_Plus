// exercise6.cpp
// ch_line() function.
#include <iostream>
using namespace std;

void ch_line(char ch, int i, int j);

int main(void)
{
	cout << "Enter a character: ";
	char ch;
	cin >> ch;

	cout << "Enter 2 integers: ";
	int i, j;
	cin >> i >> j;

	ch_line(ch, i, j);

	return 0;
}

void ch_line(char ch, int i, int j)
{
	const char SPACE = ' ';
	int col = 1;

	while (col < i)
	{
		cout << SPACE;
		col++;;
	}
	while (col <= j)
	{
		cout << ch;
		col++;
	}
	cout << endl;
}
