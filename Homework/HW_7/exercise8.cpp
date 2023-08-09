// exercise8.cpp
// Working with traditional 1- and 2-dimensional arrays.
#include <iostream>
#include <iomanip>		// For std::setw()
using namespace std;

const int ROWS = 3;
const int SIZE = 5;

void init(int trg[][SIZE], int rows, int src_1[], int src_2[]);
void output(const int trg[][SIZE], int rows);
void output(const int ar[], int n);

int main(void)
{
	int src_1[SIZE] = {0, 1, 2, 3, 4};
	int src_2[SIZE] = {5, 6, 0, 7, 1};
	int trg[ROWS][SIZE];

	// Output of source arrays
	cout << "Source arrays:\n";
	output(src_1, SIZE);
	output(src_2, SIZE);
	cout << endl;

	// Initilization and output of the target array
	cout << "Results:\n";
	init(trg, ROWS, src_1, src_2);
	output(trg, ROWS);

	return 0;
}

void output(const int ar[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << setw(2) << ar[i] << "  ";
	}
	cout << endl;
}

void init(int trg[][SIZE], int rows, int src_1[], int src_2[])
{
	int j;

	// 1st row
	for (j = 0; j < SIZE; j++)
	{
		trg[0][j] = src_1[j] + src_2[j];
	}
	// 2nd row
	for (j = 0; j < SIZE; j++)
	{
		trg[1][j] = src_1[j] - src_2[j];
	}
	// 3rd row
	for (j = 0; j < SIZE; j++)
	{
		trg[2][j] = src_1[j] * src_2[j];
	}
}

void output(const int trg[][SIZE], int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			cout << setw(2) << trg[i][j] << "  ";
		}
		cout << endl;
	}
}
