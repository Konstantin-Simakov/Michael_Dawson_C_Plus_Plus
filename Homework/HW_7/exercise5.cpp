// exercise5.cpp
// 'Golf' game imitation.
#include <iostream>

int data_input(double arr[], int limit);
void display_results(const double arr[], int n);
double calc_average(const double arr[], int n);

int main(void)
{
	using namespace std;
	const int PLAYS = 10;
	double golf[PLAYS];
	
	// The fact number of golf plays is a variable 'fact_plays' below
	cout << "Enter up to " << PLAYS << " golf plays: ";
	int fact_plays = data_input(golf, PLAYS);

	cout << "Your input golf plyas number is " << fact_plays << endl;
	display_results(golf, fact_plays);

	double average = calc_average(golf, fact_plays);
	cout << "The average value of " << fact_plays << " golf plays "
		 << "is " << average << endl;

	return 0;
}

int data_input(double arr[], int limit)
{
	using namespace std;
	int num = 0;
	while (num < limit && cin >> arr[num])
	{
		++num;
	}

	return num;
}

void display_results(const double arr[], int n)
{	
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ": " << arr[i] << endl;
	}
}

double calc_average(const double arr[], int n)
{
	double sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	return sum / n;
}
