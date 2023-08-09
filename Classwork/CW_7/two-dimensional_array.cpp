// exercise10.cpp
// Doubles the values of a two-dimensional array.
#include <iostream>
#include <iomanip>			// For setw() manipulator
using namespace std;

const int COLS = 5;
const int ROWS = 3;

void init_arr(int ar[][COLS], int rows);
void show_arr(const int (* const ar)[COLS], int rows);
void doubling_arr(int ar[][COLS], int rows);

int main(void)
{
	int array[ROWS][COLS];

	init_arr(array, ROWS);
	cout << "Source values:\n";
	show_arr(array, ROWS);

	doubling_arr(array, ROWS);
	cout << "\nDouble values:\n";
	show_arr(array, ROWS);
	
	return 0;
}

void init_arr(int ar[][COLS], int rows)
{
	// Any initialization of the array. 
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			ar[i][j] = i * i + j * j;
		}
	}
}

void show_arr(const int (* const ar)[COLS], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << setw(4) << ar[i][j] << ' ';
		}
	}
	cout << endl;
}

void doubling_arr(int ar[][COLS], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			ar[i][j] *= 2;
		}
	}
}