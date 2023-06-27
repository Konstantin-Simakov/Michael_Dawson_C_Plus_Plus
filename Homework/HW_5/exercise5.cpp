// exercise5.cpp
// Minimum from 2 values

#include <iostream>

double min(double x, double y);

int main(void)
{
	using namespace std;
	cout << "Enter 2 numbers: ";
	double x, y;
	cin >> x >> y;

	cout << "The minimum from " << x << " and " << y << " is " << min(x, y) << endl;

	return 0;
}

double min(double x, double y)
{
	return x < y ? x : y;
}
