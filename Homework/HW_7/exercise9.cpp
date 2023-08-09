// exercise9.cpp
// 
// Working with 2-dimensional array of double 
// as some 1-dimensional arrays, 
// calculates the average value of the all array,
// calculates of the biggest value in the all array.
// 
#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 5;

void input(double ar[][COLS], int rows);
double average(const double ar[], int n);
double average_all(const double ar[][COLS], int rows);
double biggest(const double ar[][COLS], int rows);
void show_results(const double ar[][COLS], int rows);

int main(void)
{
	double array[ROWS][COLS];

	input(array, ROWS);
	show_results(array, ROWS);

	return 0;
}

void input(double ar[][COLS], int rows)
{
	cout << "Enter values for a 2-dimension " << rows << 'x' << COLS << " array:\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cin >> ar[i][j];
		}
	}
}

double average(const double ar[], int n)
{
	double sum = 0.0;

	for (int i = 0; i < n; i++)
	{
		sum += ar[i];
	}

	return sum / n;
}

double average_all(const double ar[][COLS], int rows)
{
	double sum = 0.0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sum += ar[i][j];
		}
	}

	return sum / (COLS * rows);
}

double biggest(const double ar[][COLS], int rows)
{
	double max = ar[0][0];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (max < ar[i][j])
			{
				max = ar[i][j];
			}
		}
	}

	return max;
}

void show_results(const double ar[][COLS], int rows)
{
	cout << "\nAverages:\n";
	for (int i = 0; i < rows; i++)
	{
		cout << "array[" << i << "] (line " << i + 1 << ") = " << average(ar[i], COLS) << endl;
	}	
	
	cout << "\nAverage value for all elements is " << average_all(ar, rows) << endl;
	cout << "\nThe biggest value from all elements is " << biggest(ar, rows) << endl;
}
