// exercise7.cpp
// ch_rows_cols() function.
#include <iostream>
using namespace std;

void ch_rows_cols(char ch, int rows, int cols);

int main(void)
{
	cout << "Enter a character: ";
	char ch;
	cin >> ch;

	cout << "Enter a number of rows: ";
	int rows;
	cin >> rows;
	
	cout << "Enter a number of columns: ";
	int cols;
	cin >> cols;

	ch_rows_cols(ch, rows, cols);

	return 0;
}

void ch_rows_cols(char ch, int rows, int cols)
{
	for (int i = 1; i <= rows; ++i)
	{
		for (int j = 1; j <= cols; ++j)
		{
			cout << ch;
		}
		cout << endl;
	}
	cout << endl;
}
